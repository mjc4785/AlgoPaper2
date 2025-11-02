CXX = g++
CXXFLAGS = -Wall -O2

all: minChange JohnsonTrotter

minChange: minChange.cpp	
	$(CXX) $(CXXFLAGS) minChange.cpp -o minChange 

JohnsonTrotter: JohnsonTrotter.cpp
	$(CXX) $(CXXFLAGS) JohnsonTrotter.cpp -o JohnsonTrotter 

clean:
	rm -f minChange JohnsonTrotter 

val-min:
	valgrind --leak-check=full ./minChange

val-j:
	valgrind --leak-check=full ./JohnsonTrotter

run-j:
	./JohnsonTrotter

run-min:
	./minChange
