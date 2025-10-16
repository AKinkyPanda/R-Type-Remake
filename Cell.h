#pragma once

namespace Tmpl8 {
	class Cell
	{
		friend class Grid;

		float posX, posY;
		Grid* grid;

		Cell* next;
		Cell* prev;

		vec2* unit[1 + numBullets + numEnemyShipRed + numEnemyBullets * numEnemyShipRed + numEnemyShipYellow];

	public:
		Cell();
		Cell(Grid* grid, float x, float y);
		~Cell();

		virtual void UpdateUnit(Player &player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain);

		void Draw(Surface* screen, float posX, float posY, Pixel colour);
	};
}

