#include "precomp.h"

namespace Tmpl8
{
	BackgroundCollision::BackgroundCollision()
	{
	}

	void BackgroundCollision::Update(Player &player, TerrainData terrainData) const
	{
		for (int y = 0; y < TerrainHeight; y++)
		{
			for (int x = 0; x < TerrainWidth; x++)
			{
				const int topX = x * spriteW;
				const int topY = y * spriteH;

				if (topX >= (int)screenX - spriteW && topX <= (int)screenX + screenW)
				{
					if (terrainData.data[(int)(player.GetPlayerPosY() / (float)spriteH)][(int)(player.GetPlayerPosX() / (float)spriteW)] != 0 ||
						terrainData.data[(int)(player.GetPlayerPosY() / (float)spriteH)][(int)((player.GetPlayerPosX() + (float)playerW) / (float)spriteW)] != 0 ||
						terrainData.data[(int)((player.GetPlayerPosY() + (float)playerH) / (float)spriteH)][(int)(player.GetPlayerPosX() / (float)spriteW)] != 0 ||
						terrainData.data[(int)((player.GetPlayerPosY() + (float)playerH) / (float)spriteH)][(int)((player.GetPlayerPosX() + (float)playerW) / (float)spriteW)] != 0)
					{
						player.lives -= 999;
					}
				}
			}
		}
	}
}
