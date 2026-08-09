all: a.exe

a.exe: wp.o wp_main.o
	g++ wp.o wp_main.o

wp.o: wp.cpp
	g++ -c wp.cpp

wp_main: wp_main.cpp
	g++ -c wp_main.cpp

clean:
	rm -f*.o a.exe