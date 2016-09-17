compile () {
	g++ -std=c++11 \
	src/$1.cpp \
	-lstdc++ -o build/$1.cpp.o -c
}

compile math/vec2
compile math/vec3
compile math/quat
compile math/mat4
compile render/shader
compile render/window
compile main	

g++ -o ThirdsEngine \
	build/math/vec2.cpp.o \
	build/math/vec3.cpp.o \
	build/math/quat.cpp.o \
	build/math/mat4.cpp.o \
	build/render/shader.cpp.o \
	build/render/window.cpp.o \
	build/main.cpp.o \
	-L/usr/local/lib -lGLEW -lGLU -lGL -lglfw3 -ldl -lXrandr -lXinerama -lXxf86vm -lXcursor -lX11 -lpthread
