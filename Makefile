all:
	clang++ task101.cpp -F/Library/Frameworks -framework SDL2 -Wl,-rpath,/Library/Frameworks -o my_circle

run:
	./my_circle

clean:
	rm -f my_circle