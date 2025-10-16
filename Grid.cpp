#include "precomp.h"

namespace Tmpl8
{
	Sprite* ESRDeath = new Sprite(new Surface("assets/ESR-death.tga"), 6);
	Animation* enemyDemolition[numEnemyShipRed + numEnemyShipYellow];

	Grid::Grid()
	{
		for (int i = 0; i < gridH; i++)
		{
			for (int j = 0; j < gridW; j++)
			{
				cells[i][j] = nullptr;
			}
		}

		for (int i = 0; i < numEnemyShipRed + numEnemyShipYellow; i++)
		{
			enemyDemolition[i] = nullptr;
		}
	}

	Grid::~Grid()
	{
		for (int i = 0; i < gridH; i++)
		{
			for (int j = 0; j < gridW; j++)
			{
				delete cells[i][j];
				cells[i][j] = nullptr;
			}
		}
	}

	void Grid::HandleCollision(Surface* screen, float deltaTime, AABB a, AABB b, Circle c, Circle d, Player& player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain)
	{
		for ( int y = 0; y < gridH; y++ )
		{
			for ( int x = 0; x < gridW; x++ )
			{
				HandleCell(y, x, screen, deltaTime, a, b, c, d, player, enemyShipRed, enemyShipYellow, playerBullet, enemyBulletRed, terrain);
			}
		}
	}

	void Grid::HandleCell(int x, int y, Surface* screen, float deltaTime, AABB a, AABB b, Circle c, Circle d, Player& player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain)
	{
		UpdateUnit(player, enemyShipRed, enemyShipYellow, playerBullet, enemyBulletRed, terrain);
		for (int i = 0; i < 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed + numEnemyShipYellow; i++)
		{
			HandleUnit(unit[i], unit, i, screen, deltaTime, a, b, c, d, player, enemyShipRed, enemyShipYellow, playerBullet, enemyBulletRed, terrain);
		}
	}

	void Grid::HandleUnit(vec2* unit, vec2* other[], int iterator, Surface* screen, float deltaTime, AABB a, AABB b, Circle c, Circle d, Player& player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain)
	{
		for (int i = 0; i < 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed + numEnemyShipYellow; i++)
		{
			if (other[i] != nullptr && unit != nullptr)
			{
				if (iterator == 0 &&
					(int)other[i]->x == (int)unit->x &&
					i > 0 &&
					i < 1 + numEnemyShipRed)
				{
					collisionHandler.PlayerVEnemyRed(screen, a, b, player, enemyShipRed, terrain, deltaTime);
				}

				if (iterator == 0 &&
					(int)other[i]->x == (int)unit->x &&
					(int)other[i]->y == (int)unit->y &&
					i > numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed &&
					i < 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed + numEnemyShipYellow)
				{
					collisionHandler.PlayerVEnemyYellow(screen, a, d, player, enemyShipYellow, terrain, deltaTime);
				}

				if (iterator >= 1 + numEnemyShipRed &&
					iterator < 1 + numEnemyShipRed + numBullets &&
					(int)other[i]->x == (int)unit->x &&
					i < 1 + numEnemyShipRed &&
					i > 0)
				{
					collisionHandler.ProjectileVEnemyRed(screen, b, c, enemyShipRed, playerBullet, terrain, deltaTime);
				}

				if (iterator >= 1 + numEnemyShipRed &&
					iterator < 1 + numEnemyShipRed + numBullets &&
					(int)other[i]->x == (int)unit->x &&
					i < 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed + numEnemyShipYellow &&
					i >= 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed)
				{
					collisionHandler.ProjectileVEnemyYellow(screen, c, d, enemyShipYellow, playerBullet, terrain, deltaTime);
				}

				if ( iterator == 0 &&
					(int)other[i]->x == (int)unit->x &&
					i >= 1 + numBullets + numEnemyShipRed &&
					i < 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed)
				{
					collisionHandler.ProjectileVPlayer(screen, a, c, player, enemyBulletRed, terrain, deltaTime);
				}
			}
		}
	}

