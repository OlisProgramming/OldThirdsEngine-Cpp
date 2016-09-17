g++ -std=c++11 \
	src/math/vec2.cpp \
	src/math/vec3.cpp \
	src/math/quat.cpp \
	src/math/mat4.cpp \
	src/render/shader.cpp \
	src/render/window.cpp \
	src/main.cpp \
	-lstdc++ -o ThirdsEngine -L/usr/local/lib -lGLEW -lGLU -lGL -lglfw3 -ldl -lXrandr -lXinerama -lXxf86vm -lXcursor -lX11 -lpthread
