#include <iostream>

#include "ClientSock.hpp"

int main(void)
{
    ClientSock clnt;
    clnt.ConnectServ("127.0.0.1","54322");

    Msg msg1, msg2;
    MsgPacket tem1,tem2;

    msg1.error_code = 0;
    msg1.id = "123";
    msg1.mtype = 12;
    msg1.name = "minwoo";
    msg1.opp_id = "456";
    msg1.passwd = "qwer";
    msg1.text_msg = "hello";

    msg2.error_code = 1;
    msg2.id = "456";
    msg2.mtype = 12;
    msg2.name = "minwoo2";
    msg2.opp_id = "123";
    msg2.passwd = "qwer";
    msg2.text_msg = "wow";

    msg1.TransformToPacket(&tem1);
    msg2.TransformToPacket(&tem2);

    //에코 서버 테스트
    std::vector<MsgPacket> send_buf;
    send_buf.push_back(tem1);
    send_buf.push_back(tem2);
    clnt.SendMsg(send_buf);

    std::vector<MsgPacket> recv_buf;
    clnt.RecvMsg(recv_buf);
    
    Msg recv_msg1, recv_msg2;
    if (recv_buf.size() > 0)
    {
        recv_msg1.TransformFromPacket(&recv_buf[0]);
        recv_msg2.TransformFromPacket(&recv_buf[1]);
    }
    else
    {
        std::cout<<"error"<<std::endl;
    }

    recv_msg1.PrintMsgContent();
    recv_msg2.PrintMsgContent();

    clnt.CloseSock();
    return 0;
}