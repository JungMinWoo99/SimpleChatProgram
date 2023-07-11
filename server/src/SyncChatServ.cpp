#include "SyncChatServ.hpp"

using namespace std;

int SyncChatServ::RecvClntRequest() 
{
    server.RecvMsg(recv_buf);
    return recv_buf[0].mtype;
}

void SyncChatServ::AnswerLogin(Msg &login_msg)
{
    Msg answer_msg;
    answer_msg.mtype = LOGIN;

    UserInfo user_info_buf;
    bool is_login_success = db.GetUserInfo(login_msg.id, user_info_buf);
    answer_msg.TransformFromUserInfo(&user_info_buf);

    if(is_login_success)
    {
        if(answer_msg.id.empty())
            answer_msg.error_code = NOEXID;
        else if(answer_msg.passwd!=login_msg.passwd)
            answer_msg.error_code = INCRPW;
        else
            answer_msg.error_code = 0;
    }
    else
    {
        answer_msg.error_code = UNEXPT;
    }

    send_buf.resize(1);
    answer_msg.TransformToPacket(&send_buf[0]);

    server.SendMsg(send_buf);
}

void SyncChatServ::AnswerSignUp(Msg &sign_up_msg)
{
    Msg answer_msg;
    answer_msg.mtype = SIGNUP;

    UserInfo user_info_buf;
    sign_up_msg.TransformToUserInfo(&user_info_buf);
    bool is_sign_up_success = db.AddUserInfo(user_info_buf);

    if(is_sign_up_success)
        answer_msg.error_code = 0;
    else if(db.IsConstraintViolation())
        answer_msg.error_code = ALEXID;
    else
        answer_msg.error_code = UNEXPT;

    send_buf.resize(1);
    answer_msg.TransformToPacket(&send_buf[0]);

    server.SendMsg(send_buf);
}

void SyncChatServ::SendUserList()
{
    std::vector<UserInfo> user_list;

    db.GetUserList(user_list);

    send_buf.resize(user_list.size());
    for (int i = 0; i < user_list.size(); i++)
        MsgConverter::UserInfoToMsgPacket(&send_buf[i], &user_list[i]);
    server.SendMsg(send_buf);
}

void SyncChatServ::SendMsgList(string& id, string& opp_id)
{
    std::vector<Msg> msg_list;
    UserInfo opp_info;
    db.GetUserInfo(opp_id,opp_info);
    Msg opp_info_msg;
    opp_info_msg.TransformFromUserInfo(&opp_info);

    if (id == opp_id)
    {
        send_buf.resize(1);
        send_buf.front().error_code = YOURID;
    }
    else if(opp_info_msg.id=="")
    {
        send_buf.resize(1);
        send_buf.front().error_code = NOEXID;
    }
    else if (db.GetMsgList(id, opp_id, msg_list))
    {
        send_buf.resize(msg_list.size());
        for (int i = 0; i < msg_list.size(); i++)
            msg_list[i].TransformToPacket(&send_buf[i]);
    }
    else
    {
        send_buf.resize(1);
        send_buf.front().error_code = UNEXPT;
    }

    server.SendMsg(send_buf);
}

void SyncChatServ::AddMsg(Msg& user_msg) 
{
    db.AddMsg(user_msg);
}

SyncChatServ::SyncChatServ() : server(), db("./SyncServerDB.db")
{
}

void SyncChatServ::RunTestServ()
{
    while (true)
    {
        cout << "접속 대기중" << endl;

        server.OpenSock();

        cout << "클라이언트 접속" << endl;

        bool client_end = false;

        while (!client_end)
        {
            try
            {
                int request_type = RecvClntRequest();

                Msg recv_msg;
                recv_msg.TransformFromPacket(&recv_buf[0]);

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
                    SendMsgList(recv_msg.id,recv_msg.opp_id);
                    break;
                }
                case USERMSG:
                {
                    AddMsg(recv_msg);
                    break;
                }
                case DISCNET:
                {
                    client_end = true;
                    server.CloseSock();
                    break;
                }
                default:
                    break;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                server.CloseSock();
                break;
            }
        }
    }
}