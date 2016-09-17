#include "mesh.h"

namespace mesh
{
	Mesh::Mesh()
	{
		glGenBuffers(1, &vbo);
	}
	
	void Mesh::addVertices(float points[])
	{		
		vbo = 0;
		glGenBuffers (1, &vbo);
		glBindBuffer (GL_ARRAY_BUFFER, vbo);
		glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (float), points, GL_STATIC_DRAW);
		
		vao = 0;
		glGenVertexArrays (1, &vao);
		glBindVertexArray (vao);
		glEnableVertexAttribArray (0);
		glBindBuffer (GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	}
	
	void Mesh::render()
	{
		glBindVertexArray (vao);
		// draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawArrays (GL_TRIANGLES, 0, 3);
	}
}
