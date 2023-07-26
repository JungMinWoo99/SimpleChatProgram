#include "SyncChatServ.hpp"
#include "AsyncServAcceptor.hpp"

int main(void)
{
    boost::asio::io_context io_context;
    AsyncServAcceptor<SyncChatServ> server(io_context);
    server.StartAccept();
    io_context.run();
    return 0;
}