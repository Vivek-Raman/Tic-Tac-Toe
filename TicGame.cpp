#include "TicGame.h"
#include "stdafx.h"

typedef int Coords[2];
constexpr int BOARD_SIZE = 3;

TicGame::TicGame()
{
	// Set board to NULL
	for (int i = 0; i < BOARD_SIZE; ++i)	
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			Game[i][j] = '\0';
		}
	}
	InputCoords[0] = 0;
	InputCoords[1] = 0;
	ScoreX = ScoreY = 0;
}

int TicGame::GetScoreX() const { return ScoreX; }
int TicGame::GetScoreY() const { return ScoreY; }

int TicGame::PlayTurn(int Input, bool bIsTurnX)
{
	
	return 0;
}

bool TicGame::IsGameDone()
{
	return false;
}


TicGame::~TicGame()
{
}
