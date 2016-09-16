#pragma once

namespace render
{
	class Window
	{
	public:
		GLFWwindow* glfwWindow;
		
		Window(int width, int height, char* title);
		~Window();
		
		void start();
		//void stop();
		
	private:
		//void render();
		//void update();
		
		//void dispose();
	};
}
