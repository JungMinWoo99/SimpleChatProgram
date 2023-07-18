#include "ServerSock.hpp"

using namespace std;
using namespace boost::asio;

ServerSock::ServerSock(io_context &io_context) : msg_sock(io_context) 
{
}

ip::tcp::socket& ServerSock::Socket()
{
    return msg_sock;
}

void ServerSock::RecvMsg(vector<MsgPacket> &buf)
{
    MsgSockFunc::RecvMsg(buf, msg_sock);
}

void ServerSock::SendMsg(vector<MsgPacket> &buf)
{
    MsgSockFunc::SendMsg(buf, msg_sock);
}

void ServerSock::CloseSock()
{
    MsgSockFunc::CloseSock(msg_sock);
}