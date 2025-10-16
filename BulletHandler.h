#pragma once

constexpr int numBullets = 10;

namespace Tmpl8 {
	class BulletHandler : public PlayerBullet
	{
		int bulletCnt = 0;
		float chargeTimer = 0.0f;

		int numFramesCharge = 8;
		float speedAnimCharge = 0.1f;

	public:
		PlayerBullet* playerBullets[numBullets];

		BulletHandler();

		void Update(float deltaTime, float screenX);
		void Draw(Surface* a_Target, float deltaTime, float screenX, Player &player);
		void Fired(float deltaTime, float screenX, float playerPosX, float playerPosY);

		PlayerBullet** GetPlayerBullet();
	};
}

