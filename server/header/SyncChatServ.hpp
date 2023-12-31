#ifndef SYNCCHATSERV_HPP
#define SYNCCHATSERV_HPP

#include "ServerSock.hpp"
#include "ServerDBManager.hpp"

class SyncChatServ
{
private:
    ServerSock& server;
    ServerDBManager db;
    std::vector<MsgPacket> recv_buf;
    std::vector<MsgPacket> send_buf;

    int RecvClntRequest();

    void AnswerLogin(Msg &login_msg);

    void AnswerSignUp(Msg &sign_up_msg);

    void SendUserList();

    void SendMsgList(std::string &id, std::string &opp_id);

    void AddMsg(Msg &user_msg);

    void RunServ();

public:
    SyncChatServ(ServerSock& sock);
};

#endif /* SYNCCHATSERV_HPP */
