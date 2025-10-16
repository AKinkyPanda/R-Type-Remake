#include "precomp.h"

namespace Tmpl8
{
	CollisionHandler::CollisionHandler()
	{
		
	}

	void CollisionHandler::PlayerVEnemyRed(Surface* screen, AABB a, AABB b, Player& player, EnemyShipRed* enemyShipRed[], Terrain& terrain, float deltaTime)
	{
		for (int i = 0; i < numEnemyShipRed; i++) {
			if (enemyShipRed[i] != nullptr && 
				col.AABBvAABB(a, enemyShipRed[i]->GetEnemyShipRedAABB()))
			{
				tempX = enemyShipRed[i]->GetEnemyPosX();
				tempY = enemyShipRed[i]->GetEnemyPosY();

				delete enemyShipRed[i];
				enemyShipRed[i] = nullptr;

				isColliding = true;
			}
		}
	}

	void CollisionHandler::PlayerVEnemyYellow(Surface* screen, AABB a, Circle b, Player& player, EnemyShipYellow* enemyShipYellow[], Terrain& terrain, float deltaTime)
	{
		for (int i = 0; i < numEnemyShipYellow; i++)
		{
			if (enemyShipYellow[i] != nullptr)
			{
				if (col.AABBvCircle(a, enemyShipYellow[i]->GetEnemyShipYellowCircle()))
				{
					tempX = enemyShipYellow[i]->GetEnemyPosX();
					tempY = enemyShipYellow[i]->GetEnemyPosY();

					delete enemyShipYellow[i];
					enemyShipYellow[i] = nullptr;

					isColliding = true;
				}
			}
		}
	}


	void CollisionHandler::ProjectileVEnemyRed(Surface* screen, AABB a, Circle b, EnemyShipRed* enemyShipRed[], PlayerBullet* playerBullets[], Terrain& terrain, float deltaTime)
	{
		for (int i = 0; i < numEnemyShipRed; i++) {
			if (enemyShipRed[i] != nullptr)
			{
				for (int j = 0; j < numBullets; j++)
				{
					if (playerBullets[j] != nullptr &&
						enemyShipRed[i] != nullptr &&
						col.AABBvCircle(enemyShipRed[i]->GetEnemyShipRedAABB(), playerBullets[j]->GetBulletCircle()))
					{
						tempX = enemyShipRed[i]->GetEnemyPosX();
						tempY = enemyShipRed[i]->GetEnemyPosY();

						delete enemyShipRed[i];
						enemyShipRed[i] = nullptr;

						if (playerBullets[j]->state == PlayerBullet::NORMAL) {
							delete playerBullets[j];
							playerBullets[j] = nullptr;
						}

						isColliding = true;
					}
				}
			}
		}
	}

	void CollisionHandler::ProjectileVEnemyYellow(Surface* screen, Circle a, Circle b, EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullets[], Terrain& terrain, float deltaTime)
	{
		for (int i = 0; i < numEnemyShipYellow; i++) {
			if (enemyShipYellow[i] != nullptr)
			{
				for (int j = 0; j < numBullets; j++)
				{
					if (playerBullets[j] != nullptr &&
						enemyShipYellow[i] != nullptr &&
						col.CirclevCircle(playerBullets[j]->GetBulletCircle(), enemyShipYellow[i]->GetEnemyShipYellowCircle()))
					{
						tempX = enemyShipYellow[i]->GetEnemyPosX();
						tempY = enemyShipYellow[i]->GetEnemyPosY();

						delete enemyShipYellow[i];
						enemyShipYellow[i] = nullptr;

						if (playerBullets[j]->state == PlayerBullet::NORMAL) {
							delete playerBullets[j];
							playerBullets[j] = nullptr;
						}

						isColliding = true;
					}
				}
			}
		}
	}


	void CollisionHandler::ProjectileVPlayer(Surface* screen, AABB a, Circle b, Player& player, EnemyBulletRed* enemyBulletsRed[], Terrain& terrain, float deltaTime)
	{
		for (int i = 0; i < numEnemyBulletsRed * numEnemyShipRed; i++)
		{
			if (enemyBulletsRed[i] != nullptr 
				&& col.AABBvCircle(a, enemyBulletsRed[i]->GetEnemyBulletRedCircle()))
			{
				player.lives -= 1;

				delete enemyBulletsRed[i];
				enemyBulletsRed[i] = nullptr;
			}
		}
	}

	bool CollisionHandler::GetIsColliding() const
	{
		return isColliding;
	}

	float CollisionHandler::GetTempX() const
	{
		return tempX;
	}

	float CollisionHandler::GetTempY() const
	{
		return tempY;
	}

	void CollisionHandler::SetIsColliding(bool state)
	{
		isColliding = state;
	}

}
