#pragma once

namespace Tmpl8 {
	class GameState
	{
	public:
		GameState();

		enum State{MENU, GAMEPLAY, RESPAWNING};
		State state = MENU;

		void SetGameState(State newS);

		State GetGameState() const;
	};
}

