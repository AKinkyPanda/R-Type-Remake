#include "precomp.h"

namespace Tmpl8 {
	Cell::Cell()
	{

	}

	Cell::Cell(Grid* grid, float x, float y)
		: grid(grid)
	{
		grid = nullptr;
		posX = x;
		posY = y;

	}

	Cell::~Cell()
	{
		delete grid;

		delete next;
		delete prev;

		delete[] unit;
	}

	void Cell::UpdateUnit(Player& player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain &terrain)
	{
		
	}

	void Cell::Draw(Surface* screen, float posX, float posY, Pixel colour)
	{
		screen->Box((int)posX, (int)posY, (int)posX + 16, (int)posY + 16, colour);
	}
}