#include <iostream>

namespace math {
	class vec2
	{
	public:
		vec2();
		vec2(float x, float y);
		
		static vec2 initX();
		static vec2 initY();
		static vec2 initZero();
		
		float dot(vec2 other);
		float len();
		
		std::string toString();
		
		float x, y;
	};
}
