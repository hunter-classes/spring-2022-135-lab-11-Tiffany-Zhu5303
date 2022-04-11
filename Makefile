OBJECTS = profile.o

main: main.o profile.o
	g++ -o main main.o $(OBJECTS)

tests: tests.o profile.o
	g++ -o tests tests.o $(OBJECTS)

profile.o: profile.cpp profile.h

main.o: main.cpp profile.h

tests.o: tests.cpp doctest.h

clean:
	rm -f main tests main.o tests.o $(OBJECTS)
