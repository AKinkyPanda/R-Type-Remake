#include "precomp.h"

namespace Tmpl8
{
	Collision::Collision()
	{
	}

	bool Collision::AABBvAABB(AABB a, AABB b)
	{
		const float d1x = b.min.x - a.max.x;
		const float d1y = b.min.y - a.max.y;
		const float d2x = a.min.x - b.max.x;
		const float d2y = a.min.y - b.max.y;

		if (d1x > 0.0f || d1y > 0.0f)
			return false;

		if (d2x > 0.0f || d2y > 0.0f)
			return false;

		return true;
	}

	bool Collision::AABBvCircle(AABB a, Circle b)
	{
		vec2 distance = vec2(b.center() - a.center());
		//Clamp
		const vec2 clampDist = ClampV(distance, -a.Bounds(), a.Bounds());
		const vec2 closestPoint = a.center() + clampDist;

		distance = closestPoint - b.center();
		if (distance.length() < b.radius)
		{
			return true;
		}
		return false;
	}

	bool Collision::CirclevCircle(Circle a, Circle b) const
	{
		const float distX = a.center().x - b.center().x;
		const float distY = a.center().y - b.center().y;
		const float distance = distX * distX + distY * distY;

		if (distance <= (a.radius + b.radius) * (a.radius + b.radius)) {
			return true;
		}
		return false;
	}


	vec2 Collision::ClampV(vec2 dist, vec2 min, vec2 max)
	{
		float x = dist.x;
		x = (x > max.x) ? max.x : x;
		x = (x < min.x) ? min.x : x;

		float y = dist.y;
		y = (y > max.y) ? max.y : y;
		y = (y < min.y) ? min.y : y;

		return vec2(x, y);
	}


}