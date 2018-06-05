#include "TicGame.h"
#include "stdafx.h"

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

	InputCoords.Row = '\0';
	InputCoords.Column = 0;
	ScoreX = ScoreY = 0;
	PlayerTurn = 'X';
}

// Get functions
int TicGame::GetScoreX() const { return ScoreX; }
int TicGame::GetScoreY() const { return ScoreY; }
char TicGame::GetPlayerTurn() const { return PlayerTurn; }

int TicGame::PlayTurn(int Input)
{
	
	return 0;
}

// Prints the current game state
void TicGame::DisplayBoard()
{
	int i = 0, j = 0;
	for (i = 0; i < BOARD_SIZE; ++i)
	{
		for (j = 0; j < BOARD_SIZE; ++j)
		{
			cout << Game[i][j] << "\t";
		}
		cout << endl;
	}
}

bool TicGame::IsGameDone()
{
	return false;
}


TicGame::~TicGame()
{
}
