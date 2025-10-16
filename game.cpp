#include "precomp.h" // include this first in every .cpp file
#include "game.h"

namespace Tmpl8
{
	GameState gameState;

	Terrain terrain;
	TerrainData terrainData;

	Player player;
	PlayerBullet playerBullet;
	BulletHandler bulletHandler;

	EnemyShipRed enemyRed;
	EnemyShipYellow enemyYellow;
	EnemyManager enemyMngr;
	EnemyBulletRedManager enemyBulletMngr;

	BackgroundCollision bckCollision;

	Grid grid;

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		gameState.SetGameState(GameState::MENU);
	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);

		switch (gameState.GetGameState()) {
		case GameState::MENU:
			for (int button = 0; button < 256; button++)
			{
				if (GetAsyncKeyState(button) & 1)
				{
					gameState.SetGameState(GameState::GAMEPLAY);
					terrainData.Load();
				}
			}

			break;
		case GameState::GAMEPLAY:
			//UPDATE
			terrain.Update(deltaTime);
			player.Update(deltaTime, terrain.GetScreenX(), terrain.IsBoss());
			bulletHandler.Fired(deltaTime, terrain.GetScreenX(), player.GetPlayerPosX(), player.GetPlayerPosY());
			bulletHandler.Update(deltaTime, terrain.GetScreenX());
			enemyMngr.Update(deltaTime, terrain.GetScreenX());
			enemyBulletMngr.Fired(player, enemyMngr.GetEnemyShipRed());
			enemyBulletMngr.Update(deltaTime, terrain.GetScreenX(), player, enemyMngr.GetEnemyShipRed());
			bckCollision.Update(player, terrainData);
			//Major memory leak - fixed
			grid.HandleCollision(screen, deltaTime, player.GetPlayerAABB(), enemyRed.GetEnemyShipRedAABB(),
				playerBullet.GetBulletCircle(), enemyYellow.GetEnemyShipYellowCircle(), player,
				enemyMngr.GetEnemyShipRed(), enemyMngr.GetEnemyShipYellow(),
				bulletHandler.GetPlayerBullet(), enemyBulletMngr.GetEnemyBulletRed(), terrain);

			//DRAW
			terrain.Draw(screen, terrainData);
			player.Draw(screen, deltaTime, terrain.GetScreenX());
			bulletHandler.Draw(screen, deltaTime, terrain.GetScreenX(), player);
			enemyMngr.Draw(screen, deltaTime, terrain.GetScreenX());
			enemyBulletMngr.Draw(screen, deltaTime, terrain.GetScreenX());
			grid.Draw(screen, deltaTime, terrain);

			if (player.lives <= 0)
			{
				gameState.SetGameState(GameState::RESPAWNING);
			}

			break;
		case GameState::RESPAWNING:
			if (terrain.GetScreenX() <= 1000)
			{
				terrain.SetScreenX(0.f);
				terrain.SetScreenBackX(0.f);
				gameState.SetGameState(GameState::GAMEPLAY);

			}
			else if (terrain.GetScreenX() > 1000 && terrain.GetScreenX() <= 2000)
			{
				terrain.SetScreenX(1000.f);
				terrain.SetScreenBackX(1000.f * 0.75f);
				gameState.SetGameState(GameState::GAMEPLAY);
			}
			else if (terrain.GetScreenX() > 2000)
			{
				terrain.SetScreenX(2000.f);
				terrain.SetScreenBackX(2000.f * 0.75f);
				gameState.SetGameState(GameState::GAMEPLAY);
			}

			break;
		}
	}
};