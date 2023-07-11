#ifndef TITLEPAGE_HPP
#define TITLEPAGE_HPP

#define TITLEPAGE_MENU_NUM 2

#include <utility>
#include <string>
#include <array>

#include "TerminalControl.hpp"
#include "BasePage.hpp"

class TitlePage : public BasePage
{
private:
    const static int menu_num = TITLEPAGE_MENU_NUM;
    const std::array<std::string, TITLEPAGE_MENU_NUM> menu_str = {"Login", "Sign up"};
    TerminalControl::Cursor cursor;

    void PrintMenu();
protected:
    virtual void EventEnter() override;

    virtual void EventESC() override;

    virtual void EventArrow() override;

    virtual void EventPageUpDn() override;

    virtual void EventF5() override;

    virtual void EventStr() override;

public:
    TitlePage(ClientManager& obj);

    // 화면 실행

    virtual std::string PageMain() override;

    virtual void RenderPage() override;
};

#endif /* TITLEPAGE_HPP */
