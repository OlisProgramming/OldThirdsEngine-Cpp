#pragma once

namespace render
{
	namespace shader
	{
		// Notice that getFileContents is NOT in header file
		void initVertexShader();
		void initFragmentShader();
		void compileShaderProgram();
		void useShaderProgram();
		
		void addUniform(char* uniform);
		// Overload for each uniform type
		void setUniform(char* uniform, float value);
	}
}
