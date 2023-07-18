#ifndef ASYNCSERVERSOCK_HPP
#define ASYNCSERVERSOCK_HPP

#include "ServerSock.hpp"
#include <iostream>
#include <boost/asio.hpp>

class AsyncServerSock : public ServerSock
{
private:
    friend class AcceptSock;

    boost::asio::ip::tcp::socket & Socket();
public:
    AsyncServerSock(boost::asio::io_context &io_context);
};

class AcceptSock
{
private:
    boost::asio::io_context &io_context_;
    
    boost::asio::ip::tcp::acceptor accept_sock;

public:
    
};

#endif /* ASYNCSERVERSOCK_HPP */
