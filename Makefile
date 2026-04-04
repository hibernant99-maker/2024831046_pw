# Existing Flags
CXXFLAGS = -I/Library/Frameworks/SDL2.framework/Headers
# ADD -Wl,-rpath,/Library/Frameworks to the LDFLAGS below
LDFLAGS = -F/Library/Frameworks -framework SDL2 -Wl,-rpath,/Library/Frameworks

all: circle101 circle102 circle103

circle101: task101.cpp
	g++ task101.cpp -o circle101 $(CXXFLAGS) $(LDFLAGS)

circle102: task102.cpp
	g++ task102.cpp -o circle102 $(CXXFLAGS) $(LDFLAGS)

circle103: task103.cpp
	g++ task103.cpp -o circle103 $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f circle101 circle102 circle103