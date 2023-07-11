all : MsgEchoServ.exe ClientManagerTestServ.exe

MsgEchoServ.exe : MsgEchoServ.cpp ../../packet/MsgPacket/obj/MsgProtocol.o ../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ -L/boost/lib/ -I/boost/include/boost-1_81/ \
	MsgEchoServ.cpp \
	../../packet/MsgPacket/obj/MsgProtocol.o \
	../../packet/MsgPacket/obj/MsgSockFunc.o \
	-o MsgEchoServ.exe \
	-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32

ClientManagerTestServ.exe : ClientManagerTestServ.cpp \
							../../packet/MsgPacket/obj/MsgProtocol.o \
							../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ -L/boost/lib/ -I/boost/include/boost-1_81/ \
	ClientManagerTestServ.cpp \
	../../packet/MsgPacket/obj/MsgProtocol.o \
	../../packet/MsgPacket/obj/MsgSockFunc.o \
	-o ClientManagerTestServ.exe \
	-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32