
typedef int Coords[2];
class TicGame
{

public:
	TicGame();	//Constructor to set default values

	//Get functions
	int GetScoreX() const;
	int GetScoreY() const;

	int PlayTurn(int, bool);	//TODO: Improve return value
	bool IsGameDone();



	~TicGame();

private:
	char Game[3][3];
	Coords InputCoords;
	int ScoreX;
	int ScoreY;
};
