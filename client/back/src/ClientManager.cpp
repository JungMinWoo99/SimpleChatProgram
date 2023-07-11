#include "ClientManager.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

ClientManager::ClientManager() : client() {}

bool ClientManager::Login(const UserInfo& login_info) 
{
    Msg login_request_msg;
    vector<MsgPacket> buf(1);

    MsgConverter::UserInfoToMsgPacket(&buf[0],&login_info);
    login_request_msg.TransformFromPacket(&buf[0]);
    login_request_msg.mtype=LOGIN;
    login_request_msg.TransformToPacket(&buf[0]);
    
    client.SendMsg(buf);
    client.RecvMsg(buf);

    recent_error = buf[0].error_code;
    if(recent_error==0)
    {
        Msg tem;
        tem.TransformFromPacket(&buf.front());
        tem.TransformToUserInfo(&current_user);
        return true;        
    }
    else
    {
        return false;
    }
}

bool ClientManager::SignUp(const UserInfo& sign_up_info) 
{
    Msg sign_up_request_msg;
    vector<MsgPacket> buf(1);

    MsgConverter::UserInfoToMsgPacket(&buf[0],&sign_up_info);
    sign_up_request_msg.TransformFromPacket(&buf[0]);
    sign_up_request_msg.mtype=SIGNUP;
    sign_up_request_msg.TransformToPacket(&buf[0]);

    client.SendMsg(buf);
    client.RecvMsg(buf);

    recent_error = buf[0].error_code;
    return recent_error==0;
}

bool ClientManager::RequestUserList() 
{
    Msg user_list_request_msg;
    vector<MsgPacket> buf(1);

    user_list_request_msg.mtype=USLSREQ;
    user_list_request_msg.TransformToPacket(&buf[0]);

    client.SendMsg(buf);
    client.RecvMsg(buf);

    recent_error = buf[0].error_code;
    if(recent_error==0)
    {
        user_list.clear();
        user_list.resize(buf.size());
        for(int i=0;i<buf.size();i++)
            MsgConverter::MsgPacketToUserInfo(&user_list[i],&buf[i]);
        
        return true;
    }
    else
    {
        return false;
    }
}

bool ClientManager::RequestMsgList() 
{
    Msg msg_list_request_msg;
    vector<MsgPacket> buf(1);

    msg_list_request_msg.mtype=MSLSREQ;
    msg_list_request_msg.id = current_user.id;
    msg_list_request_msg.opp_id = current_opp_id;
    msg_list_request_msg.TransformToPacket(&buf[0]);

    client.SendMsg(buf);
    client.RecvMsg(buf);

    recent_error = buf[0].error_code;
    if(recent_error==0)
    {
        msg_list.clear();
        msg_list.resize(buf.size());
        for(int i=0;i<buf.size();i++)
            msg_list[i].TransformFromPacket(&buf[i]);

        return true;
    }
    else
    {
        return false;
    }
}

bool ClientManager::SendMsg(const std::string& msg) 
{
    Msg send_msg;
    vector<MsgPacket> buf(1);

    send_msg.mtype=USERMSG;
    send_msg.id=current_user.id;
    send_msg.opp_id=current_opp_id;
    send_msg.text_msg = msg;
    send_msg.TransformToPacket(&buf[0]);

    client.SendMsg(buf);
    
    return RequestMsgList();
}

void ClientManager::Connect(std::string serv_addr, std::string service) 
{
    client.ConnectServ(serv_addr, service);    
}

void ClientManager::Disconnect() 
{
    Msg send_msg;
    vector<MsgPacket> buf(1);

    send_msg.mtype=DISCNET;
    send_msg.TransformToPacket(&buf[0]);

    client.SendMsg(buf);

    client.CloseSock();
}

void ClientManager::SetOppId(std::string opp_id) 
{
    current_opp_id = opp_id;    
}

const std::string& ClientManager::GetOppId() 
{
    return current_opp_id;
}

const UserInfo& ClientManager::GetCurrentUser() 
{
    return current_user;
}

const std::vector<UserInfo>& ClientManager::GetUserList() 
{
    return user_list;
}

const std::vector<Msg>& ClientManager::GetMsgList() 
{
    return msg_list;
}

ErrorCode ClientManager::GetRecentError()
{
    return recent_error;
}
