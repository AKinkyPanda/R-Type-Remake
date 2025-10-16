//#include "player.h"
#include "precomp.h"

namespace Tmpl8
{
	Sprite* playerS = new Sprite(new Surface("assets/playerShip.tga"), 5);
	Sprite* playerSDown = new Sprite(new Surface("assets/playerShipDown.tga"), 2);
	Sprite* playerSUp = new Sprite(new Surface("assets/playerShipUp.tga"), 2);
	Animation* playerUP = new Animation();
	Animation* playerDown = new Animation();

	Player::Player()
	{
		playerPosX = startX;
		playerPosY = startY;
	}

	void Player::Update(float deltaTime, float screenX, bool isBoss)
	{
		SetCheckpoint(screenX);
		Respawn();

		if (playerPosX < screenX)
		{
			playerPosX = screenX;
		}

		if (GetAsyncKeyState(VK_RIGHT) && playerPosX < screenX + 355)
		{
			playerPosX += speed * ((deltaTime / 1000) * 250);
		}
		if (GetAsyncKeyState(VK_LEFT) && playerPosX > screenX)
		{
			playerPosX -= speed * ((deltaTime / 1000) * 250);
		}
		if (GetAsyncKeyState(VK_UP) && playerPosY > 0)
		{
			playerPosY -= speed * ((deltaTime / 1000) * 250);
		}
		if (GetAsyncKeyState(VK_DOWN) && playerPosY < (float)SCRHEIGHT - (float)playerH)
		{
			playerPosY += speed * ((deltaTime / 1000) * 250);
		}

		if (!isBoss) {
			playerPosX += idleSpeed * ((deltaTime / 1000) * 100);
		}

		playerBox = AABB(playerPosX, playerPosY, (float)playerW, (float)playerH);
	}

	void Player::Draw(Surface* a_Target, float deltaTime, float screenX) const
	{
		if (GetAsyncKeyState(VK_UP) && playerPosY > 0)
		{
			playerUP->Play(a_Target, deltaTime, screenX, playerPosX, playerPosY, numFramesVertical, animationSpeedVertical, playerSUp);
		}
		else if (GetAsyncKeyState(VK_DOWN) && playerPosY < (float)SCRHEIGHT - (float)playerH)
		{
			playerDown->Play(a_Target, deltaTime, screenX, playerPosX, playerPosY, numFramesVertical, animationSpeedVertical, playerSDown);
		}
		else
		{
			playerS->SetFrame(2);
			playerS->Draw(a_Target, (int)(playerPosX - screenX), (int)playerPosY);
		}

	}

	void Tmpl8::Player::SetCheckpoint(float screenX)
	{
		if (screenX < 1000)
		{
			checkpointX = 0;
			checkpointY = 90;
		}
		else if (screenX < 2000)
		{
			checkpointX = 1000;
			checkpointY = 90;
		} else
		{
			checkpointX = 2000;
			checkpointY = 90;
		}
	}

	void Player::Respawn()
	{
		if (lives <= 0)
		{
			playerPosX = checkpointX;
			playerPosY = checkpointY;

			lives = 6;
		}
	}

	void Player::SetPlayerPosX(float positionX)
	{
		this->playerPosX = positionX;
	}

	void Player::SetPlayerPosY(float positionY)
	{
		playerPosY = positionY;
	}

	float Player::GetPlayerStartX() const
	{
		return startX;
	}

	float Player::GetPlayerStartY() const
	{
		return startY;
	}

	float Player::GetPlayerPosX() const
	{
		return playerPosX;
	}

	float Player::GetPlayerPosY() const
	{
		return playerPosY;
	}

	AABB Player::GetPlayerAABB() const
	{
		return playerBox;
	}
}
