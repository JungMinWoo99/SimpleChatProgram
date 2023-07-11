#ifndef BASEPAGE_HPP
#define BASEPAGE_HPP

#include <string>
#include <vector>

#include "TerminalControl.hpp"
#include "ClientManager.hpp"

class BasePage
{
private:
  int top_area_h;
  int bot_area_h;
  int w;

protected:
  ClientManager& client_manager;
  bool exit = false;
  std::string next_page;

  // 특수키 입력시 이벤트

  virtual void EventEnter() = 0;

  virtual void EventESC() = 0;

  virtual void EventArrow() = 0;

  virtual void EventPageUpDn() = 0;

  virtual void EventF5() = 0;

  virtual void EventStr() = 0;

  virtual void KeyboardEvent() final;

public:

  BasePage(ClientManager& client_manager, int top_h = 18, int bot_h = 6, int w = 80);

  virtual std::string PageMain() = 0;

  virtual void RenderPage() = 0;

};
#endif /* BASEPAGE_HPP */
