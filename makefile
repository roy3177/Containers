##roymeoded2512@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

Main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

run: Main
	./main

clean:
	rm -f Main
