all : ClientAPITest.exe ClientManagerTest.exe

ClientAPITest.exe : ClientAPITest.cpp ../../../packet/MsgPacket/obj/MyMsg.o ../../../packet/MsgPacket/obj/MsgSockFunc.o ../obj/ClientAPI.o
	g++ -L/boost/lib/ -L. -I/boost/include/boost-1_81/ -I. -Isrc \
		ClientAPITest.cpp \
		../../../packet/MsgPacket/obj/MyMsg.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../obj/ClientAPI.o \
		-o ClientAPITest.exe \
		-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32

ClientManagerTest.exe : ClientManagerTest.cpp ../../../packet/MsgPacket/obj/MyMsg.o ../../../packet/MsgPacket/obj/MsgSockFunc.o ../obj/ClientAPI.o ../obj/ClientManager.o
	g++ -L/boost/lib/ -L. -I/boost/include/boost-1_81/ -I. -Isrc \
		ClientManagerTest.cpp \
		../../../packet/MsgPacket/obj/MyMsg.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../obj/ClientAPI.o \
		../obj/ClientManager.o \
		-o ClientManagerTest.exe \
		-llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32