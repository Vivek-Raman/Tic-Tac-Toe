
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

class TicGame
{

public:
	TicGame();	//Constructor to set default values

	//Get functions
	int GetScoreA() const;
	int GetScoreB() const;
	char GetPlayerTurn() const;

	void PlayTurn();
	EInputErrorType ValidatedInput(char[]);
	void DisplayBoard() const;

	~TicGame();

private:
	char Game[3][3];
	char PlayerTurn;
	Input InputCoords;
	int ScoreA;
	int ScoreB;

	void SwapPlayer();
	void SplitInput(char[]);
	void AddTurn();
	bool EndGame();
};
