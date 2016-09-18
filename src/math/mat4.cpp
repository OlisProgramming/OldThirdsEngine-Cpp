#include "mat4.h"

#include <cmath>
#include "util.h"

namespace math
{
	mat4::mat4()
	{
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				m[i][j] = 0.0f;
	}
	
	mat4 mat4::initTranslation(float x, float y, float z)
	{
		mat4 out = mat4();
		out.m[0][0] = 1.0f;
		out.m[1][1] = 1.0f;
		out.m[2][2] = 1.0f;
		out.m[3][3] = 1.0f;
		out.m[0][3] = x;
		out.m[1][3] = y;
		out.m[2][3] = z;
		return out;
	}
	
	mat4 mat4::initRotation(float x, float y, float z)
	{
		mat4 rx = mat4();
		mat4 ry = mat4();
		mat4 rz = mat4();
		
		x *= DEG_TO_RAD;
		y *= DEG_TO_RAD;
		z *= DEG_TO_RAD;
		
		float sx = (float)sin(x);
		float sy = (float)sin(y);
		float sz = (float)sin(z);
		float cx = (float)cos(x);
		float cy = (float)cos(y);
		float cz = (float)cos(z);
		
		rz.m[0][0] = cz;
		rz.m[0][1] = -sz;
		rz.m[1][0] = sz;
		rz.m[1][1] = cz;
		rz.m[2][2] = 1;
		rz.m[3][3] = 1;
		
		rx.m[0][0] = 1;
		rx.m[1][1] = cx;
		rx.m[1][2] = -sx;
		rx.m[2][1] = sx;
		rx.m[2][2] = cx;
		rx.m[3][3] = 1;
		
		ry.m[0][0] = cy;
		ry.m[0][2] = -sy;
		ry.m[1][1] = 1;
		ry.m[2][0] = sy;
		ry.m[2][2] = cy;
		ry.m[3][3] = 1;
		
		return rz.mul(ry.mul(rx));
	}
	
	mat4 mat4::initScale(float x, float y, float z)
	{
		mat4 out = mat4();
		out.m[0][0] = x;
		out.m[1][1] = y;
		out.m[2][2] = z;
		out.m[3][3] = 1.0f;
		return out;
	}

	mat4 mat4::mul(mat4 other)
	{
		mat4 out = mat4();
		
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				out.m[i][j] =
					m[i][0] * other.m[0][j] +
					m[i][1] * other.m[1][j] +
					m[i][2] * other.m[2][j] +
					m[i][3] * other.m[3][j];
		
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
