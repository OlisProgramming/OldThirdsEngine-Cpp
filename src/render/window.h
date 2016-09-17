#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "../mesh/mesh.h"

namespace render
{
	namespace window
	{
		extern GLFWwindow* glfwWindow;
		extern mesh::Mesh* mesh_test;
		
		void init(int width, int height, char* title);
		
		void start();
		void stop();
		
		void render();
		//void update();
		
		void key_callback(int key, int scancode, int action, int mode);
		void window_size_callback(int width, int height);
		
		void dispose();
	}
}
