#ifndef SIGNUPPAGE_HPP
#define SIGNUPPAGE_HPP

#define SIGNUPPAGE_MENU_NUM 4

#include <utility>
#include <string>
#include <array>

#include "BasePage.hpp"

using namespace std;

class SignupPage : public BasePage
{
private:
    const static int menu_num = SIGNUPPAGE_MENU_NUM;
    array<string, SIGNUPPAGE_MENU_NUM> menu_str = {"name", "ID", "PW", "Sign up"};
    TerminalControl::Cursor cursor;
    TerminalControl::InputTextBox name_input_box;
    TerminalControl::InputTextBox id_input_box;
    TerminalControl::InputTextBox passwd_input_box;

    void PrintMenu();

    bool CheckBlank();

    void SignUp();

    void PrintErrorMsg();

    void SignUpSuccess();

protected:
    virtual void EventEnter() override;

    virtual void EventESC() override;

    virtual void EventArrow() override;

    virtual void EventPageUpDn() override;

    virtual void EventF5() override;

    virtual void EventStr() override;

public:
    SignupPage(ClientManager &obj);

    virtual std::string PageMain() override;

    virtual void RenderPage() override;
};

#endif /* SIGNUPPAGE_HPP */
