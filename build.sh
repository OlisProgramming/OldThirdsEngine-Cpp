g++ -std=c++11 \
	src/math/vec2.cpp \
	src/math/vec3.cpp \
	src/math/mat4.cpp \
	src/render/shader.cpp \
	src/render/window.cpp \
	src/main.cpp \
	-lstdc++ -o ThirdsEngine -L/usr/local/lib -lXi -lGLEW -lGLU -lm -lGL -lm -lpthread -ldl -ldrm -lXdamage -lX11-xcb -lxcb-glx -lxcb-dri2 -lxcb-dri3 -lxcb-present -lxcb-randr -lxcb-xfixes -lxcb-render -lxcb-shape -lxcb-sync -lxshmfence -lglfw3 -lrt -lm -ldl -lXrandr -lXinerama -lXxf86vm -lXext -lXcursor -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lXdmcp 
