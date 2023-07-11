#include "SignupPage.hpp"

using namespace std;
using namespace TerminalControl;

SignupPage::SignupPage(ClientManager &obj)
    : BasePage(obj),
      cursor(*(new vector<Point>{})),
      name_input_box(make_pair(38, 5), MAX_INFO_LEN),
      id_input_box(make_pair(36, 8), MAX_INFO_LEN),
      passwd_input_box(make_pair(36, 11), MAX_INFO_LEN)
{
    vector<Point> menu_coordinate_list;
    menu_coordinate_list.push_back(make_pair(32, 5));
    menu_coordinate_list.push_back(make_pair(32, 8));
    menu_coordinate_list.push_back(make_pair(32, 11));
    menu_coordinate_list.push_back(make_pair(37, 14));
    cursor = Cursor(menu_coordinate_list);
}

string SignupPage::PageMain()
{
    next_page.clear();
    name_input_box.ClearStr();
    id_input_box.ClearStr();
    passwd_input_box.ClearStr();
    cursor.SetBegin();

    RenderPage();
    KeyboardEvent();

    TerminalIO::ChangeStrColor("white");

    return next_page;
};

void SignupPage::PrintMenu()
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
            name_input_box.DrawInputBox();
        }
        if (i == 1)
        {
            id_input_box.DrawInputBox();
        }
        else if (i == 2)
        {
            passwd_input_box.DrawInputBox();
        }
    }
    TerminalIO::RefreshTerminal();
}

void SignupPage::RenderPage()
{
    TerminalIO::ClearWholeArea();
    PrintMenu();
}

void SignupPage::EventEnter()
{
    ReadKey();
    switch (cursor.CurrentIndex())
    {
    case 0:
    case 1:
    case 2:
        cursor.MoveDown();
        break;
    case 3:
    {
        SignUp();
        break;
    }
    }

    PrintMenu();
}

void SignupPage::EventESC()
{
    ReadKey();
    exit = true;
    next_page = "TitlePage";
}

void SignupPage::EventArrow()
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

void SignupPage::EventPageUpDn()
{
    ReadKey();
}

void SignupPage::EventF5()
{
    ReadKey();
}

void SignupPage::EventStr()
{
    if (cursor.CurrentIndex() == 0)
    {
        name_input_box.ReadStr();
    }
    else if (cursor.CurrentIndex() == 1)
    {
        id_input_box.ReadStr();
    }
    else if (cursor.CurrentIndex() == 2)
    {
        passwd_input_box.ReadStr();
    }
    else if (cursor.CurrentIndex() == 3)
    {
        ReadKey();
    }
}

bool SignupPage::CheckBlank()
{
    if (name_input_box.GetStr().empty() || id_input_box.GetStr().empty() || passwd_input_box.GetStr().empty())
        return true;
    else
        return false;
}

void SignupPage::SignUp()
{
    if (CheckBlank())
    {
        TerminalIO::PrintStr(make_pair(26, 16), "Please fill out all blanks");
        name_input_box.ClearStr();
        id_input_box.ClearStr();
        passwd_input_box.ClearStr();
    }
    else
    {
        Msg sign_up_info;
        sign_up_info.name = name_input_box.GetStr();
        sign_up_info.id = id_input_box.GetStr();
        sign_up_info.passwd = passwd_input_box.GetStr();

        UserInfo sign_up_info_buf;
        sign_up_info.TransformToUserInfo(&sign_up_info_buf);

        bool is_sign_up_success = client_manager.SignUp(sign_up_info_buf);
        if (is_sign_up_success)
            SignUpSuccess();
        else
            PrintErrorMsg();
    }
}

void SignupPage::PrintErrorMsg()
{
    ErrorCode error = client_manager.GetRecentError();
    if (error == ALEXID)
        TerminalIO::PrintStr(make_pair(31, 16), "Already exists ID");
    else
        TerminalIO::PrintStr(make_pair(31, 16), "critical error");
}

void SignupPage::SignUpSuccess()
{
    exit = true;
    next_page = "LoginPage";
}
