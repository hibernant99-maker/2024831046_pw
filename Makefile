all:
	clang++ task101.cpp -F/Library/Frameworks -framework SDL2 -o my_circle

run:
	./my_circle