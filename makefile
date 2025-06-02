##roymeoded2512@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

Main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test 

valgrind: test.cpp main.cpp
	@echo " Running valgrind on test.cpp"
	$(CXX) $(CXXFLAGS) test.cpp -o test
	valgrind --leak-check=full --track-origins=yes ./test

	@echo "\n Running valgrind on main.cpp"
	$(CXX) $(CXXFLAGS) main.cpp -o main
	valgrind --leak-check=full --track-origins=yes ./main

clean:
	rm -f main test


