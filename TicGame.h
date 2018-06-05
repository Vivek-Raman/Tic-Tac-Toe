
struct Input
{
	char Row;
	int Column;
};

class TicGame
{

public:
	TicGame();	//Constructor to set default values

	//Get functions
	int GetScoreX() const;
	int GetScoreY() const;
	char GetPlayerTurn() const;

	int PlayTurn(int);	//TODO: Improve return value
	bool ValidatedInput();
	void DisplayBoard();
	bool IsGameDone();

	~TicGame();

private:
	char Game[3][3];
	char PlayerTurn;
	Input InputCoords;
	int ScoreX;
	int ScoreY;
};
