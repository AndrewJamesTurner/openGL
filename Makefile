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

HelloWorld: src/HelloWorld.cpp 
	@$(CC) -o HelloWorld src/HelloWorld.cpp $(CFLAGS) $(GLFLAGS) 

HelloTriangle: src/HelloTriangle.cpp
	@$(CC) -o HelloTriangle src/HelloTriangle.cpp $(CFLAGS) $(GLFLAGS) 
	
HelloShaders: src/HelloShaders.cpp include/Shader.h
	@$(CC) -o HelloShaders src/HelloShaders.cpp include/Shader.h $(CFLAGS) $(GLFLAGS) 

astyle: src/*.cpp include/*.h
	astyle --style=kr src/*.cpp include/*.h



clean:
	@rm -f src/*.orig include/*.orig HelloWorld HelloTriangle HelloShaders
