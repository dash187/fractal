CXX = g++
CXXFLAGS = -Wextra -Wall -pedantic 
HEADERS = $(wildcard *.hpp)
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(filter-out %test.cpp, $(SRC)))
TEST_OBJ = $(filter-out main.o, $(OBJ))

all:	format compile run

compile:	main complex_test

run:
	./main
	feh out.ppm

main:	$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%test:	%test.o	$(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lpthread -lgtest -lgtest_main

%.o:	%.cpp	$(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

format:
	clang-format -i *.cpp *.hpp

clean:
	rm -f main *test *.o *.ppm
