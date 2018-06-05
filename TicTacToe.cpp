// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

TicGame Game;
int main()
{
	PrintUI();
	
	// Check winning conditions
	// Make next move
	// Chicken dinner?
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
	cout << "Enter input: "; //TODO: Dear lord, learn English!
}