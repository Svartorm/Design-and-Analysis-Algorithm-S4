main: clean build run

init: build run

build:
	g++ -std=c++11 -o res hike.cpp

clean:
	del -f *.exe

run:
	./res.exe