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
}
