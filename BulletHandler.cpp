#include "precomp.h"

namespace Tmpl8
{
	Sprite* bulletCharge = new Sprite(new  Surface("assets/playerBulletCharge.tga"), 8);
	Animation* bulletChargeAnim = new Animation();

	BulletHandler::BulletHandler()
	{
	}

	void BulletHandler::Update(float deltaTime, float screenX)
	{
		for (int i = 0; i < numBullets; i++)
		{
			if (playerBullets[i] != nullptr)
			{
				playerBullets[i]->Update(deltaTime, screenX);

				if (playerBullets[i]->GetBulletPosX() >= screenX + 380)
				{
				delete playerBullets[i];
				playerBullets[i] = nullptr;
				}
			}
		}
	}

	void BulletHandler::Draw(Surface* a_Target, float deltaTime, float screenX, Player &player)
	{
		if (GetAsyncKeyState(0x5A) < 0)
		{
			bulletChargeAnim->Play(a_Target, deltaTime, screenX, player.GetPlayerPosX() + player.playerW, player.GetPlayerPosY() - 5, numFramesCharge, speedAnimCharge, bulletCharge);
		}

		for (int i = 0; i < numBullets; i++)
		{
			if (playerBullets[i] != nullptr)
			{
				playerBullets[i]->Draw(a_Target, deltaTime, screenX);
			}
		}
	}

	void BulletHandler::Fired(float deltaTime, float screenX, float playerPosX, float playerPosY)
	{
		if (GetAsyncKeyState(0x5A) < 0)
		{
			chargeTimer += deltaTime / 1000;

			if (chargeTimer > 6) chargeTimer = 6.0f;
		}

		if (GetAsyncKeyState(0x5A) == 0 && chargeTimer > 0.0f)
		{
			playerBullets[bulletCnt] = new PlayerBullet;
			playerBullets[bulletCnt]->SetBulletPosX(playerPosX);
			playerBullets[bulletCnt]->SetBulletPosY(playerPosY);

			if (chargeTimer < 1) {

				playerBullets[bulletCnt]->SetBulletState(State::NORMAL);
				playerBullets[bulletCnt]->SetBulletWidth(8);
				playerBullets[bulletCnt]->SetBulletHeight(4);

				chargeTimer = 0;
			}
			else if (chargeTimer >= 1 && chargeTimer < 2)
			{
				playerBullets[bulletCnt]->SetBulletState(State::CHARGE1);
				playerBullets[bulletCnt]->SetBulletWidth(17);
				playerBullets[bulletCnt]->SetBulletHeight(12);

				chargeTimer = 0;
			}
			else if (chargeTimer >= 2 && chargeTimer < 3)
			{
				playerBullets[bulletCnt]->SetBulletState(CHARGE2);
				playerBullets[bulletCnt]->SetBulletWidth(33);
				playerBullets[bulletCnt]->SetBulletHeight(12);

				chargeTimer = 0;
			}
			else if (chargeTimer >= 3 && chargeTimer < 4)
			{
				playerBullets[bulletCnt]->SetBulletState(CHARGE3);
				playerBullets[bulletCnt]->SetBulletWidth(49);
				playerBullets[bulletCnt]->SetBulletHeight(14);

				chargeTimer = 0;
			}
			else if (chargeTimer >= 4 && chargeTimer < 5)
			{
				playerBullets[bulletCnt]->SetBulletState(CHARGE4);
				playerBullets[bulletCnt]->SetBulletWidth(65);
				playerBullets[bulletCnt]->SetBulletHeight(14);

				chargeTimer = 0;
			}
			else if (chargeTimer >= 5 && chargeTimer <= 6)
			{
				playerBullets[bulletCnt]->SetBulletState(CHARGE5);
				playerBullets[bulletCnt]->SetBulletWidth(81);
				playerBullets[bulletCnt]->SetBulletHeight(16);

				chargeTimer = 0;
			}

			bulletCnt++;

			if (bulletCnt == numBullets - 1)
			{
				bulletCnt = 0;
			}
		}
	}

	PlayerBullet** BulletHandler::GetPlayerBullet()
	{
		return playerBullets;
	}

}
