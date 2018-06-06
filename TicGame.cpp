#include "TicGame.h"
#include "stdafx.h"

constexpr int BOARD_SIZE = 3;
constexpr char BOARD_DEFAULT_CHAR = '_';

// Initialise all data members
TicGame::TicGame()
{
	// Set board to NULL
	for (int i = 0; i < BOARD_SIZE; ++i)	
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			Game[i][j] = BOARD_DEFAULT_CHAR;
		}
	}

	InputCoords.Row = 0;
	InputCoords.Column = 0;
	ScoreA = ScoreB = 0;
	PlayerTurn = 'X';
}

// Get functions
int TicGame::GetScoreA() const { return ScoreA; }
int TicGame::GetScoreB() const { return ScoreB; }
char TicGame::GetPlayerTurn() const { return PlayerTurn; }

// Returns TRUE on valid input
bool TicGame::PlayTurn()
{
	// Input Turn string
	char InputValue[5];
	cout << endl << PlayerTurn << "'s turn, ";
	cout << "make your move: "; //TODO: Dear lord, learn English!
	fgets(InputValue, 5, stdin);
	SplitInput(InputValue);
	switch (ValidatedInput(InputValue))
	{
	case EInputErrorType::BadBoth:
	case EInputErrorType::BadColumn:
	case EInputErrorType::BadRow:
	case EInputErrorType::TooLong:
		cout << "Input should be of format <Row><Column> eg. \"A3\"";
		return false;

	case EInputErrorType::Occupied:
		cout << "Cell is occupied.";
		return false;

	case EInputErrorType::OK:
		cout << "Valid Input.\n";
		break;
	}
	return true;
}

// Splits input into InputCoords
void TicGame::SplitInput(char *InputValue)
{
	InputCoords.Row = (int)(toupper(*InputValue) - 'A') + 1;
	InputValue++;
	InputCoords.Column = atoi(InputValue);
}

// Adds entry to Board
void TicGame::AddTurn()
{
	Game[InputCoords.Row][InputCoords.Column] = PlayerTurn;
	if (EndGame() == EEndGameType::False)
		SwapPlayer();
	else
	{
		cout << PlayerTurn << " wins!\n";	// TODO: Improve with subroutine
	}
}

// Checks win conditions
EEndGameType TicGame::EndGame()
{
	int StreakCount = 1;
	
	// Check row-wise
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		char temp = Game[i][0];
		StreakCount = 1;
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (Game[i][j] == temp && j != 0)
			{
				StreakCount++;
			}
		}
	}
	if (StreakCount == 3)
		return EEndGameType::RowWin;
	else
		StreakCount = 0;

	// Check column-wise
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		char temp = Game[0][i];
		StreakCount = 1;
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (Game[j][i] == temp && j != 0)
			{
				StreakCount++;
			}
		}
	}
	if (StreakCount == 3)
		return EEndGameType::ColumnWin;
	else
		StreakCount = 0;

	// Check primary diagonal
	char temp = Game[1][1];
	StreakCount = 1;
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (Game[i][i] == temp && i != 1)
			StreakCount++;
	}
	if (StreakCount == 3)
		return EEndGameType::DiagonalWin;
	else
		StreakCount = 0;

	// Check secondary diagonal
	StreakCount = 1;
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (Game[i][BOARD_SIZE - i-1] == temp && i != 1)
			StreakCount++;
	}
	if (StreakCount == 3)
		return EEndGameType::DiagonalWin;
	else
		StreakCount = 0;

	return EEndGameType::False;
}

// Returns Error state of InputCoords
EInputErrorType TicGame::ValidatedInput(char InputValue[])
{
	if(strlen(InputValue) > 3)
		return EInputErrorType::TooLong;

	if (InputCoords.Row < 1 || InputCoords.Row > BOARD_SIZE)
	{
		if (InputCoords.Column < 1 || InputCoords.Column > BOARD_SIZE)
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
		if (InputCoords.Column < 1 || InputCoords.Column > BOARD_SIZE)
		{
			return EInputErrorType::BadColumn;
		}
	}

	// Match array indices
	InputCoords.Column--;
	InputCoords.Row--;

	// Checks array for unoccupied cell
	if (Game[InputCoords.Row][InputCoords.Column] != BOARD_DEFAULT_CHAR)
	{
		return EInputErrorType::Occupied;
	}
	return EInputErrorType::OK;
}

// Prints the current game state
void TicGame::DisplayBoard() const
{
	int i = 0, j = 0;
	printf("     A   B   C   \n");
	printf("    ___________  \n");
	printf(" 1 | %c | %c | %c | \n", Game[0][0], Game[0][1], Game[0][2]);
	printf("   |___|___|___| \n");
	printf(" 2 | %c | %c | %c | \n", Game[1][0], Game[1][1], Game[1][2]);
	printf("   |___|___|___| \n");
	printf(" 3 | %c | %c | %c | \n", Game[2][0], Game[2][1], Game[2][2]);
	printf("   |___|___|___| \n");
}

void TicGame::SwapPlayer()
{
	if (PlayerTurn == 'X')
		PlayerTurn = 'O';
	else
		PlayerTurn = 'X';
}

TicGame::~TicGame()
{
}