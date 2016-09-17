#include "transform.h"

namespace math
{
	Transform::Transform()
	{
		translation = math::vec3(0.0f, 0.0f, 0.0f);
	}
	
	math::mat4 Transform::getTransformation()
	{
		math::mat4 translationMatrix = math::mat4::initTranslation(translation.x, translation.y, translation.z);
		
		return translationMatrix;
	}
}
