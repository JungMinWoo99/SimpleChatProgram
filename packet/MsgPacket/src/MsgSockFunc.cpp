#include <iostream>
#include <boost/asio.hpp>

#include "MsgSockFunc.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

void MsgSockFunc::RecvMsg(vector<MsgPacket> &buf, tcp::socket &sock)
{
    boost::system::error_code ignored_error, error;

    int recv_msg_num;
    auto int_buf = buffer(&recv_msg_num, sizeof(int));
    sock.read_some(int_buf, ignored_error);

    write(sock, int_buf, ignored_error);

    buf.resize(recv_msg_num);

    auto recv_buf = buffer(buf, sizeof(MsgPacket) * recv_msg_num);
    sock.read_some(recv_buf, error);

    try
    {
        if (error == boost::asio::error::eof)
            return; // Connection closed cleanly by peer.
        else if (error)
            throw boost::system::system_error(error); // Some other error.
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
        return;
    }
}

void MsgSockFunc::SendMsg(vector<MsgPacket> &buf, tcp::socket &sock)
{
    boost::system::error_code ignored_error, error;

    int send_msg_num = buf.size();
    auto int_buf = buffer(&send_msg_num, sizeof(int));
    write(sock, int_buf, ignored_error);

    sock.read_some(int_buf, ignored_error);

    auto send_buf = buffer(buf, sizeof(MsgPacket) * send_msg_num);
    write(sock, send_buf, error);

    try
    {
        if (error)
            throw boost::system::system_error(error); // Some other error.
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
        return;
    }
}

void MsgSockFunc::CloseSock(tcp::socket &sock)
{
    // 출력 스트림을 끊음 (상대편의 shutdown을 기다리기 위해 shutdown_send 사용)
    sock.shutdown(boost::asio::ip::tcp::socket::shutdown_send);

    // 상대편의 shutdown을 기다림 (상태 확인을 위해 receive 버퍼를 사용)
    char tem;
    auto recv_buf = buffer(&tem, sizeof(char));
    boost::system::error_code ec;
    sock.read_some(recv_buf, ec);

    if (ec == boost::asio::error::eof)
    {
        // 상대편이 shutdown을 수행했음
        std::cout << "상대편이 연결을 종료했습니다." << std::endl;
        sock.close();
    }
    else if (!ec)
    {
        // 오류 없이 데이터를 읽었음
        std::cerr << "오류 없이 데이터를 읽었으나 상대편의 연결 종료를 기다리지 않았습니다." << std::endl;
        sock.close();
    }
    else
    {
        // 오류 처리
        std::cerr << "상대편의 연결 종료를 기다리는 동안 오류가 발생했습니다: " << ec.message() << std::endl;
        sock.close();
    }
}