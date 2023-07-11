#ifndef MSGSOCKFUNC_HPP
#define MSGSOCKFUNC_HPP

#include <cstring>
#include <vector>
#include <boost/asio.hpp>

#include "MsgProtocol.hpp"

namespace MsgSockFunc
{
    void RecvMsg(std::vector<MsgPacket> &buf, boost::asio::ip::tcp::socket& sock);

    void SendMsg(std::vector<MsgPacket> &buf, boost::asio::ip::tcp::socket& sock);

    void CloseSock(boost::asio::ip::tcp::socket& sock);
}
#endif /* MSGSOCKFUNC_HPP */
