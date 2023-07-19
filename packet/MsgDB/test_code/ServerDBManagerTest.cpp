#include "ServerDBManager.hpp"
#include <iostream>
#include <boost/format.hpp>

using namespace std;
using boost::format;

int main(void)
{
    ServerDBManager db_manager("./test.db");

    UserInfo send_buf;
    UserInfo recv_buf;
    Msg test_msg;

    // 유저 추가 테스트
    for (int i = 0; i < 50; i++)
    {
        test_msg.name = (format("minwoo%1%") % i).str();
        test_msg.id = (format("qwer%1%") % i).str();
        test_msg.passwd = (format("123%1%") % i).str();
        test_msg.TransformToUserInfo(send_buf);
        if (!db_manager.AddUserInfo(send_buf))
        {
            cout << "유저 추가 테스트 실패" << endl;
            return -1;
        }
    }

    //유저 목록 조회 테스트
    vector<UserInfo> user_list;
    db_manager.GetUserList(user_list);
    for(int i =0; i < user_list.size();i++)
    {
        cout<<user_list[i].id<<endl;
    }

    // 유저 검색 테스트
    for (int i = 49; i > -1; i--)
    {
        if (db_manager.GetUserInfo((format("qwer%1%") % i).str(), recv_buf))
        {
            cout << i << "번째 유저: " << recv_buf.id << '|' << recv_buf.name << '|' << recv_buf.passwd << endl;
        }
        else
        {
            cout << "유저 검색 테스트 실패" << endl;
            return -1;
        }
    }

    // 메세지 추가 테스트
    for (int i = 0; i < 50; i++)
    {
        int rand_num1 = (i * 13) % 50;
        int rand_num2 = (i * 7) % 50;

        test_msg.id = (format("minwoo%1%") % rand_num1).str();
        test_msg.opp_id = (format("minwoo%1%") % rand_num2).str();
        test_msg.text_msg = (format("%1%%2%") % rand_num1 % rand_num2).str();

        if (!db_manager.AddMsg(test_msg))
        {
            cout << "메세지 추가 테스트 실패" << endl;
            return -1;
        }
    }

    // 메세지 조회 테스트
    vector<Msg> buf;
    if (db_manager.GetMsgList("minwoo13", "minwoo7", buf))
    {
        for (int i = 0;i<buf.size();i++)
            buf[i].PrintMsgContent();
    }
    else
    {
        cout << "메세지 조회 테스트 실패" << endl;
        return -1;
    }
    return 0;
}