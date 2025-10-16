#include "precomp.h"

namespace Tmpl8
{
	Circle::Circle(float radius, float x, float y)
	{
		this->radius = radius;
		this->x = x;
		this->y = y;
	}

	vec2 Circle::center()
	{
		vec2 i = vec2((x + x + radius + radius) / 2, (y + y + radius + radius) / 2);
		return i;
	}

}