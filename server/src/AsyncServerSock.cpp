#include "AsyncServerSock.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

AsyncServerSock::AsyncServerSock(boost::asio::io_context &io_context)
    : ServerSock(io_context)
{
}

boost::asio::ip::tcp::socket & AsyncServerSock::Socket()
{
    return msg_sock;
}