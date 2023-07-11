#ifndef MSGPROTOCOL_HPP
#define MSGPROTOCOL_HPP

#include <string>

#define PERMS 0777
#define PROJID 2019203070

/**
 * 포트 번호
 */

#define ECHO_SERV_PORT 54322

/*
 * 메세지 타입
 */
#define LOGIN 21   // 로그인
#define SIGNUP 22  // 회원가입
#define USERMSG 23 // 유저 메세지 전송
#define USLSREQ 24 // 유저목록 전송
#define LISTEND 25 // 목록 전송완료
#define ROOMREQ 26 // 채팅방 입장
#define MSLSREQ 27 // 메세지 목록 전송
#define DISCNET 28 // 연결 종료

/*
 * 에러 코드
 */
#define ALEXID 11 // 이미 존재하는 아이디로 회원가입할 경우 에러코드
#define NOEXID 12 // 존재하지 않는 아이디를 입력한 경우 에러코드
#define INCRPW 13 // 잘못된 비밀번호로 로그인을 시도한 경우 에러코드
#define YOURID 14 // 본인아이디로 본인아이디에 접근한 경우 에러코드
#define UNEXPT 15 // 기타 파악하지 못한 에러

/*
 * 메세지 정보
 */
#define MAX_INFO_LEN 10
#define MAX_TEXT_LEN 20

typedef int ErrorCode;

struct MsgPacket
{
    int mtype = 0;
    char name[MAX_INFO_LEN + 1] = {0};
    char id[MAX_INFO_LEN + 1] = {0};
    char passwd[MAX_INFO_LEN + 1] = {0};
    char text_msg[MAX_TEXT_LEN + 1] = {0};
    char opp_id[MAX_INFO_LEN + 1] = {0};
    int error_code = 0;  
};

struct UserInfo
{
    char name[MAX_INFO_LEN + 1] = {0};
    char id[MAX_INFO_LEN + 1] = {0};
    char passwd[MAX_INFO_LEN + 1] = {0};
};

class Msg
{
public:
    // 메크로 상수로 정의 메세지 코드를 저장한 변수
    int mtype = 0;
    // 사용자 정보
    std::string name;
    std::string id;
    std::string passwd;
    // 전달할 메세지
    std::string text_msg;
    // 전달할 상대
    std::string opp_id;
    // 메크로 상수로 정의한 에러코드를 저장한 변수
    int error_code = 0; // 에러코드가 0이면 에러없이 성공했다는 의미

    //패킷 변환 관련 함수

    void TransformToPacket(MsgPacket* buf);

    void TransformFromPacket(const MsgPacket* buf);

    void TransformToUserInfo(UserInfo* buf);

    void TransformFromUserInfo(const UserInfo* buf);

    void PrintMsgContent();
};

struct MsgConverter
{
    static void UserInfoToMsgPacket(MsgPacket *dest, const UserInfo *src);
    static void MsgPacketToUserInfo(UserInfo *dest, const MsgPacket *src);
};

#endif /* MSGPROTOCOL_HPP */
