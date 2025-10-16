#include "precomp.h"

namespace Tmpl8{
	Sprite* enemyShipRedS = new Sprite(new Surface("assets/EnemyShipRed.tga"), 8);

	Animation* enemyDeath = new Animation();

	EnemyShipRed::EnemyShipRed()
	{
		
	}

	EnemyShipRed::EnemyShipRed(float posX, float posY, float width, float height)
	{
		startX = posX;
		startY = posY;
		enemyW = width;
		enemyH = height;
		speedY = Rand(0.3);
		enemyIdle = new Animation();
	}

	void EnemyShipRed::Update(float deltaTime, float screenX)
	{
		switch (state) {
		case SPAWNING: Spawn(screenX); break;
		case MOVING_UP: MoveUp(deltaTime, screenX); Fire(deltaTime, screenX); break;
		case MOVING_DOWN: MoveDown(deltaTime, screenX); Fire(deltaTime, screenX); break;
		}

		enemyBox = AABB(enemyPosX + 5, enemyPosY + 8, enemyW - 7, enemyH - 8);
	}

	void EnemyShipRed::Draw(Surface* screen, float deltaTime, float screenX)
	{
		if (state != SPAWNING) {
			enemyIdle->Play(screen, deltaTime, screenX, enemyPosX, enemyPosY, numFrames, frameSpeed, enemyShipRedS);
		}
	}

	void EnemyShipRed::Spawn(float screenX)
	{
			enemyPosX = startX;
			enemyPosY = startY;
			state = MOVING_UP;
	}

	void EnemyShipRed::MoveUp(float deltaTime, float screenX)
	{
		enemyPosX -= speed * ((deltaTime / 1000) * 300);
		enemyPosY += speedY * ((deltaTime / 1000) * 250);

		shotTimer += deltaTime / 1000;

		if (enemyPosY >= startY + 30)
		{
			state = MOVING_DOWN;
		}
	}

	void EnemyShipRed::MoveDown(float deltaTime, float screenX)
	{
		enemyPosX -= speed * ((deltaTime / 1000) * 300);
		enemyPosY -= speedY * ((deltaTime / 1000) * 250);

		shotTimer += deltaTime / 1000;

		if (enemyPosY <= startY)
		{
			state = MOVING_UP;
		}
	}

	void EnemyShipRed::Fire(float deltaTime, float screenX)
	{
		if (shotTimer >= 3)
		{
			fired = true;

			shotTimer = -3;
		} 
	}


	void EnemyShipRed::DeathAnim(Surface* screen, float deltaTime, float screenX, int numFrames, float frameSpeed, Sprite* sprite) const
	{
		enemyDeath->Play(screen, deltaTime, screenX, enemyPosX, enemyPosY, numFrames, frameSpeed, sprite);
	}


	void EnemyShipRed::SetState(State newS)
	{
		state = newS;
	}

	void EnemyShipRed::SetFireState(bool state)
	{
		fired = state;
	}

	float EnemyShipRed::GetEnemyPosX() const
	{
		return enemyPosX;
	}

	float EnemyShipRed::GetEnemyPosY() const
	{
		return enemyPosY;
	}

	float EnemyShipRed::GetEnemyWidth() const
	{
		return enemyW;
	}

	float EnemyShipRed::GetEnemyHeight() const
	{
		return enemyH;
	}

	bool EnemyShipRed::GetEnemyFireState() const
	{
		return fired;
	}

	AABB EnemyShipRed::GetEnemyShipRedAABB() const
	{
			return enemyBox;
	}

}