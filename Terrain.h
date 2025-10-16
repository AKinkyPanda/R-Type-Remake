#pragma once

namespace Tmpl8 {
	class Terrain
	{
		const int tileNumW = 20;
		const int tileNumH = 12;

		const float speed = 0.33f;
		const float speedBack = speed * 0.75f;

	public:
		Terrain();

		float screenX = 0.0f;
		float screenY = 0.0f;

		float screenBackX = 0.0f;
		float screenBackY = 0.0f;

		const int spriteW = 64;
		const int spriteH = 16;

		const int screenW = tileNumW * spriteW;
		const int screenH = tileNumH * spriteH;

		void Update(float deltaTime);
		void Draw(Surface* a_Target, TerrainData terrainData) const;

		bool IsBoss() const;

		void SetScreenX(float position);
		void SetScreenBackX(float position);

		float GetScreenX() const;
	};
};

