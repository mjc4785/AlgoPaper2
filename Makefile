CXX = g++
CXXFLAGS = -Wall -O2

all: minChange JohnsonTrotter combination

minChange: minChange.cpp	
	$(CXX) $(CXXFLAGS) minChange.cpp -o minChange 

JohnsonTrotter: JohnsonTrotter.cpp
	$(CXX) $(CXXFLAGS) JohnsonTrotter.cpp -o JohnsonTrotter 

combination: combination.cpp
	$(CXX) $(CXXFLAGS) combination.cpp -o combination

clean:
	rm -f minChange JohnsonTrotter combination 

val-min:
	valgrind --leak-check=full ./minChange

val-j:
	valgrind --leak-check=full ./JohnsonTrotter

val-com:
	valgrind --leak-check=full ./combination

run-j:
	./JohnsonTrotter

run-min:
	./minChange

run-com:
	./combination

