#include "precomp.h"

namespace Tmpl8
{
	Sprite* enemyBulletS = new Sprite(new Surface("assets/enemyBulletRed.tga"), 4);
	Animation* enemyBulletAnim = new Animation();

	EnemyBulletRed::EnemyBulletRed()
	{
		
	}

	EnemyBulletRed::EnemyBulletRed(float bulletPosX, float bulletPosY, float playerPosX, float playerPosY)
	{
		enemyBulletPosX = bulletPosX;
		enemyBulletPosY = bulletPosY;
		targetX = playerPosX;
		targetY = playerPosY;
	}

	void EnemyBulletRed::Update(float deltaTime, float screenX)
	{
		const float pathX = targetX - enemyBulletPosX;
		const float pathY = targetY - enemyBulletPosY;

		const float d = sqrt(pathX * pathX + pathY * pathY);

		const float normDirVecX = pathX / d;
		const float normDirVecY = pathY / d;

		const float speedDeltaX = normDirVecX * speed * (deltaTime / 1000) * 100;
		const float speedDeltaY = normDirVecY * speed * (deltaTime / 1000) * 100;

		enemyBulletPosX += speedDeltaX;
		enemyBulletPosY += speedDeltaY;

		enemyBulletCircle = Circle(radius, enemyBulletPosX + 9, enemyBulletPosY + 4);
	}

	void EnemyBulletRed::Draw(Surface* screen, float deltaTime, float screenX)
	{
		enemyBulletAnim->Play(screen, deltaTime, screenX, enemyBulletPosX, enemyBulletPosY, numFrames, speedAnim, enemyBulletS);
	}

	void EnemyBulletRed::SetEnemyBulletPosX(float posX)
	{
		enemyBulletPosX = posX;
	}

	void EnemyBulletRed::SetEnemyBulletPosY(float posY)
	{
		enemyBulletPosY = posY;
	}

	float EnemyBulletRed::GetEnemyBulletPosX() const
	{
		return enemyBulletPosX;
	}

	float EnemyBulletRed::GetEnemyBulletPosY() const
	{
		return enemyBulletPosY;
	}

	float EnemyBulletRed::GetEnemyBulletWidth() const
	{
		return enemyBulletW;
	}

	float EnemyBulletRed::GetEnemyBulletHeight() const
	{
		return enemyBulletH;
	}

	Circle EnemyBulletRed::GetEnemyBulletRedCircle() const
	{
		return enemyBulletCircle;
	}

}