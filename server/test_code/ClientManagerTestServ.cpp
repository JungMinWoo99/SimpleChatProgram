#include <iostream>

#include <boost/asio.hpp>

#include "MsgProtocol.hpp"
#include "MsgSockFunc.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

class ClientManagerTestServ
{
private:
    io_context io_context;
    tcp::socket msg_sock;
    tcp::acceptor acceptor;
    vector<MsgPacket> recv_buf;
    vector<MsgPacket> send_buf;
    vector<UserInfo> user_list;
    vector<Msg> msg_list;

    void RecvMsg(vector<MsgPacket> &buf)
    {
        MsgSockFunc::RecvMsg(buf, msg_sock);
    }

    void SendMsg(vector<MsgPacket> &buf)
    {
        MsgSockFunc::SendMsg(buf, msg_sock);
    }

    void CloseSock()
    {
        msg_sock.close();
    }

    void AnswerLogin(Msg &login_msg)
    {
        Msg answer_msg;
        answer_msg.mtype = LOGIN;
        if (login_msg.id == "error")
            answer_msg.error_code = NOEXID;
        else if (login_msg.passwd == "error")
            answer_msg.error_code = INCRPW;
        else
            answer_msg.error_code = 0;

        send_buf.resize(1);
        answer_msg.TransformToPacket(&send_buf[0]);

        SendMsg(send_buf);
    }

    void AnswerSignUp(Msg &sign_up_msg)
    {
        Msg answer_msg;
        answer_msg.mtype = SIGNUP;
        if (sign_up_msg.id == "error")
            answer_msg.error_code = ALEXID;
        else
            answer_msg.error_code = 0;

        send_buf.resize(1);
        answer_msg.TransformToPacket(&send_buf[0]);

        SendMsg(send_buf);
    }

    void SendUserList()
    {
        send_buf.resize(user_list.size());
        for (int i = 0; i < user_list.size(); i++)
            user_list[i].TransformToPacket(&send_buf[i]);
        SendMsg(send_buf);
    }

    void SendMsgList()
    {
        send_buf.resize(msg_list.size());
        for (int i = 0; i < msg_list.size(); i++)
            msg_list[i].TransformToPacket(&send_buf[i]);
        SendMsg(send_buf);
    }

public:
    ClientManagerTestServ() : io_context(), msg_sock(io_context), acceptor(io_context, tcp::endpoint(tcp::v4(), ECHO_SERV_PORT))
    {
        user_list.resize(30);
        Msg tem;
        tem.id = "oo";
        for (int i = 0; i < user_list.size(); i++)
            tem.TransformToUserInfo(user_list[i]);

        msg_list.resize(20);
        msg_list[0].text_msg = "hello";
        msg_list[0].id = "not user";
        msg_list[1].text_msg = "wow";
        msg_list[2].text_msg = "hello2";
        msg_list[3].text_msg = "wow2";
        msg_list[4].text_msg = "hello";
        msg_list[5].text_msg = "wow";
        msg_list[6].text_msg = "hello2";
        msg_list[7].text_msg = "wow2";
        msg_list[8].text_msg = "hello";
        msg_list[9].text_msg = "wow";
        msg_list[10].text_msg = "hello2";
        msg_list[11].text_msg = "wow2";
        msg_list[12].text_msg = "hello";
        msg_list[12].id = "not user";
        msg_list[13].text_msg = "wow";
        msg_list[13].id = "not user";
        msg_list[14].text_msg = "hello2";
        msg_list[15].text_msg = "wow2";
        msg_list[16].text_msg = "hello";
        msg_list[17].text_msg = "wow";
        msg_list[18].text_msg = "hello2";
        msg_list[19].text_msg = "wow2";
        msg_list[20].text_msg = "hello";
        msg_list[20].id = "not user";
    }

    void RunTestServ()
    {
        while (true)
        {
            cout<<"접속 대기중"<<endl;
            acceptor.accept(msg_sock);
            cout<<"클라이언트 접속"<<endl;
            
            while (true)
            {
                try
                {
                    this->RecvMsg(recv_buf);

                    Msg recv_msg;
                    recv_msg.TransformFromPacket(&recv_buf[0]);

                    int request_type = recv_msg.mtype;
                    switch (request_type)
                    {
                    case LOGIN:
                    {
                        AnswerLogin(recv_msg);
                        break;
                    }
                    case SIGNUP:
                    {
                        AnswerSignUp(recv_msg);
                        break;
                    }
                    case USLSREQ:
                    {
                        SendUserList();
                        break;
                    }
                    case MSLSREQ:
                    {
                        SendMsgList();
                        break;
                    }
                    case USERMSG:
                    {
                        msg_list.push_back(recv_msg);
                        break;
                    }
                    case DISCNET:
                    {
                        CloseSock();
                        break;
                    }
                    default:
                        break;
                    }
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                    CloseSock();
                    break;
                }
            }
        }
    }
};

int main(void)
{
    ClientManagerTestServ test;
    test.RunTestServ();

    return 0;
}