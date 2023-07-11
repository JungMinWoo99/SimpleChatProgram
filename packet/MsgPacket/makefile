all : obj/MsgProtocol.o obj/MsgSockFunc.o

obj/MsgProtocol.o : src/MsgProtocol.cpp
	g++ -Isrc -c src/MsgProtocol.cpp -o obj/MsgProtocol.o

obj/MsgSockFunc.o : src/MsgSockFunc.cpp
	g++ -I/boost/include/boost-1_81/ -Isrc -c src/MsgSockFunc.cpp -o obj/MsgSockFunc.o