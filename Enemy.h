#pragma once
#include "BaseObject.h"

namespace Tmpl8 {
	class Enemy : public BaseObject
	{
		float enemyPosX = 0;
		float enemyPosY = 0;

		const float speed = 0.3f;

		int hp = 0;
	public:
		Enemy();

		virtual void Update();
		virtual void Draw();
	};
}

