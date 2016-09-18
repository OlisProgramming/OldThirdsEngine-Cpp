#include "transform.h"

namespace math
{
	Transform::Transform()
	{
		translation = math::vec3(0.0f, 0.0f, 0.0f);
		rotation = math::vec3(0.0f, 0.0f, 0.0f);
		scale = math::vec3(0.0f, 0.0f, 0.0f);
	}
	
	math::mat4 Transform::getTransformation()
	{
		math::mat4 translationMatrix = math::mat4::initTranslation(translation.x, translation.y, translation.z);
		math::mat4 rotationMatrix = math::mat4::initRotation(rotation.x, rotation.y, rotation.z);
		math::mat4 scaleMatrix = math::mat4::initScale(scale.x, scale.y, scale.z);
		
		return translationMatrix.mul(rotationMatrix.mul(scaleMatrix));
	}
}
