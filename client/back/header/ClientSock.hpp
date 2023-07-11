#ifndef CLIENTAPI_HPP
#define CLIENTAPI_HPP

#include <boost/asio.hpp>
#include <string>
#include <vector>

#include "MsgProtocol.hpp"

class ClientSock
{
private:
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket clnt_socket;

    boost::asio::ip::tcp::resolver::results_type serv_endpoints;
public:
    ClientSock();

    void ConnectServ(std::string serv_addr, std::string service);

    void RecvMsg(std::vector<MsgPacket>& buf);

    void SendMsg(std::vector<MsgPacket>& buf);

    void CloseSock();
};



#endif /* CLIENTAPI_HPP */
