WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/chat_program
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

ClientProgram.exe : src/ClientProgram.cpp \
					../front/obj/TerminalControl.o \
					../front/obj/BasePage.o \
					../front/obj/TitlePage.o \
					../front/obj/SignupPage.o \
					../front/obj/LoginPage.o \
					../front/obj/MainPage.o \
					../front/obj/MsgPage.o \
					../back/obj/ClientSock.o \
					../back/obj/ClientManager.o \
					../../packet/MsgPacket/obj/MsgProtocol.o \
					../../packet/MsgPacket/obj/MsgSockFunc.o
	g++ $(INCLUDEDIR) \
		-L/boost/lib/ -Ldll \
		src/ClientProgram.cpp \
		../front/obj/TerminalControl.o \
		../front/obj/BasePage.o \
		../front/obj/TitlePage.o \
		../front/obj/SignupPage.o \
		../front/obj/LoginPage.o \
		../front/obj/MainPage.o \
		../front/obj/MsgPage.o \
		../back/obj/ClientSock.o \
		../back/obj/ClientManager.o \
		../../packet/MsgPacket/obj/MsgProtocol.o \
		../../packet/MsgPacket/obj/MsgSockFunc.o \
		-o ClientProgram.exe \
		-lBearLibTerminal -llibboost_system-mgw12-mt-x64-1_81 -llibboost_thread-mgw12-mt-x64-1_81 -lws2_32