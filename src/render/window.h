#pragma once

// GLFW
#include <GLFW/glfw3.h>

namespace render
{
	namespace window
	{
		extern GLFWwindow* glfwWindow;
		
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
