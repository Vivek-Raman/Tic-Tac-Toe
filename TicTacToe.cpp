// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void PrintUI();

TicGame Game;
int main()
{
	PrintUI();
	
	// Check winning conditions
	// Make next move
	// Check board spaces
	return 0;
}

// Displays current turn and Game state
void PrintUI()
{
	cout << "Tic-Tac-Toe\n";
	cout << "Player X: " << Game.GetScoreX() << "\nPlayer Y: " << Game.GetScoreY() << endl;
	cout << "\nBoard: \n";
	Game.DisplayBoard();
	cout << endl << Game.GetPlayerTurn() << "'s turn.\n";
	cout << "Make your move: "; //TODO: Dear lord, learn English!
}