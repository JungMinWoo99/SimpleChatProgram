#include "sqlite3.h"
#include "MsgProtocol.hpp"

#undef SQLITE_OMIT_FOREIGN_KEY
#undef SQLITE_OMIT_TRIGGER

#include <vector>

class ServerDBManager
{
private:
    sqlite3 *db;
    int db_error_code=0;
    char * db_error_msg=0;
public:
    ServerDBManager(const std::string& db_dir);

    bool AddUserInfo(const UserInfo& user_info);

    bool GetUserInfo(const std::string& user_id, UserInfo& buf);

    bool AddMsg(const Msg& msg);

    bool GetMsgList(const std::string& id, const std::string& opp_id, std::vector<Msg>& buf);

    bool GetUserList(std::vector<UserInfo>& buf);

    bool IsConstraintViolation();

    ~ServerDBManager();
};