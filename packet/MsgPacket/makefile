WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/SimpleChatProgram
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

all : obj/MsgProtocol.o obj/MsgSockFunc.o

obj/MsgProtocol.o : src/MsgProtocol.cpp
	g++ $(INCLUDEDIR) -c src/MsgProtocol.cpp -o obj/MsgProtocol.o

obj/MsgSockFunc.o : src/MsgSockFunc.cpp
	g++ $(INCLUDEDIR) -c src/MsgSockFunc.cpp -o obj/MsgSockFunc.o