#include "mat4.h"

namespace math
{
	mat4::mat4()
	{
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				m[i][j] = 0.0f;
	}

	mat4 mat4::mul(mat4* other)
	{
		mat4 out = mat4();
		
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				out.m[i][j] =
					m[i][0] * other->m[0][j] +
					m[i][1] * other->m[1][j] +
					m[i][2] * other->m[2][j] +
					m[i][3] * other->m[3][j];
		
		return out;
	}

	std::string mat4::toString()
	{
		return
		"(" + std::to_string(m[0][0]) + ", " + std::to_string(m[0][1]) + ", " + std::to_string(m[0][2]) + ", " + std::to_string(m[0][3]) + ")\n"
		"(" + std::to_string(m[1][0]) + ", " + std::to_string(m[1][1]) + ", " + std::to_string(m[1][2]) + ", " + std::to_string(m[1][3]) + ")\n"
		"(" + std::to_string(m[2][0]) + ", " + std::to_string(m[2][1]) + ", " + std::to_string(m[2][2]) + ", " + std::to_string(m[2][3]) + ")\n"
		"(" + std::to_string(m[3][0]) + ", " + std::to_string(m[3][1]) + ", " + std::to_string(m[3][2]) + ", " + std::to_string(m[3][3]) + ")";
	}
}
