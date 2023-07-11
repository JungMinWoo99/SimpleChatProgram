#include "BasePage.hpp"

using namespace std;
using namespace TerminalControl;

BasePage::BasePage(ClientManager& client_manager, int top_h, int bot_h, int w):client_manager(client_manager)
{
    this->top_area_h = top_h;
    this->bot_area_h = bot_h;
    this->w = w;
}

void BasePage::KeyboardEvent()
{
    while (!exit)
    {
        int key = PeekKey();
        if (KeyChecker::isArrow(key))
        {
            EventArrow();
        }
        else if (KeyChecker::isEnter(key))
        {
            EventEnter();
        }
        else if (KeyChecker::isESC(key))
        {
            EventESC();
        }
        else if (KeyChecker::isAlphanumeric(key) || KeyChecker::isBackspace(key))
        {
            EventStr();
        }
        else if (KeyChecker::isF5(key))
        {
            EventF5();
        }
        else if (KeyChecker::isPageUp(key)||KeyChecker::isPageDown(key))
        {
            EventPageUpDn();
        }
        else
        {
            // 사용하지 않는 키의 입력을 버림
            ReadKey();
        }
    }
    exit = false;
}
