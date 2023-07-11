#include "TitlePage.hpp"
#include "LoginPage.hpp"
#include "SignUpPage.hpp"
#include "MainPage.hpp"
#include "MsgPage.hpp"

int main(void)
{
    TerminalControl::StartTerminal();
    ClientManager obj;
    obj.Connect("127.0.0.1","54322");

    TitlePage title(obj);
    LoginPage login(obj);
    SignupPage sign_up(obj);
    MainPage main(obj);
    MsgPage msg(obj);

    std::string next_page = "TitlePage";
    while(next_page.length()!=0)
    {
        BasePage * page;
        if(next_page.compare("TitlePage")==0)
            page = &title;
        else if(next_page.compare("SignUpPage")==0)
            page = &sign_up;
        else if(next_page.compare("LoginPage")==0)
            page = &login;
        else if(next_page.compare("MainPage")==0)
            page = &main;
        else if(next_page.compare("MsgPage")==0)
            page = &msg;
        next_page = page -> PageMain();
    }

    obj.Disconnect();
    TerminalControl::EndTerminal();
    return 0;
}