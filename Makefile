CXX = g++
CXXFLAGS = -Wextra -Wall -pedantic 
HEADERS = $(wildcard *.hpp)
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))

main:	$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o:	%.cpp	$(HEADERS)
	$(CXX) $(CXXFLAGS) -c $^

format:
	clang-format -i *.cpp *.hpp

clean:
	rm -f main *.o
