#include "TerminalControl.hpp"

TerminalControl::InputTextBox::InputTextBox(Point coordinate, int max_len) : location(coordinate), max_len(max_len) {}

Point TerminalControl::InputTextBox::GetBoxCoordinate() 
{
    return location;
}

std::string TerminalControl::InputTextBox::GetStr() 
{
    return buf;
}

void TerminalControl::InputTextBox::DrawInputBox()
{
    int x=location.first-1;
    int y=location.second-1;
    TerminalIO::DrawFrame(std::make_pair(x,y),max_len + 2, 3);
}

void TerminalControl::InputTextBox::ReadStr()
{
    while (true)
    {
        int peeked_key = TerminalControl::PeekKey();

        if (TerminalControl::KeyChecker::isAlphanumeric(peeked_key))
        {
            TerminalControl::ReadKey();
            if (buf.size() < max_len)
            {
                char ch = TransformReadToANSI();
                buf.push_back(ch);
            }
        }
        else if (TerminalControl::KeyChecker::isBackspace(peeked_key))
        {
            TerminalControl::ReadKey();
            if (!buf.empty())
                buf.pop_back();
        }
        else
        {
            break;
        }

        TerminalControl::TerminalIO::ClearArea(location, max_len, 1);
        TerminalControl::TerminalIO::PrintStr(location, buf);
        TerminalControl::TerminalIO::RefreshTerminal();
    }
}

void TerminalControl::InputTextBox::ClearStr()
{
    buf.clear();
    TerminalControl::TerminalIO::ClearArea(location, max_len, 1);
    TerminalControl::TerminalIO::RefreshTerminal();
}

TerminalControl::Cursor::Cursor(std::vector<Point> &coordinate_arr) : location_arr(coordinate_arr)
{
    location_num = location_arr.size();
}

Point TerminalControl::Cursor::GetCoordinateFromIndex(int idx) 
{
    return location_arr[idx];
}

Point TerminalControl::Cursor::MoveUp()
{
    if (current_idx - 1 > -1)
        current_idx--;
    return location_arr[current_idx];
}

Point TerminalControl::Cursor::MoveDown()
{
    if (current_idx + 1 < location_arr.size())
        current_idx++;
    return location_arr[current_idx];
}

Point TerminalControl::Cursor::CurrentCoordinate()
{
    return location_arr[current_idx];
}

int TerminalControl::Cursor::CurrentIndex()
{
    return current_idx;
}

void TerminalControl::Cursor::SetBegin() {
    current_idx = 0;
}

int TerminalControl::ReadKey()
{
    return terminal_read();
}

int TerminalControl::PeekKey()
{
    while (true)
    {
        if (terminal_has_input() != 0)
            break;
    }
    return terminal_peek();
}

bool TerminalControl::KeyChecker::isArrow(int input)
{
    return isUp(input) || isDown(input) ||
           isRight(input) || isLeft(input);
}

bool TerminalControl::KeyChecker::isUp(int input)
{
    return input == TK_UP;
}

bool TerminalControl::KeyChecker::isDown(int input)
{
    return input == TK_DOWN;
}

bool TerminalControl::KeyChecker::isRight(int input)
{
    return input == TK_RIGHT;
}

bool TerminalControl::KeyChecker::isLeft(int input)
{
    return input == TK_LEFT;
}

bool TerminalControl::KeyChecker::isEnter(int input)
{
    return input == TK_ENTER;
}

bool TerminalControl::KeyChecker::isESC(int input)
{
    return input == TK_ESCAPE;
}

bool TerminalControl::KeyChecker::isF5(int input) 
{
    return input == TK_F5;
}

bool TerminalControl::KeyChecker::isPageUp(int input)
{
    return input == TK_PAGEUP;
}

bool TerminalControl::KeyChecker::isPageDown(int input)
{
    return input == TK_PAGEDOWN;
}

bool TerminalControl::KeyChecker::isAlphanumeric(int input)
{
    return (TK_A <= input && input <= TK_0) || (TK_SPACE <= input && input <= TK_SLASH);
}

bool TerminalControl::KeyChecker::isBackspace(int input)
{
    return input == TK_BACKSPACE;
}

char TerminalControl::TransformReadToANSI()
{
    return terminal_state(TK_CHAR);
}

void TerminalControl::StartTerminal(int w, int h)
{
    terminal_open();
    std::ostringstream oss;
    oss <<"window: size="<<w<<"x"<<h;
    terminal_set(oss.str().c_str());
    TerminalControl::TerminalIO::RefreshTerminal();
}

void TerminalControl::EndTerminal()
{
    terminal_close();
}

void TerminalControl::TerminalIO::RefreshTerminal()
{
    terminal_refresh();
}

void TerminalControl::TerminalIO::PrintStr(Point coordinate, const std::string &str)
{
    int x = coordinate.first;
    int y = coordinate.second;

    terminal_printf(x, y, str.c_str());
}

void TerminalControl::TerminalIO::ChangeStrColor(const std::string &color)
{
    terminal_color(color.c_str());
}

void TerminalControl::TerminalIO::ClearWholeArea() 
{
    terminal_clear();    
}

void TerminalControl::TerminalIO::ClearArea(Point coordinate, int w, int h)
{
    int x = coordinate.first;
    int y = coordinate.second;
    terminal_clear_area(x, y, w, h);
}

void TerminalControl::TerminalIO::DrawFrame(Point coordinate, int w, int h)
{
    int x = coordinate.first;
    int y = coordinate.second;

    for (int i = x; i < x + w; i++)
    {
        terminal_put(i, y, L'─');
        terminal_put(i, y + h - 1, L'─');
    }

    for (int j = y; j < y + h; j++)
    {
        terminal_put(x, j, L'│');
        terminal_put(x + w - 1, j, L'│');
    }

    terminal_put(x, y, L'┌');
    terminal_put(x + w - 1, y, L'┐');
    terminal_put(x, y + h - 1, L'└');
    terminal_put(x + w - 1, y + h - 1, L'┘');
}
