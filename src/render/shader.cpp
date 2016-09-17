#include <iostream>
#include <fstream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

#include "shader.h"

namespace render
{
	namespace shader
	{
		GLuint vertexShader;
		GLuint fragmentShader;
		GLuint shaderProgram;

		const char* getFileContents(const char *filename)
		{
			std::ifstream file(filename);
			std::filebuf* pbuf = file.rdbuf();
			std::size_t size = pbuf->pubseekoff(0, file.end, file.in);
			pbuf->pubseekpos(0,file.in);
			char* buffer = new char[size];
			pbuf->sgetn(buffer, size);
			file.close();
			
			return buffer;
		}

		// Shaders
		const GLchar* vertexShaderSource = getFileContents("res/basicVertex.glsl");
		const GLchar* fragmentShaderSource = getFileContents("res/basicFragment.glsl");
			
		void initVertexShader()
		{			
			// Vertex shader
			vertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			glCompileShader(vertexShader);
			// Check for compile time errors
			GLint success;
			GLchar infoLog[512];
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
		}

		void initFragmentShader()
		{
			// Fragment shader
			fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
			glCompileShader(fragmentShader);
			// Check for compile time errors
			GLint success;
			GLchar infoLog[512];
			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
		}

		void compileShaderProgram()
		{
			// Link shaders
			shaderProgram = glCreateProgram();
			glAttachShader(shaderProgram, vertexShader);
			glAttachShader(shaderProgram, fragmentShader);
			glLinkProgram(shaderProgram);
			// Check for linking errors
			GLint success;
			GLchar infoLog[512];
			glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
			if (!success) {
				glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
			}
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
		}

		void useShaderProgram()
		{
			glUseProgram(shaderProgram);
		}
	}
}
