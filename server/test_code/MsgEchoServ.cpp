#include <cstring>
#include <iostream>

#include <boost/asio.hpp>

#include "MsgProtocol.hpp"
#include "MsgSockFunc.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

class MsgEchoServ
{
private:
    io_context io_context;
    tcp::socket msg_sock;
    tcp::acceptor acceptor;

    void RecvMsg(vector<MsgPacket> &buf)
    {
        MsgSockFunc::RecvMsg(buf,msg_sock);
    }

    void SendMsg(vector<MsgPacket> &buf)
    {
        MsgSockFunc::SendMsg(buf,msg_sock);
    }

    void CloseSock()
    {
        msg_sock.close();
    }
public:
    MsgEchoServ() : io_context(), msg_sock(io_context), acceptor(io_context, tcp::endpoint(tcp::v4(), ECHO_SERV_PORT))
    {
    }

    void RunTestServ()
    {
        acceptor.accept(msg_sock);

        vector<MsgPacket> recv_buf;
        this->RecvMsg(recv_buf);
        
        cout<<"전달받은 메세지 갯수: "<<recv_buf.size()<<endl;
        for(int i=0; i<recv_buf.size();i++)
        {
            Msg tem;
            tem.TransformFromPacket(&recv_buf[i]);
            tem.PrintMsgContent();
        }

        this->SendMsg(recv_buf);

        boost::system::error_code error;
        int blank;
        auto blank_buf = buffer(&blank, sizeof(int));
        msg_sock.read_some(blank_buf,error);
        if (error == boost::asio::error::eof)
            this->CloseSock();
        else
        {
            cout<<"something wrong"<<endl;
        }
        
    }
};

int main(void)
{
    MsgEchoServ test;
    test.RunTestServ();

    return 0;
}