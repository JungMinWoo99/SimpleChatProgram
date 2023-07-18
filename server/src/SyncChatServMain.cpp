#include "SyncChatServ.hpp"

int main(void)
{
    boost::asio::io_context io_context;
    SyncChatServAcceptor server(io_context);
    server.StartAccept();
    io_context.run();
    return 0;
}