#include "MsgProtocol.hpp"

int main(void)
{
    Msg msg1;
    UserInfo user1;
    MsgPacket tem1,tem2;

    msg1.error_code = 0;
    msg1.id = "123";
    msg1.mtype = 12;
    msg1.name = "minwoo";
    msg1.opp_id = "456";
    msg1.passwd = "qwer";
    msg1.text_msg = "hello";


    user1.id = "456";
    user1.name = "minwoo2";
    user1.passwd = "qwer";

    msg1.TransformToPacket(&tem1);
    user1.TransformToPacket(&tem2);

    msg1.PrintMsgContent();
    user1.PrintMsgContent();

    Msg recv_msg1, recv_user1;

    recv_msg1.TransformFromPacket(&tem1);
    recv_user1.TransformFromPacket(&tem2);

    recv_msg1.PrintMsgContent();
    recv_user1.PrintMsgContent();

    return 0;
}