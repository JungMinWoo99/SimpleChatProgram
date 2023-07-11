#include "SyncServerSock.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

void SyncServerSock::OpenSock() 
{
    acceptor.accept(msg_sock);
}

void SyncServerSock::RecvMsg(std::vector<MsgPacket> &buf)
{
    MsgSockFunc::RecvMsg(buf, msg_sock);
}

void SyncServerSock::SendMsg(std::vector<MsgPacket> &buf)
{
    MsgSockFunc::SendMsg(buf, msg_sock);
}

void SyncServerSock::CloseSock()
{
    MsgSockFunc::CloseSock(msg_sock);
}

SyncServerSock::SyncServerSock() : io_context(), msg_sock(io_context), acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), ECHO_SERV_PORT))
{
}