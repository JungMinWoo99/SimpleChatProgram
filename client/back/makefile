WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/SimpleChatProgram
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header


all : obj/ClientSock.o obj/ClientManager.o

obj/ClientSock.o : src/ClientSock.cpp
	g++ $(INCLUDEDIR) -c src/ClientSock.cpp -o obj/ClientSock.o

obj/ClientManager.o : src/ClientManager.cpp
	g++ $(INCLUDEDIR) -c src/ClientManager.cpp -o obj/ClientManager.o
