CXXFLAGS = -g -Wall --std=c++11

main: main.o profile.o network.o
	g++ $(CXXFLAGS) -o main main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ $(CXXFLAGS) -o tests tests.o profile.o network.o


main.o: main.cpp
profile.o: profile.cpp profile.h
network.o: network.cpp network.h

tests.o: tests.cpp doctest.h

clean:
	rm -rf *o a.out