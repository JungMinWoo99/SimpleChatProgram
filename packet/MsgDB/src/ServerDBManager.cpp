#include "ServerDBManager.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <boost/format.hpp>
#include <chrono>
#include <iomanip>

using namespace std;
using boost::format;

typedef int (*CallBackFunc)(void *, int, char **, char **);

ServerDBManager::ServerDBManager(const string &db_dir)
{
    db_error_code = sqlite3_open(db_dir.c_str(), &db);
    if (db_error_code)
    {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        exit(-1);
    }
    sqlite3_exec(db,"PRAGMA foreign_keys = 1;",nullptr,nullptr,nullptr);
}

bool ServerDBManager::AddUserInfo(const UserInfo &user_info)
{
    format add_user_query("INSERT INTO PersonalInfo values ('%s', '%s', '%s')");
    add_user_query % user_info.name % user_info.id % user_info.passwd;
    add_user_query.str();
    db_error_code = sqlite3_exec(db, add_user_query.str().c_str(), nullptr, nullptr, &db_error_msg);
    if (db_error_code != SQLITE_OK)
    {
        cout << db_error_msg << endl;
        sqlite3_free(db_error_msg);

        return false;
    }
    else if (user_info.id.empty())
    {
        cout << "duplicate id" << endl;
        return false;
    }
    return true;
}

bool ServerDBManager::GetUserInfo(const std::string &user_id, UserInfo &buf)
{
    CallBackFunc call_back = [](void *buf, int attr_num, char **tuple, char **attr)
    {
        UserInfo *user_info_buf = (UserInfo *)buf;
        user_info_buf->name = tuple[0];
        user_info_buf->id = tuple[1];
        user_info_buf->passwd = tuple[2];
        return 0;
    };
    
    format login_check_query("SELECT name, id, passwd "
                             "FROM PersonalInfo "
                             "where id = '%s';");
    login_check_query % user_id;
    db_error_code = sqlite3_exec(db, login_check_query.str().c_str(), call_back, &buf, &db_error_msg);
    if (db_error_code != SQLITE_OK)
    {
        cout << db_error_msg << endl;
        sqlite3_free(db_error_msg);
        return false;
    }
    return true;
}

bool ServerDBManager::AddMsg(const Msg &msg)
{
    // 현재 시간 얻기
    auto now = std::chrono::system_clock::now();

    // 타임스탬프로 변환
    auto timestamp = std::chrono::system_clock::to_time_t(now);

    // struct tm로 변환
    std::tm *timeinfo = std::localtime(&timestamp);

    // 문자열 형식으로 변환
    char timestamp_str[20];
    std::strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", timeinfo);

    format add_msg_query("INSERT INTO Msg values ('%s', '%s', '%s', '%s')");
    add_msg_query % msg.id % msg.opp_id % msg.text_msg % timestamp_str;
    db_error_code = sqlite3_exec(db, add_msg_query.str().c_str(), nullptr, nullptr, &db_error_msg);
    if (db_error_code != SQLITE_OK)
    {
        cout << db_error_msg << endl;
        sqlite3_free(db_error_msg);
        return false;
    }
    return true;
}

bool ServerDBManager::GetMsgList(const std::string &id, const std::string &opp_id, std::vector<Msg> &buf)
{
    CallBackFunc call_back = [](void *buf, int attr_num, char **tuple, char **attr)
    {
        vector<Msg> *msg_buf = (vector<Msg> *)buf;
        Msg msg;
        msg.id = tuple[0];
        msg.opp_id = tuple[1];
        msg.text_msg = tuple[2];
        msg_buf->push_back(msg);
        return 0;
    };

    buf.clear();

    format get_msg_query("SELECT id, opp_id, text_msg "
                         "FROM Msg "
                         "where (id = '%1%' and opp_id = '%2%') "
                         "      or (id = '%2%' and opp_id = '%1%') "
                         "ORDER BY msg_time;");
    get_msg_query % id % opp_id;
    db_error_code = sqlite3_exec(db, get_msg_query.str().c_str(), call_back, &buf, &db_error_msg);
    if (db_error_code != SQLITE_OK)
    {
        cout << db_error_msg << endl;
        sqlite3_free(db_error_msg);
        return false;
    }
    return true;
}

bool ServerDBManager::GetUserList(vector<UserInfo>& buf) 
{
    CallBackFunc call_back = [](void *buf, int attr_num, char **tuple, char **attr)
    {
        vector<UserInfo> *user_list_buf = (vector<UserInfo> *)buf;
        user_list_buf->resize(user_list_buf->size()+1);
        user_list_buf->back().id=tuple[0];

        return 0;
    };

    buf.clear();

    string get_user_list_query = "SELECT id "
                                 "FROM PersonalInfo ;";

    db_error_code = sqlite3_exec(db, get_user_list_query.c_str(), call_back, &buf, &db_error_msg);
    if (db_error_code != SQLITE_OK)
    {
        cout << db_error_msg << endl;
        sqlite3_free(db_error_msg);
        return false;
    }
    return true;
}

ServerDBManager::~ServerDBManager()
{
    sqlite3_close(db);
}

bool ServerDBManager::IsConstraintViolation()
{
    return db_error_code == SQLITE_CONSTRAINT;
}