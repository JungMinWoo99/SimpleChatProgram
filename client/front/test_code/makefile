WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/SimpleChatProgram
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

all : TerminalControlUnitTest.exe TitlePageTest.exe LoginPageTest.exe SignupPageTest.exe MainPageTest.exe MsgPageTest.exe

TerminalControlUnitTest.exe : TerminalControlUnitTest.cpp ../obj/TerminalControl.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ -L../dll/\
		TerminalControlUnitTest.cpp\
		../obj/TerminalControl.o \
		-o TerminalControlUnitTest.exe \
		-lBearLibTerminal

TitlePageTest.exe : TitlePageTest.cpp ../obj/TitlePage.o ../obj/BasePage.o ../obj/TerminalControl.o \
					../../back/obj/ClientSock.o ../../back/obj/ClientManager.o \
					../../../packet/MsgPacket/obj/MsgProtocol.o ../../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ -L../dll/\
		TitlePageTest.cpp\
		../obj/TitlePage.o \
		../obj/BasePage.o \
		../obj/TerminalControl.o\
		../../back/obj/ClientSock.o \
		../../../packet/MsgPacket/obj/MsgProtocol.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../../back/obj/ClientManager.o \
		-o TitlePageTest.exe \
		-lBearLibTerminal -llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32

LoginPageTest.exe : LoginPageTest.cpp ../obj/LoginPage.o ../obj/BasePage.o ../obj/TerminalControl.o \
					../../back/obj/ClientSock.o ../../back/obj/ClientManager.o \
					../../../packet/MsgPacket/obj/MsgProtocol.o ../../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ -L../dll/\
		LoginPageTest.cpp\
		../obj/LoginPage.o \
		../obj/BasePage.o \
		../obj/TerminalControl.o \
		../../back/obj/ClientSock.o \
		../../../packet/MsgPacket/obj/MsgProtocol.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../../back/obj/ClientManager.o \
		-o LoginPageTest.exe \
		-lBearLibTerminal -llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32

SignupPageTest.exe : SignupPageTest.cpp ../obj/SignupPage.o ../obj/BasePage.o ../obj/TerminalControl.o \
					../../back/obj/ClientSock.o ../../back/obj/ClientManager.o \
					../../../packet/MsgPacket/obj/MsgProtocol.o ../../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ -L../dll/\
		SignupPageTest.cpp\
		../obj/SignupPage.o \
		../obj/BasePage.o \
		../obj/TerminalControl.o \
		../../back/obj/ClientSock.o \
		../../../packet/MsgPacket/obj/MsgProtocol.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../../back/obj/ClientManager.o \
		-o SignupPageTest.exe \
		-lBearLibTerminal -llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32

MainPageTest.exe : MainPageTest.cpp ../obj/MainPage.o ../obj/BasePage.o ../obj/TerminalControl.o \
					../../back/obj/ClientSock.o ../../back/obj/ClientManager.o \
					../../../packet/MsgPacket/obj/MsgProtocol.o ../../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ -L../dll/\
		MainPageTest.cpp\
		../obj/MainPage.o \
		../obj/BasePage.o \
		../obj/TerminalControl.o\
		../../back/obj/ClientSock.o \
		../../../packet/MsgPacket/obj/MsgProtocol.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../../back/obj/ClientManager.o \
		-o MainPageTest.exe \
		-lBearLibTerminal -lBearLibTerminal -llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32

MsgPageTest.exe : MsgPageTest.cpp ../obj/MsgPage.o ../obj/BasePage.o ../obj/TerminalControl.o \
					../../back/obj/ClientSock.o ../../back/obj/ClientManager.o \
					../../../packet/MsgPacket/obj/MsgProtocol.o ../../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ -L../dll/\
		MsgPageTest.cpp \
		../obj/MsgPage.o \
		../obj/BasePage.o \
		../obj/TerminalControl.o \
		../../back/obj/ClientSock.o \
		../../../packet/MsgPacket/obj/MsgProtocol.o \
		../../../packet/MsgPacket/obj/MsgSockFunc.o \
		../../back/obj/ClientManager.o \
		-o MsgPageTest.exe \
		-lBearLibTerminal -lBearLibTerminal -llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32
