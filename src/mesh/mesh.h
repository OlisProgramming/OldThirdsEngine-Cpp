#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

namespace mesh
{
	class Mesh
	{
	public:
		Mesh();
		void addVertices(float points[]);
		void render();
	
	private:
		GLuint vbo, vao;
		int vertexSize;
		int verticesLength;
	};
}
