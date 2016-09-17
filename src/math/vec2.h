#pragma once

#include <string>

namespace math {
	class vec2
	{
	public:
		vec2();
		vec2(float x, float y);
		
		float dot(vec2* other);
		float len();
		vec2 nor();
		vec2 rot(float angle);
		
		vec2 add(vec2* other);
		vec2 sub(vec2* other);
		vec2 mul(vec2* other);
		vec2 div(vec2* other);
		
		std::string toString();
		
		float x, y;
	};
}
