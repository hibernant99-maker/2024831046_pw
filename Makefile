# Compiler and Flags for Mac
CXX = clang++
FLAGS = -F/Library/Frameworks -framework SDL2 -Wl,-rpath,/Library/Frameworks

# Default rule: Type 'make' to compile everything
all: task101 task102

# Rule for Task 101 (Static Circle)
task101:
	$(CXX) task101.cpp $(FLAGS) -o circle101

# Rule for Task 102 (Expanding Circle)
task102:
	$(CXX) task102.cpp $(FLAGS) -o circle102

# Clean rule: Type 'make clean' to remove executables
clean:
	rm -f circle101 circle102