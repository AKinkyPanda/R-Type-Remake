#pragma once

namespace Tmpl8 {
	class Animation
	{
		int frame = 0;
		float frameTimer = 0.0f;

		bool AnimEnd = false;

	public:
		Animation();

		void Play(Surface* screen, float deltaTime, float screenX, float x, float y, int numFrames, float frameSpeed, Sprite* sprite);
		void PlayLoop(Surface* screen, float deltaTime, float screenX, float x, float y, int numFrames, float frameSpeed, Sprite* sprite);

		void SetAnimEnd(bool status);

		int GetFrame() const;
		bool GetAnimEnd() const;
	};
}

