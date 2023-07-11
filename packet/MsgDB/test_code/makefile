WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/chat_program
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

all : ServerDBManagerTest.exe

ServerDBManagerTest.exe : ServerDBManagerTest.cpp ../obj/ServerDBManager.o ../obj/sqlite3.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ \
		ServerDBManagerTest.cpp \
		../obj/ServerDBManager.o ../obj/sqlite3.o \
		../../MsgPacket/obj/MsgProtocol.o \
		-o ServerDBManagerTest.exe