#include <iostream>

#include "ClientManager.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

int main(void)
{
    ClientManager client_manager;
    MsgPacket msg_buf;
    UserInfo user_info_buf;

    client_manager.Connect("127.0.0.1","54322");

    Msg sign_up_msg;
    sign_up_msg.id="gamepain";
    sign_up_msg.passwd="123";
    sign_up_msg.name = "minwoo";

    sign_up_msg.TransformToPacket(&msg_buf);
    MsgConverter::MsgPacketToUserInfo(&user_info_buf,&msg_buf);
    if(client_manager.SignUp(user_info_buf))
        cout<<"sign up success"<<endl;
    else
        cout<<"sign up fail"<<endl;
    
    Msg login_msg;
    login_msg.id="gamepain";
    login_msg.passwd="123";
    
    login_msg.TransformToPacket(&msg_buf);
    MsgConverter::MsgPacketToUserInfo(&user_info_buf,&msg_buf);
    if(client_manager.Login(user_info_buf))
        cout<<"login success"<<endl;
    else
        cout<<"login fail"<<endl;
    
    if(client_manager.RequestUserList())
    {
        cout<<"Loading UserList success"<<endl;
        const std::vector<UserInfo>& user_list = client_manager.GetUserList();
        for(int i=0;i<user_list.size();i++)
            cout<<user_list[i].id<<endl;
    }
    else
        cout<<"Loading UserList fail"<<endl;
    
    if(client_manager.RequestMsgList())
    {
        cout<<"Loading MsgList success"<<endl;
        const std::vector<Msg>& msg_list = client_manager.GetMsgList();
        for(int i=0;i<msg_list.size();i++)
            cout<<msg_list[i].text_msg<<endl;
    }
    else
        cout<<"Loading MsgList fail"<<endl;

    client_manager.Disconnect();

    return 0;
}