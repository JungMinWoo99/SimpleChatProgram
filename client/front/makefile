WORKSPACEFOLDER = /Users/qqdld/Desktop/Dev/network_chat_program/chat_program
INCLUDEDIR = -I/boost/include/boost-1_81/ \
             -I$(WORKSPACEFOLDER)/client/back/header/ \
             -I${WORKSPACEFOLDER}/client/front/header \
             -I${WORKSPACEFOLDER}/server/header \
             -I${WORKSPACEFOLDER}/packet/MsgPacket/header \
             -I${WORKSPACEFOLDER}/packet/MsgDB/header

all : obj/TerminalControl.o obj/BasePage.o obj/TitlePage.o obj/SignupPage.o obj/LoginPage.o obj/MainPage.o obj/MsgPage.o

obj/MsgPage.o: src/MsgPage.cpp
	g++ $(INCLUDEDIR) -c src/MsgPage.cpp -o obj/MsgPage.o

obj/MainPage.o: src/MainPage.cpp
	g++ $(INCLUDEDIR) -c src/MainPage.cpp -o obj/MainPage.o

obj/LoginPage.o: src/LoginPage.cpp
	g++ $(INCLUDEDIR) -c src/LoginPage.cpp -o obj/LoginPage.o

obj/SignupPage.o: src/SignupPage.cpp
	g++ $(INCLUDEDIR) -c src/SignupPage.cpp -o obj/SignupPage.o

obj/TitlePage.o : src/TitlePage.cpp
	g++ $(INCLUDEDIR) -c src/TitlePage.cpp -o obj/TitlePage.o

obj/BasePage.o : src/BasePage.cpp
	g++ $(INCLUDEDIR) -c src/BasePage.cpp -o obj/BasePage.o

obj/TerminalControl.o : src/TerminalControl.cpp
	g++ $(INCLUDEDIR) -c src/TerminalControl.cpp -o obj/TerminalControl.o