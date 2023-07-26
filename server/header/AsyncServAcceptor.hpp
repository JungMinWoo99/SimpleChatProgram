#ifndef ASYNCSERVACCEPTOR_HPP
#define ASYNCSERVACCEPTOR_HPP

#include "ServerSock.hpp"
#include <boost/bind.hpp>
#include <boost/thread.hpp>

template <typename T>
class AsyncServAcceptor
{
private:
    boost::asio::io_context &io_context;
    boost::asio::ip::tcp::acceptor acceptor;

public:
    AsyncServAcceptor(boost::asio::io_context &io_context) : io_context(io_context), acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), ECHO_SERV_PORT))
    {
    }

    void StartAccept()
    {
        ServerSock *sock = new ServerSock(io_context);

        acceptor.async_accept(sock->Socket(), boost::bind(&AsyncServAcceptor<T>::AcceptHandler, this, sock, boost::asio::placeholders::error));
    }

    void AcceptHandler(ServerSock *sock, const boost::system::error_code &error)
    {
        if (!error)
        {
            std::cout << "클라이언트 연결" << std::endl;
            auto chat_server_run = [](ServerSock *serv_sock)
            {
                T chat_server(*serv_sock);
                delete serv_sock;
            };
            boost::thread chat_thread(chat_server_run, sock);
            chat_thread.detach();
        }
        StartAccept();
    }
};

#endif /* ASYNCSERVACCEPTOR_HPP */
