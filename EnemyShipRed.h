#pragma once
#include "Enemy.h"

constexpr int numEnemyBullets = 3;

namespace Tmpl8 {
	class EnemyBulletRed;
	class Animation;
	class Collision;

	class EnemyShipRed : public Enemy
	{
	private:
		float enemyPosX = 0;
		float enemyPosY = 0;

		float startY = 90;
		float startX = 0;

		float enemyW = 33;
		float enemyH = 24;

		const float speed = 0.1f;
		float speedY = 0;

		const float frameSpeed = 0.1f;
		const int numFrames = 8;

		float shotTimer = 0.0f;

		AABB enemyBox = AABB(enemyPosX + 5, enemyPosY + 8, enemyW - 7, enemyH - 8);

		Animation* enemyIdle;

		bool fired = false;

	public:
		EnemyShipRed();
		EnemyShipRed(float posX, float posY, float width, float height);

		virtual void Update(float deltaTime, float screenX);
		virtual void Draw(Surface* screen, float deltaTime, float screenX);

		enum State { SPAWNING, MOVING_UP, MOVING_DOWN };
		State state = SPAWNING;

		void Spawn(float screenX);
		void MoveUp(float deltaTime, float screenX);
		void MoveDown(float deltaTime, float screenX);
		void Fire(float deltaTime, float screenX);

		void DeathAnim(Surface* screen, float deltaTime, float screenX, int numFrames, float frameSpeed, Sprite* sprite) const;

		void SetState(State newS);
		void SetFireState(bool state);

		float GetEnemyPosX() const;
		float GetEnemyPosY() const;
		float GetEnemyWidth() const;
		float GetEnemyHeight() const;
		bool GetEnemyFireState() const;

		AABB GetEnemyShipRedAABB() const;
	};
}

