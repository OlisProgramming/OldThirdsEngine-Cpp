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

		mat4 mul(mat4* other);

		std::string toString();
	};
}
