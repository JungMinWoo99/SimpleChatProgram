#ifndef MSGPAGE_HPP
#define MSGPAGE_HPP

#define MSGPAGE_MENU_NUM 1
#define PRINT_LINE_NUM 16

#include <utility>
#include <string>
#include <array>
#include <vector>

#include "BasePage.hpp"

class MsgPage : public BasePage
{
private:
    const static int menu_num = MSGPAGE_MENU_NUM;
    const static int print_line_num = PRINT_LINE_NUM;
    TerminalControl::InputTextBox msg_input_box;
    std::vector<Msg> msg_list;

    int msg_print_start_line = 0;

    void UpdateMsgList();
    
    void PrintMenu();

    void PrintMsgList();
protected:
    virtual void EventEnter() override;

    virtual void EventESC() override;

    virtual void EventArrow() override;

    virtual void EventPageUpDn() override;

    virtual void EventF5() override;

    virtual void EventStr() override;

public:
    MsgPage(ClientManager& obj);

    virtual std::string PageMain() override;

    virtual void RenderPage() override;

};

#endif /* MSGPAGE_HPP */
