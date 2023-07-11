#include "SignupPage.hpp"

int main(void)
{
    TerminalControl::StartTerminal();
    ClientManager obj;
    obj.Connect("127.0.0.1","54322");
    SignupPage test_page(obj);
    test_page.PageMain();
    TerminalControl::EndTerminal();
    return 0;
}