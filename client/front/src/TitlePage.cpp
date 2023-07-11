#include "TitlePage.hpp"

using namespace std;
using namespace TerminalControl;

TitlePage::TitlePage(ClientManager& obj) : BasePage(obj), cursor(*(new vector<Point>{})) 
{
    vector<Point> menu_coordinate_list;
    menu_coordinate_list.push_back(make_pair(38, 5));
    menu_coordinate_list.push_back(make_pair(37, 8));
    cursor = Cursor(menu_coordinate_list);
}

string TitlePage::PageMain()
{
    next_page.clear();
    cursor.SetBegin();

    RenderPage();
    KeyboardEvent();

    TerminalIO::ChangeStrColor("white");
    return next_page;
}

void TitlePage::PrintMenu()
{
    for (int i = 0; i < menu_num; i++)
    {
        bool selected = i == cursor.CurrentIndex();
        string selected_color = selected ? "orange" : "light gray";
        TerminalIO::ChangeStrColor(selected_color);
        TerminalIO::ClearArea(cursor.GetCoordinateFromIndex(i), menu_str[i].size(), 1);
        TerminalIO::PrintStr(cursor.GetCoordinateFromIndex(i), menu_str[i]);
    }
    TerminalIO::RefreshTerminal();
}

void TitlePage::RenderPage()
{
    TerminalIO::ClearWholeArea();

    PrintMenu();
}

void TitlePage::EventEnter()
{
    ReadKey();

    exit = true;
    if (cursor.CurrentIndex() == 0)
        next_page = "LoginPage";
    else if (cursor.CurrentIndex() == 1)
        next_page = "SignUpPage";
}

void TitlePage::EventESC()
{
    ReadKey();

    exit = true;
    next_page.clear();
}

void TitlePage::EventArrow()
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

void TitlePage::EventPageUpDn()
{
    ReadKey();
    return;
}

void TitlePage::EventF5()
{
    ReadKey();
    return;
}

void TitlePage::EventStr()
{
    ReadKey();
    return;
}