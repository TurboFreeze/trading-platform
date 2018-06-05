CC=clang++
CPPFLAGS=-I inc

%.o: %.cpp
	$(CC) -c -std=c++11 -o $@ $< $(CPPFLAGS)

client: client.o
	$(CC) -o client client.o

clean:
	rm client client.o