	void Grid::UpdateUnit(Player &player, EnemyShipRed* enemyShipRed[], EnemyShipYellow* enemyShipYellow[], PlayerBullet* playerBullet[], EnemyBulletRed* enemyBulletRed[], Terrain& terrain)
	{
		int enemyRIter = 0;
		int enemyYIter = 0;
		int bulletIter = 0;
		int enemyBulletIter = 0;

		for (int i = 0; i < 1 + numBullets + numEnemyShipRed + numEnemyBulletsRed * numEnemyShipRed + numEnemyShipYellow; i++)
		{
			if (i == 0)
			{
				delete unit[i];
				unit[i] = nullptr;
				unit[i] = new vec2((float)(((int)player.GetPlayerPosX() + (int)player.playerW / 2 - (int)terrain.GetScreenX()) / 16), (float)(((int)player.GetPlayerPosY() + (int)player.playerH / 2) / 16));
			}

			if (i > 0 && i < 1 + numEnemyShipRed &&
				enemyShipRed[enemyRIter] != nullptr &&
				(enemyShipRed[enemyRIter]->GetEnemyPosX() - terrain.GetScreenX()) / 16 >= 0)
			{
				delete unit[i];
				unit[i] = nullptr;
				unit[i] = new vec2((float)((int)((enemyShipRed[enemyRIter]->GetEnemyPosX() + enemyShipRed[enemyRIter]->GetEnemyWidth() / 2 - terrain.GetScreenX()) / 16)), (float)((int)(((int)enemyShipRed[enemyRIter]->GetEnemyPosY() + enemyShipRed[enemyRIter]->GetEnemyHeight() / 2) / 16)));
				enemyRIter++;
			}else if (i > 0 && i < 1 + numEnemyShipRed)
			{
				delete unit[i];
				unit[i] = nullptr;
				enemyRIter++;
			}

			if (i >= 1 + numEnemyShipRed &&
				i < 1 + numEnemyShipRed + numBullets &&
				playerBullet[bulletIter] != nullptr)
			{
				delete unit[i];
				unit[i] = nullptr;
				unit[i] = new vec2(((float)((int)(playerBullet[bulletIter]->GetBulletPosX() + playerBullet[bulletIter]->GetBulletWidth() - terrain.GetScreenX()) / 16)), (float)((int)((playerBullet[bulletIter]->GetBulletPosY() + playerBullet[bulletIter]->GetBulletHeight() / 2) / 16)));
				bulletIter++;
			} else if (i > numEnemyShipRed &&
				i < 1 + numBullets + numEnemyShipRed)
			{
				delete unit[i];
				unit[i] = nullptr;
				bulletIter++;
			}

			if (i >= 1 + numEnemyShipRed + numBullets &&
				i < 1 + numEnemyShipRed + numBullets + numEnemyBullets * numEnemyShipRed &&
				enemyBulletRed[enemyBulletIter] != nullptr)
			{
				delete unit[i];
				unit[i] = nullptr;
				unit[i] = new vec2((float)((int)((enemyBulletRed[enemyBulletIter]->GetEnemyBulletPosX() + enemyBulletRed[enemyBulletIter]->GetEnemyBulletWidth() - terrain.GetScreenX()) / 16)), (float)((int)((enemyBulletRed[enemyBulletIter]->GetEnemyBulletPosY() + enemyBulletRed[enemyBulletIter]->GetEnemyBulletHeight() / 2) / 16)));
				enemyBulletIter++;
			} else if (i > numEnemyShipRed + numBullets &&
				i < 1 + numBullets + numEnemyShipRed + numEnemyBulletsRed * numEnemyShipRed)
			{
				delete unit[i];
				unit[i] = nullptr;
				enemyBulletIter++;
			}

			if (i >= 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed &&
				i < 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed + numEnemyShipYellow &&
				enemyShipYellow[enemyYIter] != nullptr)
			{
				delete unit[i];
				unit[i] = nullptr;
				unit[i] = new vec2((float)((int)((enemyShipYellow[enemyYIter]->GetEnemyPosX() + enemyShipYellow[enemyYIter]->GetEnemyWidth() / 2 - terrain.GetScreenX()) / 16)), (float)((int)((enemyShipYellow[enemyYIter]->GetEnemyPosY() + enemyShipYellow[enemyYIter]->GetEnemyHeight() / 2) / 16)));
				enemyYIter++;
			} else if (i > numBullets + numEnemyShipRed + numEnemyBulletsRed * numEnemyShipRed &&
				i < 1 + numEnemyShipRed + numBullets + numEnemyBulletsRed * numEnemyShipRed + numEnemyShipYellow)
			{
				delete unit[i];
				unit[i] = nullptr;
				enemyYIter++;
			}
		}
	}



	void Grid::Draw(Surface* screen, float deltaTime, Terrain& terrain)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 24; j++)
			{
				const float topX = (float)j * 16.f;
				const float topY = (float)i * 16.f;

				for (int x = 0; x < 1 + numEnemyShipRed + numBullets + numEnemyBullets * numEnemyShipRed + numEnemyShipYellow; x++) {
					if (unit[x] != nullptr) {
						if (x == 0 && unit[x]->x == j && unit[x]->y == i) {
							cells[i][j]->Draw(screen, topX, topY, colour);
						}
						else if (x > 0 && x < 6 && unit[x] != nullptr && unit[x]->x == j && unit[x]->y == i)
						{
							cells[i][j]->Draw(screen, topX, topY, BLUEMASK);
						}
						else if (x > 5 && x < 16 && unit[x] != nullptr && unit[x]->x == j && unit[x]->y == i)
						{
							cells[i][j]->Draw(screen, topX, topY, GREENMASK);
						}
						else if (x > 15 && x < 31 && unit[x] != nullptr && unit[x]->x == j && unit[x]->y == i)
						{
							cells[i][j]->Draw(screen, topX, topY, 0x000000);
						}
						else if (x > 30 && x < 36 && unit[x] != nullptr && unit[x]->x == j && unit[x]->y == i)
						{
							cells[i][j]->Draw(screen, topX, topY, REDMASK);
						}
					}
				}
			}
		}

		if (collisionHandler.GetIsColliding() == true)
		{
			enemyDemolition[animIter] = new Animation();
			animPosX[animIter] = collisionHandler.GetTempX();
			animPosY[animIter] = collisionHandler.GetTempY();

			animIter++;

			if (animIter > 9)
			{
				animIter = 0;
			}

			collisionHandler.SetIsColliding(false);
		}

		for (int i = 0; i < numEnemyShipRed + numEnemyShipYellow; i++)
		{
			if (enemyDemolition[i] != nullptr)
			{
				enemyDemolition[i]->Play(screen, deltaTime, terrain.GetScreenX(), animPosX[i], animPosY[i], ESRnumFrames, ESRFrameSpeed, ESRDeath);

				if (enemyDemolition[i]->GetAnimEnd() == true)
				{
					enemyDemolition[i]->SetAnimEnd(false);
					delete enemyDemolition[i];
					enemyDemolition[i] = nullptr;
				}
			}
		}
	}
}
