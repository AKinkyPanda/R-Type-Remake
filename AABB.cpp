#include "precomp.h"

namespace Tmpl8
{
	AABB::AABB(float x, float y, float width, float height)
	{
		this->min = vec2(x, y);
		this->max = vec2(x + width, y + height);
	}

	vec2 AABB::center()
	{
		vec2 i = vec2(min.x + (max.x - min.x) / 2, min.y + (max.y - min.y) / 2);
		return i;
	}

	vec2 AABB::Bounds()
	{
		vec2 i = vec2(max.x - min.x, max.y - min.y);
		return i;
	}


}
