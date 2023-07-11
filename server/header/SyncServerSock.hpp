#ifndef SYNCSERVERSOCK_HPP
#define SYNCSERVERSOCK_HPP

#include <iostream>
#include <boost/asio.hpp>

#include "MsgSockFunc.hpp"

class SyncServerSock
{
private:
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket msg_sock;
    boost::asio::ip::tcp::acceptor acceptor;

public:
    void OpenSock();

    void RecvMsg(std::vector<MsgPacket> &buf);

    void SendMsg(std::vector<MsgPacket> &buf);

    void CloseSock();

    SyncServerSock();
};

#endif /* SYNCSERVERSOCK_HPP */
