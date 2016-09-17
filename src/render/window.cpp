#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

#include "shader.h"

#include "window.h"

namespace render
{
	namespace window
	{
		GLFWwindow* glfwWindow;
		
		// Initialises program data and opens window
		void init(int width, int height, char* title)
		{
			std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
			// Init GLFW
			glfwInit();
			// OpenGL 3.3
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

			// Create Window
			glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
			glfwMakeContextCurrent(glfwWindow);

			// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
			glewExperimental = GL_TRUE;
			// Initialize GLEW
			glewInit();
		}
		
		// Starts up program
		void start()
		{
			render::shader::initVertexShader();
			render::shader::initFragmentShader();
			render::shader::compileShaderProgram();
			
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			
			// Game loop
			while (!glfwWindowShouldClose(glfwWindow))
			{
				render();
			}
			dispose();
		}
		
		// Stops program
		void stop()
		{
			glfwSetWindowShouldClose(glfwWindow, GL_TRUE);
		}
		
		// Is called when the screen must render
		void render()
		{
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Clear colour buffer
			glClear(GL_COLOR_BUFFER_BIT);

			// Swap the screen buffers
			glfwSwapBuffers(glfwWindow);
		}
		
		// Is called whenever a key is pressed/released via GLFW
		void key_callback(int key, int scancode, int action, int mode)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				stop();
		}

		// Is called when the screen is resized
		void window_size_callback(int width, int height)
		{
			glViewport(0, 0, width, height);
		}
		
		// Is called when program has ended. Delete all resources here
		void dispose()
		{
			// Terminate GLFW, clearing any resources allocated by GLFW.
			glfwTerminate();
		}
	}
}
