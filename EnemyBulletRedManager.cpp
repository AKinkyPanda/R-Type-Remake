#include "precomp.h"

namespace Tmpl8
{
	EnemyBulletRedManager::EnemyBulletRedManager()
	{
		for (int i = 0; i < numEnemyBulletsRed * numEnemyShipRed; i++)
		{
			enemyBulletsRed[i] = nullptr;
		}
	}

	void EnemyBulletRedManager::Update(float deltaTime, float screenX, Player& player, EnemyShipRed* enemyShipsRed[])
	{
		for (int j = 0; j < numEnemyBulletsRed * numEnemyShipRed; j++)
		{
			if (enemyBulletsRed[j] != nullptr)
			{
				enemyBulletsRed[j]->Update(deltaTime, screenX);
			}
		}
	}

	void EnemyBulletRedManager::Fired(Player& player, EnemyShipRed* enemyShipsRed[])
	{
		for (int i = 0; i < numEnemyShipRed; i++)
		{
			if (enemyShipsRed[i] != nullptr && enemyShipsRed[i]->GetEnemyFireState() == true)
			{
				enemyBulletsRed[bulletCnt] = new EnemyBulletRed(enemyShipsRed[i]->GetEnemyPosX(), enemyShipsRed[i]->GetEnemyPosY(), player.GetPlayerPosX(), player.GetPlayerPosY());

				if (bulletCnt == numEnemyBulletsRed * numEnemyShipRed - 1)
				{
					bulletCnt = 0;
				}

				bulletCnt++;

				enemyShipsRed[i]->SetFireState(false);
			}
		}
	}

	void EnemyBulletRedManager::Draw(Surface* screen, float deltaTime, float screenX)
	{
		for (int i = 0; i < numEnemyBulletsRed * numEnemyShipRed; i++)
		{
			if (enemyBulletsRed[i] != nullptr) 
			{
				enemyBulletsRed[i]->Draw(screen, deltaTime, screenX);
			}
		}
	}

	EnemyBulletRed** EnemyBulletRedManager::GetEnemyBulletRed()
	{
		return enemyBulletsRed;
	}

}