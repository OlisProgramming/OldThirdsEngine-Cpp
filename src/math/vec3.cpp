#include <cmath>

#include "vec3.h"
#include "util.h"

namespace math
{
	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float vec3::dot(vec3* other)
	{
		return x * other-> x + y * other-> y + z * other->z;
	}

	float vec3::len()
	{
		return sqrt(x*x + y*y + z*z);
	}

	vec3 vec3::nor()
	{
		float l = len();
		return vec3(x/l, y/l, z/l);
	}

	vec3 vec3::rot(float angle, vec3 axis)
	{
		float sinHalfAngle = (float)sin(angle/2 * DEG_TO_RAD);
		float cosHalfAngle = (float)cos(angle/2 * DEG_TO_RAD);
		
		float rX = axis.x * sinHalfAngle;
		float rY = axis.y * sinHalfAngle;
		float rZ = axis.z * sinHalfAngle;
		float rW = cosHalfAngle;
		
		quat rotation = quat(rX, rY, rZ, rW);
		quat conjugate = rotation.con();
		quat thisQuat = this->toQuat();
		quat w = rotation.mul(&thisQuat).mul(&conjugate);
		
		return vec3(w.x, w.y, w.z);
	}

	vec3 vec3::crs(vec3* other)
	{
		float x_ = y * other->z - z * other->y;
		float y_ = z * other->x - x * other->z;
		float z_ = x * other->y - y * other->x;
		return vec3(x_, y_, z_);
	}

	vec3 vec3::add(vec3* other)
	{
		return vec3(x+other->x, y+other->y, z+other->z);
	}

	vec3 vec3::sub(vec3* other)
	{
		return vec3(x-other->x, y-other->y, z-other->z);
	}

	vec3 vec3::mul(vec3* other)
	{
		return vec3(x*other->x, y*other->y, z*other->z);
	}

	vec3 vec3::div(vec3* other)
	{
		return vec3(x/other->x, y/other->y, z/other->z);
	}

	vec3 vec3::abs()
	{
		return vec3(std::abs(x), std::abs(y), std::abs(z));
	}

	quat vec3::toQuat()
	{
		return quat(x, y, z, 0.0f);
	}

	std::string vec3::toString()
	{
		return "vec3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}
}
