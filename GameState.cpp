#include "precomp.h"

namespace Tmpl8
{
	GameState::GameState()
	{
		
	}

	void GameState::SetGameState(State newS)
	{
		state = newS;
	}

	GameState::State GameState::GetGameState() const
	{
		return state;
	}

}