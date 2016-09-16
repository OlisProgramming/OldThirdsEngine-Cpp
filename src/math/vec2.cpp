#include <cmath>

#include "vec2.h"

namespace math {
	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	
	vec2 vec2::initX()
	{
		return vec2(1.0f, 0.0f);
	}
	
	vec2 vec2::initY()
	{
		return vec2(0.0f, 1.0f);
	}
	
	vec2 vec2::initZero()
	{
		return vec2(0.0f, 0.0f);
	}
	
	float vec2::dot(vec2 other)
	{
		return x*other.x + y*other.y;
	}

	float vec2::len()
	{
		return sqrt(x*x + y*y);
	}

	std::string vec2::toString()
	{
		return "vec2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}
}
