WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/SimpleChatProgram
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

all : MsgEchoServ.exe ClientManagerTestServ.exe

MsgEchoServ.exe : MsgEchoServ.cpp ../../packet/MsgPacket/obj/MsgProtocol.o ../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ \
	MsgEchoServ.cpp \
	../../packet/MsgPacket/obj/MsgProtocol.o \
	../../packet/MsgPacket/obj/MsgSockFunc.o \
	-o MsgEchoServ.exe \
	-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32

ClientManagerTestServ.exe : ClientManagerTestServ.cpp \
							../../packet/MsgPacket/obj/MsgProtocol.o \
							../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ \
	ClientManagerTestServ.cpp \
	../../packet/MsgPacket/obj/MsgProtocol.o \
	../../packet/MsgPacket/obj/MsgSockFunc.o \
	-o ClientManagerTestServ.exe \
	-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32