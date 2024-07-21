CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = main.o linkedLists.o

bard: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ $(OBJECTS)

main.o: main.cpp linkedLists.h
	$(CXX) -g $(CXXFLAGS) -c main.cpp

linkedLists.o: linkedLists.cpp linkedLists.h
	$(CXX) -g $(CXXFLAGS) -c linkedLists.cpp

clean:
	rm -f *.o bard
