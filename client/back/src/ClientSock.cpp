#include <iostream>

#include "ClientSock.hpp"
#include "MsgSockFunc.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

ClientSock::ClientSock() : io_context(), clnt_socket(io_context)
{
}

void ClientSock::ConnectServ(string serv_addr, string service)
{
    tcp::resolver resolver(io_context);
    serv_endpoints = resolver.resolve(serv_addr, service);
    connect(clnt_socket, serv_endpoints);
}

void ClientSock::RecvMsg(vector<MsgPacket> &buf)
{
    MsgSockFunc::RecvMsg(buf,clnt_socket);
}

void ClientSock::SendMsg(vector<MsgPacket> &buf)
{
    MsgSockFunc::SendMsg(buf,clnt_socket);
}

void ClientSock::CloseSock()
{
    MsgSockFunc::CloseSock(clnt_socket);
}