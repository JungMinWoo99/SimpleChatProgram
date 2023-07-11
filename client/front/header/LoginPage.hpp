#ifndef LOGINPAGE_HPP
#define LOGINPAGE_HPP

#define LOGINPAGE_MENU_NUM 3

#include <utility>
#include <string>
#include <array>

#include "BasePage.hpp"

using namespace std;

class LoginPage : public BasePage
{
private:
    const static int menu_num = LOGINPAGE_MENU_NUM;
    array<string, LOGINPAGE_MENU_NUM> menu_str = {"ID", "PW", "Login"};
    TerminalControl::Cursor cursor;
    TerminalControl::InputTextBox id_input_box;
    TerminalControl::InputTextBox passwd_input_box;

    void PrintMenu();

    bool CheckBlank();

    void Login();

    void PrintErrorMsg();

    void LoginSuccess();
    
protected:
    virtual void EventEnter() override;

    virtual void EventESC() override;

    virtual void EventArrow() override;

    virtual void EventPageUpDn() override;

    virtual void EventF5() override;

    virtual void EventStr() override;

public:
    LoginPage(ClientManager& obj);

    virtual std::string PageMain() override;

    virtual void RenderPage() override;

};

#endif /* LOGINPAGE_HPP */
