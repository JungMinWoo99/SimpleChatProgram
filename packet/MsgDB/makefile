WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/SimpleChatProgram
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

all: obj/sqlite3.o obj/ServerDBManager.o

obj/sqlite3.o : src/sqlite3.c
	gcc -c src/sqlite3.c -o obj/sqlite3.o

obj/ServerDBManager.o : src/ServerDBManager.cpp
	g++ $(INCLUDEDIR) -c src/ServerDBManager.cpp -o obj/ServerDBManager.o