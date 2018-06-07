CC=clang++
CPPFLAGS=-I inc

%.o: %.cpp
	$(CC) -c -std=c++11 -o $@ $< $(CPPFLAGS)

client: Controller.o client.o
	$(CC) -o client Controller.o client.o

clean:
	rm client Controller.o client.o
