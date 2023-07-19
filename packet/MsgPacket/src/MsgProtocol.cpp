#include <cstring>
#include <iostream>

#include "MsgProtocol.hpp"

using namespace std;

void UserInfo::TransformToPacket(MsgPacket *buf) const
{
    strcpy(buf->name, this->name.c_str());
    strcpy(buf->id, this->id.c_str());
    strcpy(buf->passwd, this->passwd.c_str());
}

void UserInfo::TransformFromPacket(const MsgPacket *buf)
{
    this->name = buf->name;
    this->id = buf->id;
    this->passwd = buf->passwd;
}

void UserInfo::TransformToMsg(Msg &buf) const
{
    buf.name = this->name;
    buf.id = this->id;
    buf.passwd = this->id;
}

void UserInfo::TransformFromMsg(const Msg &buf)
{
    this->name = buf.name;
    this->id = buf.id;
    this->passwd = buf.passwd;
}

void UserInfo::PrintMsgContent()
{
    std::cout << "name: " << this->name << std::endl;
    std::cout << "id: " << this->id << std::endl;
    std::cout << "passwd: " << this->passwd << std::endl;
}

void Msg::TransformToPacket(MsgPacket *buf) const
{
    buf->mtype = this->mtype;
    strcpy(buf->name, this->name.c_str());
    strcpy(buf->id, this->id.c_str());
    strcpy(buf->passwd, this->passwd.c_str());
    strcpy(buf->text_msg, this->text_msg.c_str());
    strcpy(buf->opp_id, this->opp_id.c_str());
    buf->error_code = this->error_code;
}

void Msg::TransformFromPacket(const MsgPacket *buf)
{
    this->mtype = buf->mtype;
    this->name = buf->name;
    this->id = buf->id;
    this->passwd = buf->passwd;
    this->text_msg = buf->text_msg;
    this->opp_id = buf->opp_id;
    this->error_code = buf->error_code;
}

void Msg::TransformToUserInfo(UserInfo &buf) const
{
    buf.name = this->name;
    buf.id = this->id;
    buf.passwd = this->id;
}

void Msg::TransformFromUserInfo(const UserInfo &buf)
{
    this->name = buf.name;
    this->id = buf.id;
    this->passwd = buf.passwd;
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