#pragma once
#include "Circle.h"
#include "surface.h"

namespace Tmpl8 {

	class PlayerBullet :  public Circle, public BaseObject
	{
		float bulletPosX = 0;
		float bulletPosY = 0;

		const int offsetX = 28;
		const int offsetY = 6;

		float bulletW = 8;
		float bulletH = 4;

		float speed = 1.5f;

		float radiusN = 2;
		float radiusCh1 = 4;
		float radiusCh2 = 6;
		float radiusCh3 = 8;
		float radiusCh4 = 12;
		float radiusCh5 = 14;

		Circle playerBulletCircle = Circle(radius, bulletPosX, bulletPosY);
	public:
		PlayerBullet();

		enum  State { NORMAL, CHARGE1, CHARGE2, CHARGE3, CHARGE4, CHARGE5 };
		State state = NORMAL;

		void Update(float deltaTime, float screenX);
		void Draw(Surface* a_Target, float deltaTime, float screenX);

		void SetBulletPosX(float position);
		void SetBulletPosY(float position);
		void SetBulletWidth(float width);
		void SetBulletHeight(float height);
		void SetBulletState(State state);

		float GetBulletPosX() const;
		float GetBulletPosY() const;
		float GetBulletWidth() const;
		float GetBulletHeight() const;
		const Circle GetBulletCircle() const;
	};
};

