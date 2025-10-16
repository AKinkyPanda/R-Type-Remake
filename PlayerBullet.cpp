#include "precomp.h"

namespace Tmpl8
{
	Sprite* bulletS = new Sprite(new Surface("assets/playerBullet.png"), 1);

	Sprite* bulletCh1 = new Sprite(new Surface("assets/playerBulletCharge1.tga"), 2);
	Animation* bulletCh1Anim = new Animation();

	Sprite* bulletCh2 = new Sprite(new Surface("assets/playerBulletCharge2.tga"), 2);
	Animation* bulletCh2Anim = new Animation();

	Sprite* bulletCh3 = new Sprite(new Surface("assets/playerBulletCharge3.tga"), 2);
	Animation* bulletCh3Anim = new Animation();

	Sprite* bulletCh4 = new Sprite(new Surface("assets/playerBulletCharge4.tga"), 2);
	Animation* bulletCh4Anim = new Animation();

	Sprite* bulletCh5 = new Sprite(new Surface("assets/playerBulletCharge5.tga"), 2);
	Animation* bulletCh5Anim = new Animation();


	PlayerBullet::PlayerBullet()
		: Circle(radius, bulletPosX + 5, bulletPosY)
	{
	}

	void PlayerBullet::Update(float deltaTime, float screenX)
	{
		switch(state)
		{
		case NORMAL:
			if (bulletPosX < screenX + 384)
			{
				bulletPosX += speed * ((deltaTime / 1000) * 300);
			}

			playerBulletCircle = Circle(radiusN, bulletPosX + 6, bulletPosY + 2);

			break;
		case CHARGE1:
			if (bulletPosX < screenX + 384)
			{
				bulletPosX += speed * ((deltaTime / 1000) * 275);
			}

			playerBulletCircle = Circle(radiusCh1, bulletPosX + 10, bulletPosY + 6);

			break;
		case CHARGE2:
			if (bulletPosX < screenX + 384)
			{
				bulletPosX += speed * ((deltaTime / 1000) * 250);
			}

			playerBulletCircle = Circle(radiusCh2, bulletPosX + 23, bulletPosY + 6);

			break;
		case CHARGE3:
			if (bulletPosX < screenX + 384)
			{
				bulletPosX += speed * ((deltaTime / 1000) * 225);
			}

			playerBulletCircle = Circle(radiusCh3, bulletPosX + 39, bulletPosY + 7);

			break;
		case CHARGE4:
			if (bulletPosX < screenX + 384)
			{
				bulletPosX += speed * ((deltaTime / 1000) * 200);
			}

			playerBulletCircle = Circle(radiusCh4, bulletPosX + 56, bulletPosY + 7);

			break;
		case CHARGE5:
			if (bulletPosX < screenX + 384)
			{
				bulletPosX += speed * ((deltaTime / 1000) * 175);
			}

			playerBulletCircle = Circle(radiusCh5, bulletPosX + 69, bulletPosY + 8);

			break;
		}
	}

	void PlayerBullet::Draw(Surface* a_Target, float deltaTime, float screenX)
	{
		switch (state) {
		case NORMAL: bulletS->Draw(a_Target, (int)(bulletPosX - screenX), (int)(bulletPosY)); break;
		case CHARGE1: bulletCh1Anim->Play(a_Target, deltaTime, screenX, bulletPosX, bulletPosY, 2, 1.0f, bulletCh1); break;
		case CHARGE2: bulletCh2Anim->Play(a_Target, deltaTime, screenX, bulletPosX, bulletPosY, 2, 1.0f, bulletCh2); break;
		case CHARGE3: bulletCh3Anim->Play(a_Target, deltaTime, screenX, bulletPosX, bulletPosY, 2, 1.0f, bulletCh3); break;
		case CHARGE4: bulletCh4Anim->Play(a_Target, deltaTime, screenX, bulletPosX, bulletPosY, 2, 1.0f, bulletCh4); break;
		case CHARGE5: bulletCh5Anim->Play(a_Target, deltaTime, screenX, bulletPosX, bulletPosY, 2, 1.0f, bulletCh5); break;
		}
	}

	void PlayerBullet::SetBulletPosX(float position)
	{
		bulletPosX = position + offsetX;
	}

	void PlayerBullet::SetBulletPosY(float position)
	{
		bulletPosY = position + offsetY;
	}

	void PlayerBullet::SetBulletWidth(float width)
	{
		bulletW = width;
	}

	void PlayerBullet::SetBulletHeight(float height)
	{
		bulletH = height;
	}

	void PlayerBullet::SetBulletState(State state)
	{
		this->state = state;
	}

	float PlayerBullet::GetBulletPosX() const
	{
		return bulletPosX;
	}

	float PlayerBullet::GetBulletPosY() const
	{
		return bulletPosY;
	}

	float PlayerBullet::GetBulletWidth() const
	{
		return bulletW;
	}

	float PlayerBullet::GetBulletHeight() const
	{
		return bulletH;
	}

	const Circle PlayerBullet::GetBulletCircle() const
	{
		return playerBulletCircle;
	}


}
