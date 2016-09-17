#include <cmath>

#include "util.h"
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
	
	float vec2::dot(vec2* other)
	{
		return x*other->x + y*other->y;
	}

	float vec2::len()
	{
		return sqrt(x*x + y*y);
	}
	
	vec2 vec2::nor()
	{
		float l = len();
		return vec2(x/l, y/l);
	}
	
	vec2 vec2::rot(float angle) {
		
		double rad = (double)angle * DEG_TO_RAD;
		double c = cos(rad);
		double s = sin(rad);
		
		return vec2((float)(x*c - y*s), (float)(x*s + y*c));
	}
	
	vec2 vec2::add(vec2* other)
	{
		return vec2(x+other->x, y+other->y);
	}
	
	vec2 vec2::sub(vec2* other)
	{
		return vec2(x-other->x, y-other->y);
	}
	
	vec2 vec2::mul(vec2* other)
	{
		return vec2(x*other->x, y*other->y);
	}
	
	vec2 vec2::div(vec2* other)
	{
		return vec2(x/other->x, y/other->y);
	}

	std::string vec2::toString()
	{
		return "vec2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}
}
