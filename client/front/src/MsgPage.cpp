#include <utility>
#include <string>
#include <array>
#include <vector>

#include "MsgPage.hpp"

using namespace std;
using namespace TerminalControl;

MsgPage::MsgPage(ClientManager &obj)
    : BasePage(obj),
      msg_input_box(make_pair(15, 17), MAX_INFO_LEN)
{
}

string MsgPage::PageMain()
{
    TerminalIO::ClearWholeArea();

    msg_print_start_line = 0;

    UpdateMsgList();

    RenderPage();

    PrintMenu();

    KeyboardEvent();

    return next_page;
}

void MsgPage::RenderPage()
{
    TerminalIO::ClearWholeArea();
    
    TerminalIO::PrintStr(make_pair(0, 16), "Message with ");
    TerminalIO::PrintStr(make_pair(14, 16), client_manager.GetOppId());
    TerminalIO::PrintStr(make_pair(0, 17), "Input message: ");

    TerminalIO::RefreshTerminal();
}

void MsgPage::PrintMenu()
{
    PrintMsgList();
    TerminalIO::RefreshTerminal();
}

void MsgPage::EventEnter()
{
    ReadKey();
    if (!msg_input_box.GetStr().empty())
    {
        client_manager.SendMsg(msg_input_box.GetStr());
        msg_input_box.ClearStr();
        UpdateMsgList();
        PrintMsgList();
        TerminalIO::RefreshTerminal();
    }
}

void MsgPage::EventESC()
{
    ReadKey();
    exit = true;
    next_page = "MainPage";
}

void MsgPage::EventArrow()
{
    ReadKey();
}

void MsgPage::EventPageUpDn()
{
    int read_key = ReadKey();
    if (KeyChecker::isPageUp(read_key))
    {
        if (msg_print_start_line != 0)
            msg_print_start_line--;
    }
    else if (KeyChecker::isPageDown(read_key))
    {
        if (msg_print_start_line != msg_list.size() - 1)
            msg_print_start_line++;
    }
    PrintMenu();
}

void MsgPage::EventF5()
{
    ReadKey();
    UpdateMsgList();
    PrintMenu();
}

void MsgPage::EventStr()
{
    msg_input_box.ReadStr();
}

void MsgPage::PrintMsgList()
{
    /**
     * @brief
     * 터미널의 폭과 너비의 상수화 작업이 필요
     */

    TerminalIO::ClearArea(make_pair(0, 0), 80, 16);

    for (int i = 0; i < print_line_num && (i + msg_print_start_line) < msg_list.size(); i++)
    {
        Msg CurrentUserInfo;
        CurrentUserInfo.TransformFromUserInfo(&client_manager.GetCurrentUser());
        if (msg_list[i + msg_print_start_line].id == CurrentUserInfo.id)
            TerminalIO::PrintStr(make_pair(80 - msg_list[i + msg_print_start_line].text_msg.length(), i), msg_list[i + msg_print_start_line].text_msg);
        else
            TerminalIO::PrintStr(make_pair(0, i), msg_list[i + msg_print_start_line].text_msg);
    }
}

void MsgPage::UpdateMsgList()
{
    client_manager.RequestMsgList();
    msg_list = client_manager.GetMsgList();
}
