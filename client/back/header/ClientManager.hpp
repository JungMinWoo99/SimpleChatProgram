#ifndef CLIENTMANAGER_HPP
#define CLIENTMANAGER_HPP

#include <vector>
#include <string>

#include "ClientSock.hpp"
#include "MsgProtocol.hpp"

class ClientManager
{
private:
    ClientSock client;
    UserInfo current_user;
    std::vector<UserInfo> user_list;
    std::vector<Msg> msg_list;
    std::string current_opp_id;
    ErrorCode recent_error;

public:
    ClientManager();

    bool Login(const UserInfo& login_info);

    bool SignUp(const UserInfo& login_info);

    bool RequestUserList();

    bool RequestMsgList();

    bool SendMsg(const std::string& msg);
    
    void Connect(std::string serv_addr, std::string service);

    void Disconnect();

    void SetOppId(std::string opp_id);

    const std::string& GetOppId();

    const UserInfo& GetCurrentUser();

    const std::vector<UserInfo>& GetUserList();

    const std::vector<Msg>& GetMsgList();

    ErrorCode GetRecentError();
};

#endif /* CLIENTMANAGER_HPP */
