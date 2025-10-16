#pragma once
#include "Player.h"
#include "TerrainData.h"

namespace Tmpl8 {
	class BackgroundCollision : public TerrainData, public Player, public Terrain
	{
	public:
		BackgroundCollision();

		void Update(Player &player, TerrainData terrainData) const;
	};
}

