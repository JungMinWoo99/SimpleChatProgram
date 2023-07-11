#include "TitlePage.hpp"
#include <iostream>

int main(void)
{
    TerminalControl::StartTerminal();
    ClientManager obj;
    obj.Connect("127.0.0.1","54322");
    TitlePage test_page(obj);
    std::cout<<test_page.PageMain();
    TerminalControl::EndTerminal();
    return 0;
}