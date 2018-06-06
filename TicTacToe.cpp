// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void PrintUI(TicGame);

int main()
{
	while (1)
	{
		TicGame Game;
		PrintUI(Game);
		bool ValidInput = true;
		while (ValidInput)
		{
			ValidInput = Game.PlayTurn(); // Takes and validates input
		}

		// Check winning conditions
		// Make next move

		// Replay 
		cout << "Do you want to play again? (Y/N) ";
		char Choice;
		cin >> Choice;
		if (toupper(Choice) == 'N')
			break;
		else
			cout << "\n\n";
	}
	return 0;
}

// Displays current turn and Game state
void PrintUI(TicGame Game)
{
	cout << "\n\tTic-Tac-Toe\n";
	cout << " Player A: " << Game.GetScoreA() << "\tPlayer B: " << Game.GetScoreB() << endl;
	// cout << "\n Board: \n";
	Game.DisplayBoard();
}