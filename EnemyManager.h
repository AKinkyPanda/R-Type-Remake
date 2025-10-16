#pragma once
#include "EnemyShipRed.h"
#include "EnemyShipYellow.h"

constexpr int numEnemyShipRed = 5;
constexpr int numEnemyShipYellow = 5;

namespace Tmpl8 {
	class EnemyManager : public EnemyShipRed
	{
	private:
		EnemyShipRed* enemyShipRed[numEnemyShipRed];
		EnemyShipYellow* enemyShipYellow[numEnemyShipYellow];

		int spawnOffsetRedX = 30;
		int spawnOffsetRedY = 10;

		int spawnOffsetYellowX = 35;

	public:
		EnemyManager();

		void Update(float deltaTime, float screenX) override;
		void Draw(Surface* screen, float deltaTime, float screenX) override;

		void OffscreenEnemyShipRed(int index, float screenX);
		void OffscreenEnemyShipYellow(int index, float screenX);
		void SpawnEnemyShipRed(int index, float screenX, float deltaTime);
		void SpawnEnemyShipYellow(int index, float screenX, float deltaTime);

		EnemyShipRed** GetEnemyShipRed();
		EnemyShipYellow** GetEnemyShipYellow();
	};
}

