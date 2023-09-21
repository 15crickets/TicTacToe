/*
Author: Vikram Vasudevan
Date: 9/21/2023
Description: This program runs tic-tac-toe, and keeps track of each players' wins. 

 */

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//this calls the function that checks for wins.
bool checkWin(char board [4][4], char playable);

//main
int main(){
  //initializing board and variables
  char board [4][4];
  bool stillPlaying = true;
  bool firstTime = true;
  int move = 0;
  int numMoves = 0;
  int xWins = 0;
  int oWins = 0;
  char playable = 'X';

  //while loop that runs as long as the game is being played.
  while (stillPlaying == true){
    //if it is the first move of the game, clear board and set numMoves to 0.
      if(firstTime == true){
	numMoves = 0;
        for(int i = 0; i < 4; i++){
          for(int j = 0; j < 4; j++){
	    board[i][j] = ' ';
          }
        }
    }
    //add grid to board.
    board [0][1] = '1';
    board [0][2] = '2';
    board [0][3] = '3';
    board [1][0] = 'a';
    board [2][0] = 'b';
    board [3][0] = 'c';

    //print board
    if(firstTime == true){
      for(int i = 0; i< 4; i++){
        for(int j = 0; j<4; j++){
	  cout << board [i][j];
        }
        cout << endl;
      
      }
      firstTime = false;
    }
    //set player move
    if(move % 2 == 0){
      playable = 'X';
    }
    else if (move % 2 == 1){
      playable = 'O';
    }
    //get input
    int row = 0;
    char input[150];
    bool validMove = false;
    int column = 0;
    while (validMove == false){
      cin.get(input, 149);
      cin.get();
      //check that input is valid
      if(input[0] == 'a' && (input[1] == '1' || input[1] == '2' || input[1] == '3')){
	row = 1;
	column = int(input[1] - '0');
	validMove = true;
      }
      else if(input[0] == 'b' && (input[1] == '1' || input[1] == '2' || input[1] == '3')){
	row = 2;
	column = int (input[1] - '0');
	validMove = true;
      }
      else if (input[0] == 'c' && (input[1] == '1' || input[1] == '2' || input[1] == '3')){
	column = int (input[1] - '0');
	row = 3;
	validMove = true;
      }
      //check that the move has not already been played
      if(validMove == true){
	if(board[row][column] != ' '){
	  cout << "That spot is already taken" << endl;
	  validMove = false;
	}
      }
      if(validMove == false){
	cout << "Please enter a legal move" << endl;
      }

    }

    //add move to board
    board[row][column] = playable;
    numMoves++;
    //check if player has won
    bool hasWon = checkWin(board, playable);
    //this controls the display if a player has won or if there's a draw
    if(hasWon == true){
      for(int i = 0; i< 4; i++){
        for(int j = 0; j<4; j++){
	  cout << board [i][j];
        }
        cout << endl;
      
      }
      if(playable == 'X'){
	cout << "X Wins!!" << endl;
	xWins++;
      }
      else if(playable == 'O'){
	cout << "O Wins!!" << endl;
	oWins++;
      }
      cout << "X Wins: " << xWins << " O Wins: " << oWins << endl;
      cout << "Would you like to keep playing? y/n " << endl;
      char keepPlaying [4];
      cin.get(keepPlaying, 3);
      cin.get();
      if(keepPlaying[0] == 'y'){
	stillPlaying = true;
	firstTime = true;
      }
      else if (keepPlaying[0] == 'n'){
	stillPlaying = false;
      }
    }
    if(numMoves == 9 && checkWin(board, playable) == false){
      cout << "It's a draw!!" << endl;
      char keepPlaying [4];
      cin.get(keepPlaying, 3);
      cin.get();
      if(keepPlaying[0] == 'y'){
	stillPlaying = true;
	firstTime = true;
      }
      else if (keepPlaying[0] == 'n'){
	stillPlaying = false;
      }
      cout << "X Wins: " << xWins << " O Wins: " << oWins << endl;
    }

  
    if(stillPlaying != false){
      move++;
    }
    //draws board after move
    if(hasWon == false){
      for(int i = 0; i< 4; i++){
          for(int j = 0; j<4; j++){
	    cout << board [i][j];
          }
          cout << endl;
      
        }
    }

  }
  return 0;
}
//checks for wins
  bool checkWin ( char board [4][4], char playable){
    for(int i = 1; i < 4; i++){
      if(board[i][1] == playable && board[i][2] == playable && board[i][3] == playable){
	return true;
      }
      else if(board[1][i] == playable && board[2][i] == playable && board[3][i] == playable){
	return true;
      }
    }
    if(board[1][1] == playable && board[2][2] == playable && board[3][3] == playable){
      return true;
    }
    if(board[1][3] == playable && board[2][2] == playable && board [3][1] == playable){
      return true;
    }

    return false;
    
  }

  

