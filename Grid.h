#pragma once

constexpr int gridW = 24;
constexpr int gridH = 12;
constexpr int gridSize = gridW * gridH;

namespace Tmpl8 {
	class Grid : public Cell
	{
		Cell* cells[gridH][gridW];
		Pixel colour = 0xFFFFFFFF;

		float ESRFrameSpeed = 0.05f;
		int ESRnumFrames = 6;
		int animIter = 0;
		float animPosX[numEnemyShipRed + numEnemyShipYellow];
		float animPosY[numEnemyShipRed + numEnemyShipYellow];

		CollisionHandler collisionHandler;

	public:
		Grid();
		~Grid();

		void HandleCollision(Surface* screen, float deltaTime, AABB a, AABB b, Circle c, Circle d, Player& player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain);

		void HandleCell(int x, int y, Surface* screen, float deltaTime, AABB a, AABB b, Circle c, Circle d, Player& player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain);
		void HandleUnit(vec2* unit, vec2* other[], int iterator, Surface* screen, float deltaTime, AABB a, AABB b, Circle c, Circle d, Player& player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain);

		void UpdateUnit(Player& player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain) override;

		void Draw(Surface* screen, float deltaTime, Terrain& terrain);
	};
}

