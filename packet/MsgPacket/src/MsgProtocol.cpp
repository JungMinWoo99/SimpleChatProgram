#include <cstring>
#include <iostream>

#include "MsgProtocol.hpp"

using namespace std;

void Msg::TransformToPacket(MsgPacket *buf)
{
    buf->mtype = this->mtype;
    strcpy(buf->name, this->name.c_str());
    strcpy(buf->id, this->id.c_str());
    strcpy(buf->passwd, this->passwd.c_str());
    strcpy(buf->text_msg, this->text_msg.c_str());
    strcpy(buf->opp_id, this->opp_id.c_str());
    buf->error_code = this->error_code;
}

void Msg::TransformFromPacket(const MsgPacket * buf)
{
    this->mtype = buf->mtype;
    this->name = buf->name;
    this->id = buf->id;
    this->passwd =  buf->passwd;
    this->text_msg = buf->text_msg;
    this->opp_id = buf->opp_id;
    this->error_code = buf->error_code;
}

void Msg::PrintMsgContent()
{
    std::cout << "mtype: " << this->mtype << std::endl;
    std::cout << "name: " << this->name << std::endl;
    std::cout << "id: " << this->id << std::endl;
    std::cout << "passwd: " << this->passwd << std::endl;
    std::cout << "text_msg: " << this->text_msg << std::endl;
    std::cout << "opp_id: " << this->opp_id << std::endl;
    std::cout << "error_code: " << this->error_code << std::endl;
}

void Msg::TransformToUserInfo(UserInfo* buf)
{
    strcpy(buf->name, this->name.c_str());
    strcpy(buf->id, this->id.c_str());
    strcpy(buf->passwd, this->passwd.c_str());
}

void Msg::TransformFromUserInfo(const UserInfo* buf)
{
    this->id = buf->id;
    this->passwd =  buf->passwd;
    this->name = buf->name;
}

void MsgConverter::UserInfoToMsgPacket(MsgPacket *dest, const UserInfo *src)
{
    strcpy(dest->name, src->name);
    strcpy(dest->id, src->id);
    strcpy(dest->passwd, src->passwd);
}

void MsgConverter::MsgPacketToUserInfo(UserInfo *dest, const MsgPacket *src)
{
    strcpy(dest->name, src->name);
    strcpy(dest->id, src->id);
    strcpy(dest->passwd, src->passwd);
}