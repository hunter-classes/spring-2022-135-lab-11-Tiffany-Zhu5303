OBJECTS = profile.o network.o

main: main.o profile.o network.o
	g++ -o main main.o $(OBJECTS)

tests: tests.o profile.o network.o
	g++ -o tests tests.o $(OBJECTS)

profile.o: profile.cpp profile.h

network.o: network.cpp network.h profile.h

main.o: main.cpp profile.h network.h
	g++ --std=c++11 -c main.cpp profile.h network.h

tests.o: tests.cpp doctest.h

clean:
	rm -f main tests main.o tests.o $(OBJECTS)
