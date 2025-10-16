#include "precomp.h"

namespace Tmpl8
{
	void TerrainData::Load()
	{
		for (int y = 0; y < TerrainHeight; y++)
		{
			for (int x = 0; x < TerrainWidth; x++)
			{
				if (data[y][x] == 86 || data[y][x] == 153 || data[y][x] == 138
					|| data[y][x] == 137 || data[y][x] == 97 || data[y][x] == 121
					|| data[y][x] == 117 || data[y][x] == 98 || data[y][x] == 102
					|| data[y][x] == 114 || data[y][x] == 113 || data[y][x] == 112
					|| data[y][x] == 160 || data[y][x] == 175 || data[y][x] == 159
					|| data[y][x] == 166 || data[y][x] == 183 || data[y][x] == 147
					|| data[y][x] == 144 || data[y][x] == 143 || data[y][x] == 134
					|| data[y][x] == 128 || data[y][x] == 127 || data[y][x] == 125
					|| data[y][x] == 124 || data[y][x] == 133 || data[y][x] == 167)
				{
					data[y][x] = 0;
				}
			}
		}

		/*std::ifstream fileTerrain(filename);
		const char* ar = "notWork";
		printf("File is not opened %c", ar);

		if(fileTerrain.is_open())
		{
			const char* ch = "doesWork";
			printf("File is opened %c", ch);
			for(int y = 0; y < TerrainHeight; y++)
			{
				for(int x = 0; x < TerrainWidth; x++)
				{
					int fileNumber; //= y + (x * TerrainHeight);
					fileTerrain >> fileNumber;
					this->data[y][x] = fileNumber;
					if (fileNumber == 86 || fileNumber == 153 || fileNumber == 138
						|| fileNumber == 137 || fileNumber == 97 || fileNumber == 121
						|| fileNumber == 117 || fileNumber == 98 || fileNumber == 102
						|| fileNumber == 114 || fileNumber == 113 || fileNumber == 112
						|| fileNumber == 160 || fileNumber == 175 || fileNumber == 159
						|| fileNumber == 166 || fileNumber == 183 || fileNumber == 147
						|| fileNumber == 144 || fileNumber == 143 || fileNumber == 134
						|| fileNumber == 128 || fileNumber == 127 || fileNumber == 125
						|| fileNumber == 124 || fileNumber == 133)
					{
						data[y][x] = 0;
					}
					if (fileNumber == 86)
					{
						this->startX = x;
						this->startY = y;
					}
				}
			}

			fileTerrain.close();
		}*/
	}

};
