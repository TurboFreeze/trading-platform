CC=clang++
CPPFLAGS=-I inc

%.o: %.cpp 
	$(CC) -c -std=c++11 -o $@ $< $(CPPFLAGS)

server: Bid.o Platform.o Connection.o server.o
	$(CC) -o server Bid.o Platform.o Connection.o server.o

clean:
	rm server Bid.o Platform.o Connection.o server.o
