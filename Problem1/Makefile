all: server peer
server: server.o
	g++ -o server server.o
peer: peer.o 
	g++ -o peer peer.o 
peer.o: peer.cpp
	g++ -c peer.cpp
server.o: server.cpp peerinfo.hpp
	g++ -c server.cpp
