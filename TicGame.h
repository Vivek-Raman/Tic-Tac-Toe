
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
	TooLong
};

class TicGame
{

public:
	TicGame();	//Constructor to set default values

	//Get functions
	int GetScoreX() const;
	int GetScoreY() const;
	char GetPlayerTurn() const;

	int PlayTurn();	//TODO: Improve return value
	EInputErrorType ValidatedInput(char[]);
	void DisplayBoard() const;
	bool IsGameDone();

	~TicGame();

private:
	char Game[3][3];
	char PlayerTurn;
	Input InputCoords;
	int ScoreX;
	int ScoreY;

	void SwapPlayer();
	void SplitInput(char[]);
};
