#pragma once
#include "Collision.h"
#include "EnemyManager.h"

namespace Tmpl8 {
	class CollisionHandler : public Collision
	{
		bool isColliding = false;

		float tempX = 0;
		float tempY = 0;

		Collision col;
	public:
		CollisionHandler();

		void PlayerVEnemyRed(Surface* screen, AABB a, AABB b, Player &player, EnemyShipRed* enemyShipRed[], Terrain& terrain, float deltaTime);
		void PlayerVEnemyYellow(Surface* screen, AABB a, Circle b, Player& player, EnemyShipYellow* enemyShipYellow[], Terrain& terrain, float deltaTime);
		void ProjectileVEnemyRed(Surface* screen, AABB a, Circle b, EnemyShipRed* enemyShipRed[], PlayerBullet* playerBullets[], Terrain& terrain, float deltaTime);
		void ProjectileVEnemyYellow(Surface* screen, Circle a, Circle b, EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullets[], Terrain& terrain, float deltaTime);
		void ProjectileVPlayer(Surface* screen, AABB a, Circle b, Player& player, EnemyBulletRed* enemyBulletsRed[], Terrain& terrain, float deltaTime);

		bool GetIsColliding() const;
		float GetTempX() const;
		float GetTempY() const;

		void SetIsColliding(bool state);
	};
}

