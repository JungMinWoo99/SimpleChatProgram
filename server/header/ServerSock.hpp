#ifndef SERVERSOCK_HPP
#define SERVERSOCK_HPP

#include <iostream>
#include <boost/asio.hpp>

#include "MsgSockFunc.hpp"

class ServerSock
{
protected:
    boost::asio::ip::tcp::socket msg_sock;

public:
    ServerSock(boost::asio::io_context &io_context);
    
    virtual boost::asio::ip::tcp::socket& Socket() final;

    virtual void RecvMsg(std::vector<MsgPacket> &buf) final;

    virtual void SendMsg(std::vector<MsgPacket> &buf) final;

    virtual void CloseSock() final;
};

#endif /* SERVERSOCK_HPP */
