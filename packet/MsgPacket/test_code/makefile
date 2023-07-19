WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/SimpleChatProgram
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

MsgProtocolTest.exe : MsgProtocolTest.cpp ../obj/MsgProtocol.o
	g++ $(INCLUDEDIR) MsgProtocolTest.cpp ../obj/MsgProtocol.o -o MsgProtocolTest.exe