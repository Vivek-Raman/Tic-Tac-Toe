// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void PrintUI(TicGame);

int main()
{
	char Choice;
	do
	{
		TicGame Game;
		PrintUI(Game);
		bool ValidInput = false;
		while (ValidInput==0)
		{
			ValidInput = Game.PlayTurn(); // Takes and validates input
		}
		// Add validated input to board
		Game.AddTurn();

		// Check winning conditions
		// Make next move

		// Replay 
		cout << "Do you want to play again? (Y/N) ";
		cin >> Choice;
	} while (Choice == 'N');
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

// TODO: Check bIsGameOver() before taking PlayTurn()
// TODO: Fix Win condition checks
// TODO: Check win conditions after input and update GameOver

