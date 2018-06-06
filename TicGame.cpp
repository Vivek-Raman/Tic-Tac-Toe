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
	ScoreA = ScoreB = 0;
	PlayerTurn = 'X';
}

// Get functions
int TicGame::GetScoreA() const { return ScoreA; }
int TicGame::GetScoreB() const { return ScoreB; }
char TicGame::GetPlayerTurn() const { return PlayerTurn; }

void TicGame::PlayTurn()
{
	// Input Turn string
	char InputValue[5];
	fgets(InputValue, 5, stdin);
	SplitInput(InputValue);
	switch (ValidatedInput(InputValue))
	{
	case EInputErrorType::BadBoth:
		cout << "Invalid cell.\n";
		break;
	
	case EInputErrorType::BadColumn:
		cout << "Invalid column.\n";
		break;
	
	case EInputErrorType::BadRow:
		cout << "Invalid row.\n";
		break;
	
	case EInputErrorType::TooLong:
		cout << "Input should be of format <Row><Column> eg. \"A3\"\n";
		break;

	case EInputErrorType::Occupied:
		cout << "Cell is occupied.\n";
		break;

	case EInputErrorType::OK:
		cout << "Valid Input.\n";
		break;
	}
	// TODO: Persist user for valid input
	AddTurn();
}

// Adds entry to Board
void TicGame::AddTurn()
{
		Game[InputCoords.Row][InputCoords.Column] = PlayerTurn;
		if (!EndGame())
			SwapPlayer();
}

bool TicGame::EndGame()
{
	char temp = '\0';
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			;
		}
	}
	return false;
}

// Returns Error state of InputCoords
EInputErrorType TicGame::ValidatedInput(char InputValue[])
{
	if (strlen(InputValue) > 2)
		return EInputErrorType::TooLong;

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

	// Match array indices
	InputCoords.Column--;
	InputCoords.Row--;

	// Checks array for unoccupied cell
	if (Game[InputCoords.Row][InputCoords.Column] != '\0')
	{
		return EInputErrorType::Occupied;
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