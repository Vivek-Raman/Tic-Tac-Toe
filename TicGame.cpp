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

int TicGame::PlayTurn()
{
	// Input Turn string
	char InputValue[5];
	fgets(InputValue, 5, stdin);
	SplitInput(InputValue);
	ValidatedInput(InputValue);

	SwapPlayer();
	return 0;
}

// Returns Error state of InputCoords
EInputErrorType TicGame::ValidatedInput(char InputValue[])
{
	if (strlen(InputValue) > 2)
		return EInputErrorType::TooLong;

	InputCoords.Row = toupper(InputCoords.Row);
	if (InputCoords.Row <= 1 || InputCoords.Row >= BOARD_SIZE)
	{
		if (InputCoords.Column <= 1 || InputCoords.Column >= BOARD_SIZE)
		{
			return EInputErrorType::BadBoth;
		}
		else
		{
			return EInputErrorType::BadRow;
		}
	}
	else
	{
		if (InputCoords.Column <= 1 || InputCoords.Column >= BOARD_SIZE)
		{
			return EInputErrorType::BadColumn;
		}
	}
	return EInputErrorType::OK;
}

// Prints the current game state
void TicGame::DisplayBoard() const
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

void TicGame::SwapPlayer()
{
	if (PlayerTurn == 'X')
		PlayerTurn = 'O';
	else
		PlayerTurn = 'X';
}

// Splits input into InputCoords
void TicGame::SplitInput(char InputValue[])
{
	InputCoords.Row = (int)(toupper(InputValue[0]) - 'A') + 1;
	InputCoords.Column = (int)InputValue[1];
}

TicGame::~TicGame()
{
}