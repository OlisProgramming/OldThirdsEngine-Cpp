#pragma once

#include <string>

namespace math
{
	class mat4
	{
	public:
		// M for Matrix
		float m[4][4];

		mat4();
		static mat4 initTranslation(float x, float y, float z);
		static mat4 initRotation(float x, float y, float z);
		static mat4 initScale(float x, float y, float z);

		mat4 mul(mat4 other);

		std::string toString();
	};
}
