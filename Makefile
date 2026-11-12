CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

all: Lab_11

Lab_11: main.cpp
	$(CXX) $(CXXFLAGS) -o Lab_11 main.cpp

clean:
	rm -f Lab_11
