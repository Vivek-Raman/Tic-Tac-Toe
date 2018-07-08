
struct Input
{
	int Row;
	int Column;
};

enum EInputErrorType
{
	OK,
	BadRow,
	BadColumn,
	BadBoth,
	TooLong,
	Occupied
};

enum EEndGameType
{
	RowWin,
	ColumnWin,
	DiagonalWin,
	False
};

class TicGame
{

public:
	TicGame();	//Constructor to set default values

	//Get functions
	int GetScoreA() const;
	int GetScoreB() const;
	char GetPlayerTurn() const;
	bool bIsGameOver() const;

	bool PlayTurn();
	EInputErrorType ValidatedInput(char[]);
	void DisplayBoard() const;
	EEndGameType EndGame();
	void AddTurn();

	~TicGame();

private:
	char Game[3][3];		// Game board
	char PlayerTurn;		// Next turn / winner indicator
	Input InputCoords;		
	bool GameOver;			
	int ScoreA;
	int ScoreB;

	void SwapPlayer();
	void SplitInput(char*);
};
