
all: a.out

a.out:
	g++ main.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

clean:
	rm a.out