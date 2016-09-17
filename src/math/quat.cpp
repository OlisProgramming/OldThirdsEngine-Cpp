#include <cmath>

#include "quat.h"

namespace math
{
	quat::quat()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	quat::quat(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	float quat::len()
	{
		return sqrt(x*x + y*y + z*z + w*w);
	}

	quat quat::con()
	{
		return quat(-x, -y, -z, w);
	}

	quat quat::mul(quat* other)
	{
		float w_ = w*other->w - x*other->x - y*other->y - z*other->z;
		float x_ = x*other->w + w*other->x + y*other->z - z*other->y;
		float y_ = y*other->w + w*other->y + z*other->x - x*other->z;
		float z_ = z*other->w + w*other->z + x*other->y - y*other->x;
		
		return new Quaternion(x_, y_, z_, w_);
	}
}
