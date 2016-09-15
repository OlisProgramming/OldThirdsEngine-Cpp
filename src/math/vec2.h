#include <iostream>

namespace math {
	class vec2
	{
	public:
		vec2();
		vec2(float x, float y);
		
		float len();
		
		std::string toString();
		
		float x, y;
	};
	
	const vec2 VEC2_X = vec2(1.0f, 0.0f);
	const vec2 VEC2_Y = vec2(0.0f, 1.0f);
	const vec2 VEC2_ZERO = vec2();
}
