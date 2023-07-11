WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/chat_program
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header


all: obj/SyncServerSock.o obj/SyncChatServ.o SyncServerMain.exe

obj/SyncServerSock.o : src/SyncServerSock.cpp
	g++ -c $(INCLUDEDIR) src/SyncServerSock.cpp -o obj/SyncServerSock.o

obj/SyncChatServ.o : src/SyncChatServ.cpp
	g++ -c $(INCLUDEDIR) src/SyncChatServ.cpp -o obj/SyncChatServ.o

SyncServerMain.exe : src/SyncChatServMain.cpp \
					 obj/SyncServerSock.o obj/SyncChatServ.o \
					 ../packet/MsgPacket/obj/MsgProtocol.o \
					 ../packet/MsgPacket/obj/MsgSockFunc.o \
					 ../packet/MsgDB/obj/ServerDBManager.o \
					 ../packet/MsgDB/obj/sqlite3.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ \
		src/SyncChatServMain.cpp \
		obj/SyncServerSock.o \
		obj/SyncChatServ.o \
		../packet/MsgPacket/obj/MsgProtocol.o \
		../packet/MsgPacket/obj/MsgSockFunc.o \
		../packet/MsgDB/obj/ServerDBManager.o \
		../packet/MsgDB/obj/sqlite3.o\
		-o SyncChatServMain.exe \
		-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32