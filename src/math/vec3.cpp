#include <cmath>

#include "vec3.h"

namespace math
{
	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float vec3::dot(vec3* other)
	{
		return x * other-> x + y * other-> y + z * other->z;
	}

	float vec3::len()
	{
		return sqrt(x*x + y*y + z*z);
	}

	vec3 vec3::nor()
	{
		float l = len();
		return vec3(x/l, y/l, z/l);
	}

	vec3 vec3::rot(float angle, vec3 axis)
	{
		return vec3(); // TODO, it needs quaternions which are as yet unimplemented
	}

	vec3 vec3::crs(vec3* other)
	{
		float x_ = y * other->z - z * other->y;
		float y_ = z * other->x - x * other->z;
		float z_ = x * other->y - y * other->x;
		return vec3(x_, y_, z_);
	}

	vec3 vec3::add(vec3* other)
	{
		return vec3(x+other->x, y+other->y, z+other->z);
	}

	vec3 vec3::sub(vec3* other)
	{
		return vec3(x-other->x, y-other->y, z-other->z);
	}

	vec3 vec3::mul(vec3* other)
	{
		return vec3(x*other->x, y*other->y, z*other->z);
	}

	vec3 vec3::div(vec3* other)
	{
		return vec3(x/other->x, y/other->y, z/other->z);
	}

	vec3 vec3::abs()
	{
		return vec3(std::abs(x), std::abs(y), std::abs(z));
	}

	std::string vec3::toString()
	{
		return "vec3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}
}
