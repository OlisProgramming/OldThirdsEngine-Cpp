#pragma once

#include <string>

#include "quat.h"

namespace math
{
	class vec3
	{
	public:
		vec3();
		vec3(float x, float y, float z);

		float dot(vec3* other);
		float len();
		vec3 nor();
		vec3 rot(float angle, vec3 axis);

		vec3 crs(vec3* other);
		
		vec3 add(vec3* other);
		vec3 sub(vec3* other);
		vec3 mul(vec3* other);
		vec3 div(vec3* other);

		vec3 abs();
		quat toQuat();
		std::string toString();

		float x;
		float y;
		float z;
	};
}
