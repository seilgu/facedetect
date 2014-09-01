
all: a.out

a.out: main.cpp
	g++ main.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

clean:
	rm a.out