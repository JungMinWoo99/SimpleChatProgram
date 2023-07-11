#ifndef MAINPAGE_HPP
#define MAINPAGE_HPP

#define MAINPAGE_MENU_NUM 13

#include <utility>
#include <string>
#include <array>
#include <vector>

#include "BasePage.hpp"

using namespace std;

class MainPage : public BasePage
{
private:
    const static int menu_num = MAINPAGE_MENU_NUM;
    const static int user_list_size = MAINPAGE_MENU_NUM-1;
    TerminalControl::Cursor cursor;
    TerminalControl::InputTextBox id_input_box;
    bool logout_toggle = false;

    UserInfo current_user;

    vector<UserInfo> user_list;

    
    int current_page = 1;
    int list_page_num = 1;
    int last_page_size = 0;

    void PrintMenu();

    void PrintUserList();

    void EnterMsgRoom();

    void EnterMsgRoomSucces();

    void PrintErrorMsg();

    void UpdateUserList();

protected:
    virtual void EventEnter() override;

    virtual void EventESC() override;

    virtual void EventArrow() override;

    virtual void EventPageUpDn() override;

    virtual void EventF5() override;

    virtual void EventStr() override;

public:
    MainPage(ClientManager& obj);

    virtual std::string PageMain() override;

    virtual void RenderPage() override;

};

#endif /* MAINPAGE_HPP */
