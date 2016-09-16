#include <iostream>

// GLFW
#include <GLFW/glfw3.h>

#include "math/math.h"
#include "render/render.h"

// Function prototypes
void key_callback(GLFWwindow* glfwWindow, int key, int scancode, int action, int mode);
void window_size_callback(GLFWwindow* glfwWindow, int width, int height);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{
	std::cout << std::endl << std::endl << "******" << std::endl << "Thirds Engine Start" << std::endl << "******" << std::endl << std::endl;
	
	render::window::init(WIDTH, HEIGHT, (char*)"Thirds Engine | Version 0.1");
	
	// Set the required callback functions
	glfwSetKeyCallback(render::window::glfwWindow, key_callback);
	glfwSetWindowSizeCallback(render::window::glfwWindow, window_size_callback);
	
	// Start main loop
	render::window::start();
    
    std::cout << std::endl << std::endl << "******" << std::endl << "Thirds Engine End" << std::endl << "******" << std::endl << std::endl;
    
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* glfwWindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(glfwWindow, GL_TRUE);
}

// Is called when the screen is resized
void window_size_callback(GLFWwindow* glfwWindow, int width, int height)
{
    glViewport(0, 0, width, height);
}
