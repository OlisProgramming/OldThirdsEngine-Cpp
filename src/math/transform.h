#pragma once

#include "vec3.h"
#include "mat4.h"

namespace math
{
	class Transform
	{
	public:
		math::vec3 translation;
		math::vec3 rotation;
		math::vec3 scale;
		
		Transform();
		
		math::mat4 getTransformation();
	};
}
