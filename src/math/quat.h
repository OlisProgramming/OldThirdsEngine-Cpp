#pragma once

namespace math
{
	class quat
	{
		float x;
		float y;
		float z;
		float w;

		quat();
		quat(float x, float y, float z, float w);

		float len();
		quat con();
		quat mul(quat* other);
	};
}
