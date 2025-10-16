#pragma once
#include "AABB.h"

namespace Tmpl8 {
	class Collision
	{
	public:
		Collision();

		bool AABBvAABB(AABB a, AABB b);
		bool AABBvCircle(AABB a, Circle b);
		bool CirclevCircle(Circle a, Circle b) const;

		vec2 ClampV(vec2 dist, vec2 min, vec2 max);
	};
}

