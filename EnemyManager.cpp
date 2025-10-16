#include "precomp.h"

namespace Tmpl8
{
	EnemyManager::EnemyManager()
	{

	}

	void EnemyManager::Update(float deltaTime, float screenX)
	{
		for (int i = 0; i < numEnemyShipRed; i++)
		{
			if (enemyShipRed[i] != nullptr) {
				enemyShipRed[i]->Update(deltaTime, screenX);
			}

			OffscreenEnemyShipRed(i, screenX);
			SpawnEnemyShipRed(i, screenX, deltaTime);
		}

		for(int i = 0; i < numEnemyShipYellow; i++)
		{
			if (enemyShipYellow[i] != nullptr)
			{
				enemyShipYellow[i]->Update(deltaTime, screenX);
			}

			OffscreenEnemyShipYellow(i, screenX);
			SpawnEnemyShipYellow(i, screenX, deltaTime);
		}

		spawnOffsetRedX = 30;
		spawnOffsetRedY = 10;
		spawnOffsetYellowX = 35;
	}

	void EnemyManager::Draw(Surface* screen, float deltaTime, float screenX)
	{
		for (int i = 0; i < numEnemyShipRed; i++)
		{
			if (enemyShipRed[i] != nullptr) {
				enemyShipRed[i]->Draw(screen, deltaTime, screenX);
			}
		}

		for (int i = 0; i < numEnemyShipYellow; i++)
		{
			if (enemyShipYellow[i] != nullptr) {
				enemyShipYellow[i]->Draw(screen, deltaTime, screenX);
			}
		}
	}

	void EnemyManager::OffscreenEnemyShipRed(int index, float screenX)
	{
		if (enemyShipRed[index] != nullptr && enemyShipRed[index]->GetEnemyPosX() < screenX - 30)
		{
			delete enemyShipRed[index];
			enemyShipRed[index] = nullptr;
		}
	}

	void EnemyManager::OffscreenEnemyShipYellow(int index, float screenX)
	{
		if (enemyShipYellow[index] != nullptr && enemyShipYellow[index]->GetEnemyPosX() < screenX - 30)
		{
			delete enemyShipYellow[index];
			enemyShipYellow[index] = nullptr;
		}
	}

	void EnemyManager::SpawnEnemyShipRed(int index, float screenX, float deltaTime)
	{
		if ((int)screenX % 500 == 0)
		{
			enemyShipRed[index] = new EnemyShipRed(screenX + 360 + (int)spawnOffsetRedX, (float)90 + (int)spawnOffsetRedY, 33, 24);

			spawnOffsetRedX += (index + 1) + 30;
			spawnOffsetRedY -= (index + 1) + 10;
		}
	}

	void EnemyManager::SpawnEnemyShipYellow(int index, float screenX, float deltaTime)
	{
		if ((int)screenX % 500 == 0)
		{
			enemyShipYellow[index] = new EnemyShipYellow(screenX + 360 + (int)spawnOffsetYellowX, 90, 33, 34);

			spawnOffsetYellowX += (index + 1) + 30;
		}
	}

	EnemyShipRed** EnemyManager::GetEnemyShipRed()
	{
		return enemyShipRed;
	}

	EnemyShipYellow** EnemyManager::GetEnemyShipYellow()
	{
		return enemyShipYellow;
	}

}