// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void PrintUI();

TicGame Game;
int main()
{
	PrintUI();
	Game.PlayTurn();

	// Check winning conditions
	// Make next move
	// Check board spaces
	return 0;
}

// Displays current turn and Game state
void PrintUI()
{
	cout << "Tic-Tac-Toe\n";
	cout << "Player A: " << Game.GetScoreA() << "\nPlayer B: " << Game.GetScoreB() << endl;
	cout << "\nBoard: \n";
	Game.DisplayBoard();
	cout << endl << Game.GetPlayerTurn() << "'s turn.\n";
	cout << "Make your move: "; //TODO: Dear lord, learn English!
}