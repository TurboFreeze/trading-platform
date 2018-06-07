CC=clang++
CPPFLAGS=-I inc

%.o: %.cpp
	$(CC) -c -std=c++11 -o $@ $< $(CPPFLAGS)

client: View.o Controller.o client.o
	$(CC) -o client View.o Controller.o client.o

clean:
	rm client View.o Controller.o client.o
