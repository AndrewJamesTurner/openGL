# GCC complier 
CC=g++

# GCC complier options
	# -pedantic		Issue all the warnings demanded by strict ISO C
	# -Wall			Turns on all optional warnings which are desirable for normal code.
	# -O3			turns on all optimizations
	# -g			turns on debugging information	
	# -pg			turns on profiling information (for gprof)
	# -w			ignore warning 
	# -fpermissive
	# -std=c++11		use c++ 2011 standard
	
CFLAGS= -std=c++11 -pedantic -Wall -O3
GLFLAGS= -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread

helloWorld: src/helloWorld.cpp 
	@$(CC) -o helloWorld src/helloWorld.cpp $(CFLAGS) $(GLFLAGS) 

helloTriangle: src/helloTriangle.cpp
	@$(CC) -o helloTriangle src/helloTriangle.cpp $(CFLAGS) $(GLFLAGS) 

astyle: src/*.cpp
	astyle --style=kr src/*.cpp



clean:
	@rm -f src/*.orig helloWorld helloTriangle
