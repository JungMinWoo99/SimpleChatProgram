#include "TerminalControl.hpp"

#define TEST_CASE 3
int main(void)
{
    TerminalControl::StartTerminal();

    if (TEST_CASE == 1) // InputTextBox test
    {
        Point coordinate(1, 2);
        TerminalControl::InputTextBox input_box(coordinate, 20);

        while (true)
        {
            input_box.ReadStr();
            if (TerminalControl::KeyChecker::isESC(TerminalControl::PeekKey()))
            {
                TerminalControl::ReadKey();
                break;
            }
            else if (TerminalControl::KeyChecker::isArrow(TerminalControl::PeekKey()))
            {
                TerminalControl::ReadKey();
                input_box.ClearStr();
            }
        }
    }
    else if (TEST_CASE == 2)
    {
        std::vector<Point> location_arr;
        for (int i = 0; i < 10; i++)
        {
            location_arr.push_back(std::make_pair(1, i));
        }

        TerminalControl::Cursor cursor(location_arr);
        while (true)
        {
            int read_key = TerminalControl::ReadKey();
            if (TerminalControl::KeyChecker::isArrow(read_key))
            {
                std::string pointer = ">";
                if (TerminalControl::KeyChecker::isUp(read_key))
                {
                    TerminalControl::TerminalIO::ClearArea(cursor.CurrentCoordinate(), 1, 1);
                    cursor.MoveUp();
                    TerminalControl::TerminalIO::PrintStr(cursor.CurrentCoordinate(), pointer);
                }
                else if (TerminalControl::KeyChecker::isDown(read_key))
                {
                    TerminalControl::TerminalIO::ClearArea(cursor.CurrentCoordinate(), 1, 1);
                    cursor.MoveDown();
                    TerminalControl::TerminalIO::PrintStr(cursor.CurrentCoordinate(), pointer);
                }
            }
            else if (TerminalControl::KeyChecker::isESC(read_key))
            {
                break;
            }
            TerminalControl::TerminalIO::RefreshTerminal();
        }
    }
    else if (TEST_CASE == 3)
    {
        TerminalControl::TerminalIO::DrawFrame(std::make_pair(0,0),3,4);
        TerminalControl::TerminalIO::RefreshTerminal();
        while(true)
        {
            int read_key = TerminalControl::ReadKey();
            if (TerminalControl::KeyChecker::isESC(read_key))
            {
                break;
            }
            TerminalControl::TerminalIO::RefreshTerminal();
        }
    }
    TerminalControl::EndTerminal();
    return 0;
}