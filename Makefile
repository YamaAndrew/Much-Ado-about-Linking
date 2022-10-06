CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = main.o linkedLists.o

main: $(OBJECTS)
	    $(CXX) -g $(CXXFLAGS) -o $@ main.o linkedLists.o

main.o: main.cpp linkedLists.h linkedLists.cpp
		$(CXX) -g $(CXXFLAGS) -c main.cpp

linkedLists.o: linkedLists.cpp linkedLists.h
		$(CXX) -g $(CXXFLAGS) -c linkedLists.cpp

clean:
	rm *.o
	rm main
