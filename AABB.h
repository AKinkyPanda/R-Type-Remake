#pragma once

namespace Tmpl8 {
	class AABB
	{
	public:
		AABB(float x, float y, float width, float height);

		vec2 min;
		vec2 max;

		vec2 center();
		vec2 Bounds();
	};
}

