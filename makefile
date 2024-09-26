# Targets for compiling the Tower of Hanoi program and the Median program

# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -g

# Targets
TARGET_HANOI = a1-5.out
TARGET_MEDIAN = a1-4.out

# Rules
hanoi: a1-5.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_HANOI) a1-5.cpp

median: a1-4.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_MEDIAN) a1-4.cpp

# Clean rule
clean:
	rm -f *.out
