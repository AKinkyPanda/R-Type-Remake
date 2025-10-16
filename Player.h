#pragma once
#include "AABB.h"
#include "BaseObject.h"

namespace Tmpl8 {
	class BackgroundCollision;

	class Player : public BaseObject
	{
		const float startX = 25;
		const float startY = 90;

		float playerPosX = 0;
		float playerPosY = 0;

		const float speed = 0.75f;
		const float idleSpeed = 0.33f;

		float checkpointX = 0;
		float checkpointY = 0;

		int numFramesVertical = 2;
		float animationSpeedVertical = 0.5f;

	public:
		Player();

		AABB playerBox = AABB(playerPosX, playerPosY, (float)playerW, (float)playerH);

		const int playerW = 33;
		const int playerH = 17;

		int lives = 6;

		void Update(float deltaTime, float screenX, bool isBoss);
		void Draw(Surface* a_Target, float deltaTime, float screenX) const;

		void SetCheckpoint(float screenX);
		void Respawn();

		void SetPlayerPosX(float positionX);
		void SetPlayerPosY(float positionY);

		float GetPlayerStartX() const;
		float GetPlayerStartY()  const;

		float GetPlayerPosX() const;
		float GetPlayerPosY() const;

		AABB GetPlayerAABB() const;
	};
}

