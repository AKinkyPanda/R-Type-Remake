#pragma once

namespace Tmpl8 {
	class BaseObject
	{
	public:
		float posX = 0;
		float posY = 0;

		void Update(float deltaTime);
		void Draw(Surface* screen);
	};
}

