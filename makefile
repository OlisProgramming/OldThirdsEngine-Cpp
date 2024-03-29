ThirdsEngine: build/main.o
	g++ -o ThirdsEngine \
		build/math/vec2.o \
		build/math/vec3.o \
		build/math/quat.o \
		build/math/mat4.o \
		build/math/transform.o \
		build/mesh/mesh.o \
		build/render/shader.o \
		build/render/renderUtil.o \
		build/render/window.o \
		build/main.o \
		-L/usr/local/lib -lGLEW -lGLU -lGL -lglfw3 -ldl -lXrandr -lXinerama -lXxf86vm -lXcursor -lX11 -lpthread

build/main.o: src/main.cpp build/math/vec2.o build/math/vec3.o build/math/mat4.o build/math/quat.o build/render/shader.o build/render/window.o
	g++ -c -std=c++11 -lstdc++ \
		src/main.cpp -o build/main.o

build/math/vec2.o: src/math/vec2.cpp src/math/vec2.h
	g++ -c -std=c++11 -lstdc++ \
		src/math/vec2.cpp -o build/math/vec2.o

build/math/vec3.o: build/math/quat.o src/math/vec3.cpp src/math/vec3.h
	g++ -c -std=c++11 -lstdc++ \
		src/math/vec3.cpp -o build/math/vec3.o

build/math/mat4.o: src/math/mat4.cpp src/math/mat4.h
	g++ -c -std=c++11 -lstdc++ \
		src/math/mat4.cpp -o build/math/mat4.o

build/math/quat.o: src/math/quat.cpp src/math/quat.h
	g++ -c -std=c++11 -lstdc++ \
		src/math/quat.cpp -o build/math/quat.o
		
build/math/transform.o: build/math/vec3.o build/math/mat4.o src/math/transform.cpp src/math/transform.h
	g++ -c -std=c++11 -lstdc++ \
		src/math/transform.cpp -o build/math/transform.o

build/mesh/mesh.o: build/math/transform.o src/mesh/mesh.cpp src/mesh/mesh.h
	g++ -c -std=c++11 -lstdc++ \
		src/mesh/mesh.cpp -o build/mesh/mesh.o

build/render/window.o: build/render/shader.o build/mesh/mesh.o build/render/renderUtil.o src/render/window.cpp src/render/window.h
	g++ -c -std=c++11 -lstdc++ \
		src/render/window.cpp -o build/render/window.o

build/render/shader.o: build/math/mat4.o src/render/shader.cpp src/render/shader.h
	g++ -c -std=c++11 -lstdc++ \
		src/render/shader.cpp -o build/render/shader.o
		
build/render/renderUtil.o: src/render/renderUtil.cpp src/render/renderUtil.h
	g++ -c -std=c++11 -lstdc++ \
		src/render/renderUtil.cpp -o build/render/renderUtil.o
