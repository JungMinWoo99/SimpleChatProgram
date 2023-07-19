WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/SimpleChatProgram
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

all : ClientSockTest.exe ClientManagerTest.exe

ClientSockTest.exe : ClientSockTest.cpp ../../../packet/MsgPacket/obj/MsgProtocol.o ../../../packet/MsgPacket/obj/MsgSockFunc.o ../obj/ClientSock.o
	g++ -L/boost/lib/ $(INCLUDEDIR) \
		ClientSockTest.cpp \
		../../../packet/MsgPacket/obj/MsgProtocol.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../obj/ClientSock.o \
		-o ClientSockTest.exe \
		-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32

ClientManagerTest.exe : ClientManagerTest.cpp ../../../packet/MsgPacket/obj/MsgProtocol.o ../../../packet/MsgPacket/obj/MsgSockFunc.o ../obj/ClientSock.o ../obj/ClientManager.o
	g++ -L/boost/lib/ $(INCLUDEDIR) \
		ClientManagerTest.cpp \
		../../../packet/MsgPacket/obj/MsgProtocol.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../obj/ClientSock.o \
		../obj/ClientManager.o \
		-o ClientManagerTest.exe \
		-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32