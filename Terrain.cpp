#include "precomp.h"

namespace Tmpl8
{
    //Sprite* levelS = new Sprite(new Surface("assets/backS.png"), 1);
    //Sprite* backS = new Sprite(new Surface("assets/levelS.png"), 1);
    Sprite* tileSheet = new Sprite(new Surface("assets/tileSheetForeground.png"), 268);
    Sprite* tileSheetBack = new Sprite(new Surface("assets/tileSheet.png"), 268);

	Terrain::Terrain()
	{
	}

    void Terrain::Update(float deltaTime)
	{
        if (!IsBoss()) {
            //screenX += speed * 0.33f;
            screenX += speed * ((deltaTime / 1000) * 100);
            screenBackX += speedBack * ((deltaTime / 1000) * 100);
        }
	}

    void Terrain::Draw(Surface* a_Target, TerrainData terrainData) const
	{
        for (int y = 0; y < TerrainHeight; ++y)
        {
            for (int x = 0; x < TerrainWidth; ++x)
            {
            	const float topX = (float)x * (float)spriteW;
            	const float topY = (float)y * (float)spriteH;

                if (topX >= screenBackX - (float)spriteW && topX <= screenBackX + (float)screenW)
                {
                    tileSheetBack->SetFrame(terrainData.background[y][x]);
                    tileSheetBack->Draw(a_Target, (int)(std::floor(topX - screenBackX)), (int)(std::floor(topY)));
                }

                if (topX >= screenX - (float)spriteW && topX <= screenX + (float)screenW)
                {
                    tileSheet->SetFrame(terrainData.data[y][x]);
                    tileSheet->Draw(a_Target, (int)(std::floor(topX - screenX)), (int)(std::floor(topY)));
                }
            }
        }
	}

    bool Terrain::IsBoss() const
	{
        if (screenX + (float)screenW >= 2880 + 896)
        {
            return true;
        }
        return false;
	}

    void Terrain::SetScreenX(float position)
    {
        screenX = position;
    }

    void Terrain::SetScreenBackX(float position)
    {
        screenBackX = position;
    }

    float Terrain::GetScreenX() const
    {
        return screenX;
    }
};
