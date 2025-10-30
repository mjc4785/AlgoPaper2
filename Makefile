CXX = g++
CXXFLAGS = -Wall -O2

all: minChange 

euclids: minChange	
	$(CXX) $(CXXFLAGS) minChange.cpp -o minChange 

clean:
	rm -f minChange 

val:
	valgrind --leak-check=full ./minChange

run-min:
	./minChange
