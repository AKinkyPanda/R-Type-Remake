#pragma once

namespace Tmpl8 {
	class EnemyBulletRed : public BaseObject
	{
		float enemyBulletPosX = 0;
		float enemyBulletPosY = 0;

		float targetX = 0;
		float targetY = 0;

		const float enemyBulletW = 17;
		const float enemyBulletH = 6;

		const float speed = 0.5f;

		const int numFrames = 4;
		const float speedAnim = 0.25f;

		float radius = 2;

		Circle enemyBulletCircle = Circle(radius, enemyBulletPosX, enemyBulletPosY);
	public:
		EnemyBulletRed();
		EnemyBulletRed(float bulletPosX, float bulletPosY, float playerPosX, float playerPosY);

		void Update(float deltaTime, float screenX);
		void Draw(Surface* screen, float deltaTime, float screenX);

		void SetEnemyBulletPosX(float posX);
		void SetEnemyBulletPosY(float posY);

		float GetEnemyBulletPosX() const;
		float GetEnemyBulletPosY() const;
		float GetEnemyBulletWidth() const;
		float GetEnemyBulletHeight() const;

		Circle GetEnemyBulletRedCircle() const;
	};
}

