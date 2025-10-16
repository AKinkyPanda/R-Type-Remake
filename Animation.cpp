#include "precomp.h"

namespace Tmpl8
{
	Animation::Animation()
	{
		
	}

	void Animation::Play(Surface* screen, float deltaTime, float screenX, float x, float y, int numFrames, float frameSpeed, Sprite* sprite)
	{
		sprite->SetFrame(frame);
		sprite->Draw(screen, (int)(x - screenX), (int)y);

		frameTimer += deltaTime / 1000;

		if (frameTimer > frameSpeed)
		{
			frame++;
			frameTimer -= frameSpeed;
		}

		if (frame >= numFrames)
		{
			frame = 0;
			AnimEnd = true;
		}
	}

	void Animation::PlayLoop(Surface* screen, float deltaTime, float screenX, float x, float y, int numFrames, float frameSpeed, Sprite* sprite)
	{
		while (frame < numFrames)
		{
			sprite->SetFrame(frame);
			sprite->Draw(screen, (int)(x - screenX), (int)y);

			frameTimer += deltaTime / 1000;

			if (frameTimer > frameSpeed)
			{
				frame++;
				frameTimer -= frameSpeed;
			}
		}

		frame = 0;
	}

	void Animation::SetAnimEnd(bool status)
	{
		AnimEnd = status;
	}


	int Animation::GetFrame() const
	{
		return frame;
	}

	bool Animation::GetAnimEnd() const
	{
		return AnimEnd;
	}

}
