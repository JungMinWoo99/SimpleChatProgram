#include "MainPage.hpp"

using namespace std;
using namespace TerminalControl;

MainPage::MainPage(ClientManager &obj)
    : BasePage(obj),
      cursor(*(new vector<Point>{})),
      id_input_box(make_pair(17, 0), MAX_INFO_LEN)
{
    vector<Point> menu_coordinate_list;
    menu_coordinate_list.push_back(make_pair(17, 0));
    for (int i = 0; i < user_list_size; i++)
        menu_coordinate_list.push_back(make_pair(0, i + 4));
    cursor = Cursor(menu_coordinate_list);
}

std::string MainPage::PageMain()
{
    cursor.SetBegin();
    
    RenderPage();

    UpdateUserList();

    PrintUserList();

    KeyboardEvent();

    TerminalIO::ChangeStrColor("white");


    return next_page;
}

void MainPage::RenderPage()
{
    TerminalIO::ClearWholeArea();

    TerminalIO::PrintStr(make_pair(2, 0), "Input user ID: ");
    TerminalIO::PrintStr(make_pair(2, 1), ">> ");
    TerminalIO::PrintStr(make_pair(0, 2), "======================================================="
                                          "=========================");

    TerminalIO::PrintStr(make_pair(0, 16), "ID: ");
    TerminalIO::PrintStr(make_pair(4, 16), client_manager.GetCurrentUser().id);
    TerminalIO::PrintStr(make_pair(0, 17), "Name: ");
    TerminalIO::PrintStr(make_pair(6, 17), client_manager.GetCurrentUser().name);
}

void MainPage::PrintMenu()
{
    for (int i = 1; i < menu_num; i++)
        TerminalIO::ClearArea(cursor.GetCoordinateFromIndex(i), 1, 1);

    if (cursor.CurrentIndex() != 0)
        TerminalIO::PrintStr(cursor.CurrentCoordinate(), ">");

    if (logout_toggle)
        TerminalIO::ChangeStrColor(string("orange"));
    TerminalIO::PrintStr(make_pair(74, 16), "Logout");
    TerminalIO::ChangeStrColor(string("white"));

    TerminalIO::RefreshTerminal();
}

void MainPage::EventEnter()
{
    ReadKey();
    EnterMsgRoom();
    TerminalIO::RefreshTerminal();
}

void MainPage::EventESC()
{
    ReadKey();

    logout_toggle = true;
    PrintMenu();

    while (true)
    {
        int key = ReadKey();
        if (KeyChecker::isEnter(key))
        {
            exit = true;
            next_page = "TitlePage";
            break;
        }
        else if (KeyChecker::isESC(key))
        {
            logout_toggle = false;
            PrintMenu();
            break;
        }
    }
    return;
}

void MainPage::EventArrow()
{
    int read_key = ReadKey();

    if (KeyChecker::isUp(read_key))
        cursor.MoveUp();
    else if (KeyChecker::isDown(read_key))
    {
        if (current_page != list_page_num || (cursor.CurrentIndex() - 1) != last_page_size - 1)
            cursor.MoveDown();
    }

    PrintMenu();

    return;
}

void MainPage::EventPageUpDn()
{
    int read_key = ReadKey();
    if (KeyChecker::isPageUp(read_key))
    {
        if (current_page != 1)
        {
            current_page--;
            PrintUserList();
        }
    }
    else if (KeyChecker::isPageDown(read_key))
    {
        if (current_page != list_page_num)
        {
            current_page++;
            PrintUserList();
        }
    }
}

void MainPage::EventF5()
{
    ReadKey();

    UpdateUserList();
    PrintUserList();
}

void MainPage::EventStr()
{
    if (cursor.CurrentIndex() != 0)
    {
        ReadKey();
    }

    if (cursor.CurrentIndex() == 0)
    {
        id_input_box.ReadStr();
    }
}

void MainPage::EnterMsgRoom()
{
    if (cursor.CurrentIndex() != 0)
    {
        int idx = user_list_size * (current_page - 1) + cursor.CurrentIndex() - 1;
        client_manager.SetOppId(user_list[idx].id);
    }
    else
        client_manager.SetOppId(id_input_box.GetStr());

    bool is_enter_room_success = client_manager.RequestMsgList();
    if (is_enter_room_success)
        EnterMsgRoomSucces();
    else
        PrintErrorMsg();
}

void MainPage::PrintErrorMsg()
{
    ErrorCode error = client_manager.GetRecentError();

    if (error == YOURID)
        TerminalIO::PrintStr(make_pair(5, 1), "Can't input your ID");
    else if (error == NOEXID)
        TerminalIO::PrintStr(make_pair(5, 1), "ID doesn't exist");
    else
        TerminalIO::PrintStr(make_pair(5, 1), "critical error");
}

void MainPage::UpdateUserList()
{
    client_manager.RequestUserList();

    user_list = client_manager.GetUserList();

    current_page = 1;

    list_page_num = user_list.size() / user_list_size + 1;

    last_page_size = user_list.size() % user_list_size;
    if (last_page_size == 0)
        last_page_size = user_list_size;
}

void MainPage::PrintUserList()
{
    TerminalIO::ClearArea(make_pair(2, 4), 78, user_list_size);

    char list_title[31];
    sprintf(list_title, "User List (%d / %d)", current_page, list_page_num);
    TerminalIO::PrintStr(make_pair(0, 3), list_title);

    int printed_user_num = (current_page == list_page_num ? last_page_size : user_list_size);
    for (int i = 0; i < printed_user_num; i++)
    {
        int idx = user_list_size * (current_page - 1) + i;

        TerminalIO::PrintStr(make_pair(2, i + 4), user_list[idx].id);
    }

    while (cursor.CurrentIndex() > 1)
        cursor.MoveUp();

    PrintMenu();
}

void MainPage::EnterMsgRoomSucces()
{
    exit = true;
    next_page = "MsgPage";
}
