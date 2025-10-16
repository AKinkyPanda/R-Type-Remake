#include "precomp.h"

namespace Tmpl8
{
	Sprite* enemyShipYellowSUp = new Sprite(new Surface("assets/enemyShipYellowUp.tga"), 3);
	Sprite* enemyShipYellowSDown = new Sprite(new Surface("assets/enemyShipYellowDown.tga"), 3);

	Animation* enemyYellowUp = new Animation();
	Animation* enemyYellowDown = new Animation();

	EnemyShipYellow::EnemyShipYellow()
	{
		
	}

	EnemyShipYellow::EnemyShipYellow(float posX, float posY, float width, float height)
	{
		startX = posX;
		startY = posY;
		enemyW = width;
		enemyH = height;
	}

	void EnemyShipYellow::Update(float deltaTime, float screenX)
	{
		switch(state)
		{
		case SPAWNING: Spawn(screenX); break;
		case MOVING_UP: MoveUp(deltaTime, screenX); break;
		case MOVING_DOWN: MoveDown(deltaTime, screenX); break;
		}

		enemyCircle = Circle(radius, enemyPosX, enemyPosY);
	}

	void EnemyShipYellow::Draw(Surface* screen, float deltaTime, float screenX)
	{
		switch(state)
		{
		case MOVING_UP:
			enemyYellowUp->Play(screen, deltaTime, screenX, enemyPosX, enemyPosY, numFrames, frameSpeed, enemyShipYellowSUp);
			break;
		case MOVING_DOWN:
			enemyYellowDown->Play(screen, deltaTime, screenX, enemyPosX, enemyPosY, numFrames, frameSpeed, enemyShipYellowSDown);
			break;
		default:
			break;
		}
	}

	void EnemyShipYellow::Spawn(float screenX)
	{
		enemyPosX = startX;
		enemyPosY = startY;
		state = MOVING_UP;
	}

	void EnemyShipYellow::MoveUp(float deltaTime, float screenX)
	{
		enemyPosX -= speed * ((deltaTime / 1000) * 200);
		enemyPosY -= speed * ((deltaTime / 1000) * 150);

		if (enemyPosY <= startY - 15)
		{
			state = MOVING_DOWN;
		}
	}

	void EnemyShipYellow::MoveDown(float deltaTime, float screenX)
	{
		enemyPosX -= speed * ((deltaTime / 1000) * 200);
		enemyPosY += speed * ((deltaTime / 1000) * 150);

		if (enemyPosY >= startY + 15)
		{
			state = MOVING_UP;
		}
	}

	float EnemyShipYellow::GetEnemyPosX() const
	{
		return enemyPosX;
	}

	float EnemyShipYellow::GetEnemyPosY() const
	{
		return enemyPosY;
	}

	float EnemyShipYellow::GetEnemyWidth() const
	{
		return enemyW;
	}

	float EnemyShipYellow::GetEnemyHeight() const
	{
		return enemyH;
	}

	Circle EnemyShipYellow::GetEnemyShipYellowCircle() const
	{
		return enemyCircle;
	}

}
