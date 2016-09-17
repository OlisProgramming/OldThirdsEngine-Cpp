#pragma once

#include "vec3.h"
#include "mat4.h"

namespace math
{
	class Transform
	{
	public:
		math::vec3 translation;
		
		Transform();
		
		math::mat4 getTransformation();
	};
}
