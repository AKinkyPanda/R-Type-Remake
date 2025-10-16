#pragma once
#include "template.h"

namespace Tmpl8{
	class Circle
	{
	public:
		Circle(float radius, float x, float y);

		float radius = 0;
		float x = 0;
		float y = 0;

		vec2 center();
	};
}

