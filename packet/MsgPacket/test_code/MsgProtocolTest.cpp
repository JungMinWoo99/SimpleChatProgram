#include "MsgProtocol.hpp"

int main(void)
{
    Msg msg1, msg2;
    MsgPacket tem1, tem2;

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

    msg1.PrintMsgContent();
    msg2.PrintMsgContent();

    Msg recv_msg1, recv_msg2;

    recv_msg1.TransformFromPacket(&tem1);
    recv_msg2.TransformFromPacket(&tem2);


    recv_msg1.PrintMsgContent();
    recv_msg2.PrintMsgContent();

    return 0;
}