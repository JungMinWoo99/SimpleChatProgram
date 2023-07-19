#include "LoginPage.hpp"

using namespace std;
using namespace TerminalControl;

LoginPage::LoginPage(ClientManager &obj)
    : BasePage(obj),
      cursor(*(new vector<Point>{})),
      id_input_box(make_pair(36, 5), MAX_INFO_LEN),
      passwd_input_box(make_pair(36, 8), MAX_INFO_LEN)
{
    vector<Point> menu_coordinate_list;
    menu_coordinate_list.push_back(make_pair(32, 5));
    menu_coordinate_list.push_back(make_pair(32, 8));
    menu_coordinate_list.push_back(make_pair(38, 11));
    cursor = Cursor(menu_coordinate_list);
}

std::string LoginPage::PageMain()
{
    next_page.clear();
    id_input_box.ClearStr();
    passwd_input_box.ClearStr();
    cursor.SetBegin();

    RenderPage();
    KeyboardEvent();

    TerminalIO::ChangeStrColor("white");
    return next_page;
};

void LoginPage::PrintMenu()
{
    for (int i = 0; i < menu_num; i++)
    {
        bool selected = i == cursor.CurrentIndex();
        string selected_color = selected ? "orange" : "light gray";
        TerminalIO::ChangeStrColor(selected_color);
        TerminalIO::ClearArea(cursor.GetCoordinateFromIndex(i), menu_str[i].size(), 1);
        TerminalIO::PrintStr(cursor.GetCoordinateFromIndex(i), menu_str[i]);

        if (i == 0)
        {
            id_input_box.DrawInputBox();
        }
        else if (i == 1)
        {
            passwd_input_box.DrawInputBox();
        }
    }
    TerminalIO::RefreshTerminal();
}

void LoginPage::RenderPage()
{
    TerminalIO::ClearWholeArea();
    PrintMenu();
}

void LoginPage::EventEnter()
{
    ReadKey();
    switch (cursor.CurrentIndex())
    {
    case 0:
    case 1:
        cursor.MoveDown();
        break;
    case 2:
    {
        Login();
        break;
    }
    }
    PrintMenu();
}

void LoginPage::EventESC()
{
    ReadKey();
    exit = true;
    next_page = "TitlePage";
}

void LoginPage::EventArrow()
{
    int read_key = ReadKey();
    if (KeyChecker::isUp(read_key))
    {
        cursor.MoveUp();
    }
    else if (KeyChecker::isDown(read_key))
    {
        cursor.MoveDown();
    }
    PrintMenu();
}

void LoginPage::EventPageUpDn()
{
    ReadKey();
}

void LoginPage::EventF5()
{
    ReadKey();
}

void LoginPage::EventStr()
{
    if (cursor.CurrentIndex() == 0)
    {
        id_input_box.ReadStr();
    }
    else if (cursor.CurrentIndex() == 1)
    {
        passwd_input_box.ReadStr();
    }
    else if (cursor.CurrentIndex() == 2)
    {
        ReadKey();
    }
}

bool LoginPage::CheckBlank()
{
    if (id_input_box.GetStr().empty() || passwd_input_box.GetStr().empty())
        return true;
    else
        return false;
}

void LoginPage::Login()
{
    if (CheckBlank())
    {
        TerminalIO::PrintStr(make_pair(26, 16), "Please fill out all blanks");
        id_input_box.ClearStr();
        passwd_input_box.ClearStr();
    }
    else
    {
        Msg login_info;
        login_info.id = id_input_box.GetStr();
        login_info.passwd = passwd_input_box.GetStr();

        UserInfo login_info_buf;
        login_info.TransformToUserInfo(login_info_buf);

        bool is_login_success = client_manager.Login(login_info_buf);
        if (is_login_success)
            LoginSuccess();
        else
            PrintErrorMsg();
    }
}

void LoginPage::PrintErrorMsg()
{
    ErrorCode error = client_manager.GetRecentError();
    if (error == INCRPW)
        TerminalIO::PrintStr(make_pair(30, 16), "Incorrect Password");
    else if (error == NOEXID)
        TerminalIO::PrintStr(make_pair(31, 16), "ID doesn't exist");
    else
        TerminalIO::PrintStr(make_pair(30, 16), "critical error");
}

void LoginPage::LoginSuccess()
{
    exit = true;
    next_page = "MainPage";
}