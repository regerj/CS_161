#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/***********************************************************************************
 **  Program: Assignment_5.cpp
 **  Author: Jacob Reger
 **  Date: 12/8/2019
 **  Description: This program has the goal of taking input from the user as command
 **  line arguments and setting up a connect 4 game based on those parameters. It
 **  will be able to play 1 player or 2 player, and will have an unintelligent ai to
 **  play against in 1 player. It should function exactly how connect 4 does in real
 **  life, but should be limited to a 20 X 20 board at max.
 **  Input: Input will include command line arguments for the player count, column
 **  count, and row count. This will be followed by inputs on whether or not the user
 **  wants to move first in single player, where each user wants to move, and if the
 **  user wants to play again. Error handling inputs will also be present.
 **  Output: Outputs of the following functions will display the board after each 
 **  turn, as well as specific instructions for the user to input each time. Finally
 **  the program will output if a win is detected and who won.
 ***********************************************************************************/

void display_board(int rows, int cols, char ** board);
char ** create_board(int rows, int cols);
void player_move(char ** board, int player, int rows, int cols);
void two_player(int rows, int cols);
bool is_win(char ** board, int rows, int cols);
void one_player(int rows, int cols);
void argv_error(char ** argv);
void argc_error(char ** argv, int argc);
void one_player_first(int rows, int cols, char ** board);
void one_player_second(int rows, int cols, char ** board);
void argv1(char ** argv1);
void argv2(char ** argv2);
void argv3(char ** argv3);
void player1move(char ** board, int rows, int cols);
void player2move(char ** board, int rows, int cols);
void clear_memory (char ** board, int rows);
void again_error(char * again);
bool is_tie(char ** board, int cols);

int main(int argc, char** argv){ 
   argc_error(argv, argc);
   argv_error(argv);
   //cout << "finished error handling command line!" << endl;
   int player_count = atoi(argv[1]);
   int rows = atoi(argv[3]);
   int cols = atoi(argv[2]);
   //cout << "Made it past row and col init" << endl;
   char again[30];
   if(player_count == 2)
      do{
	 two_player(rows, cols);
	 cout << "Would you like to play again? (Enter 0 to play again, enter 1 to quit): ";
	 cin.getline(again, 30);
	 again_error(again);
      }while(again[0] == '0');
   else if(player_count == 1)
      do{
	 one_player(rows, cols);
	 cout << "Would you like to play again? (Enter 0 to play again, enter 1 to quit): ";
	 cin.getline(again, 30);
	 again_error(again);
      }while(again[0] == '0');
   return 0;
}

/***********************************************************************************
**  Function: is_tie
**  Description: Logic to detect whether the board has filled up without a win.
**  Parameters: char ** board, int cols
**  Pre-conditions: Take in the address to the board and the number of columns.
**  Post-conditions: No change in function.
***********************************************************************************/

bool is_tie(char ** board, int cols){

   for(int i = 0; i < cols; i++)
      if(board[0][i] == ' ')
	 return false;
   return true;
}

/***********************************************************************************
 **  Function: again_error
 **  Description: Detect an errror in the user input and correct it.
 **  Parameters: char * again
 **  Pre-conditions: Take in the address to the again.
 **  Post-conditions: Re prompt user for again and change it.
 ***********************************************************************************/

void again_error(char * again){
   while(again[0] != '0' && again[0] != '1'){
      cout << "Invalid input! Please try again (0 to play again, 1 to quit): ";
      cin.getline(again, 30);
   }
}

/***********************************************************************************
 **  Function: clear_memory
 **  Description: Delete the heap memory after the game.
 **  Parameters: char ** board
 **  Pre-conditions: Take in the address to the board.
 **  Post-conditions: Free all heap memory and delete.
 ***********************************************************************************/

void clear_memory(char ** board, int rows){
   for(int i = 0; i < rows; i++)
      delete[] board[i];
   delete[] board;

}

/***********************************************************************************
 **  Function: argc_error
 **  Description: Will error handle too many or too few arguments into the main
 **  Parameters: char ** argv, int argc
 **  Pre-conditions: Take in the whole of argv and argc.
 **  Post-conditions: Error handle argv, will not change argv in this function, will
 **  set arg v back to 4.
 ***********************************************************************************/

void argc_error(char ** argv, int argc){
   if(argc != 4){
      argc = 4;
      cout << "You input an invalid number of arguments! Please re-enter them!" << endl;
      argv_error(argv);
   }
}

/***********************************************************************************
 **  Function: argv1 
 **  Description: will error handle the first argv.
 **  Parameters: char ** argv
 **  Pre-conditions: Take in the whole of argv.
 **  Post-conditions: Will change argv1 to a valid value.
 ***********************************************************************************/

void argv1(char ** argv){
   while(argv[1][0] != '1' && argv[1][0] != '2'){
      cout << "Invalid player count! Please retry (1 or 2 players): ";
      cin.getline(argv[1], 30);
   }
}

/***********************************************************************************
 **  Function: argv2 
 **  Description: will error handle the second argv.
 **  Parameters: char ** argv
 **  Pre-conditions: Take in the whole of argv.
 **  Post-conditions: Will change argv2 to a valid value.
 ***********************************************************************************/

void argv2(char ** argv){
   while(atoi(argv[2]) < 1 || atoi(argv[2]) > 20){
      cout << "Invalid number of columns! Please re-enter a column count between 1 and 20: ";
      cin.getline(argv[2], 30);
   }
}

/***********************************************************************************
 **  Function: argv3
 **  Description: will error handle the third argv.
 **  Parameters: char ** argv
 **  Pre-conditions: Take in the whole of argv.
 **  Post-conditions: Will change argv3 to a valid value.
 ***********************************************************************************/

void argv3(char ** argv){
   while(atoi(argv[3]) < 1 || atoi(argv[3]) > 20){
      cout << "Invalid number of rows! Please re-enter a row count between 1 and 20: ";
      cin.getline(argv[3], 30);
   }
}

/***********************************************************************************
 **  Function: argv_error
 **  Description: Just a hub to execute error handling of all 3 argv.
 **  Parameters: char ** argv
 **  Pre-conditions: Take in the whole of argv.
 **  Post-conditions: No change in function.
 ***********************************************************************************/

void argv_error(char ** argv){
   argv1(argv);
   argv2(argv);
   argv3(argv);
}

/***********************************************************************************
 **  Function: one_player_first
 **  Description: Function to execute one player game where user plays first.
 **  Parameters: int rows, int cols, char ** board
 **  Pre-conditions: Take in the array boundaries and the board values.
 **  Post-conditions: No change in function.
 ***********************************************************************************/

void one_player_first(int rows, int cols, char ** board){
   bool win;
   do{
      display_board(rows, cols, board);
      if(is_win(board, rows, cols) == true){
	 cout << "Uh oh! You lost!" << endl;
	 win = true;
	 break;
      }
      if(is_tie(board, rows) == true){
	 cout << "It's a tie!" << endl;
	 win = true;
	 break;
      }
      player_move(board, 1, rows, cols);
      display_board(rows, cols, board);
      if(is_win(board, rows, cols) == true){
	 cout << "Congratulations! You win!" << endl;
	 win = true;
	 break;
      }
      if(is_tie(board, rows) == true){
	 cout << "It's a tie!" << endl;
	 win = true;
	 break;
      }
      player_move(board, 3, rows, cols);
   }
   while(win == false);
}

/***********************************************************************************
 **  Function: one_player_second
 **  Description: Function to execute one player game where user plays second.
 **  Parameters: int rows, int cols, char ** board
 **  Pre-conditions: Take in the array boundaries and the board values.
 **  Post-conditions: No change in function.
 ***********************************************************************************/

void one_player_second(int rows, int cols, char ** board){
   bool win;
   do{
      display_board(rows, cols, board);
      if(is_win(board, rows, cols) == true){
	 cout << "Congratulations! You win!" << endl;
	 win = true;
	 break;
      }
      if(is_tie(board, rows) == true){
	 cout << "It's a tie!" << endl;
	 win = true;
	 break;
      }
      player_move(board, 3, rows, cols);
      display_board(rows, cols, board);
      if(is_win(board, rows, cols) == true){
	 cout << "Uh oh! You lost!" << endl;
	 win = true;
	 break;
      }
      if(is_tie(board, rows) == true){
	 cout << "It's a tie!" << endl;
	 win = true;
	 break;
      }
      player_move(board, 1, rows, cols);
   }
   while(win == false);
}

/***********************************************************************************
 **  Function: one_player
 **  Description: Hub to ask user if they want to play first in single player and 
 **  create a board to play on.
 **  Parameters: int rows, int cols
 **  Pre-conditions: Take in the array boundaries.
 **  Post-conditions: No change in function.
 ***********************************************************************************/

void one_player(int rows, int cols){
   char first[2];
   char ** board = create_board(rows, cols);
   cout << "Would you like to go first? (0 for yes, 1 for no): ";
   cin.getline(first, 20);
   while(first[0] != '0' && first[0] != '1'){
      cout << "Invalid input! Please enter a '0' to play first or a '1' to have the computer play first: ";
      cin.getline(first, 20);
   }
   if(first[0] == '0'){
      one_player_first(rows, cols, board);
   }else if(first[0] == '1'){
      one_player_second(rows, cols, board);
   }
   clear_memory(board, rows);
}

/***********************************************************************************
 **  Function: is_win
 **  Description: Logic to detect if a win is present.
 **  Parameters: char ** board, int rows, int cols
 **  Pre-conditions: Take in the array boundaries and the board values.
 **  Post-conditions: No change in function.
 ***********************************************************************************/

bool is_win(char ** board, int rows, int cols){
   //Vertical win test
   for(int i = 0; i < rows - 3; i++)
      for(int j = 0; j < cols; j++)      
	 if(board[i][j] != ' ' && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j])
	    return true;
   //Horizontal win test
   for(int j = 0; j < cols -3; j++)
      for(int i = 0; i < rows; i++)
	 if(board[i][j] != ' ' && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3])
	    return true;
   //Diagonal win test down right
   for(int i = 0; i < rows-3; i++)
      for(int j = 0; j < cols-3; j++)
	 if(board[i][j] != ' ' && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3])
	    return true;
   //Diagonal win test down left
   for(int i = 0; i < rows-3; i++)
      for(int j = 3; j < cols; j++)
	 if(board[i][j] != ' ' && board[i][j] == board[i+1][j-1] && board[i][j] == board[i+2][j-2] && board[i][j] == board[i+3][j-3])
	    return true;
   return false;
}

/***********************************************************************************
 **  Function: two_player
 **  Description: Hub to initialize board and control alternating player moves in two 
 **  player.
 **  Parameters: int rows, int cols
 **  Pre-conditions: Take in the array boundaries.
 **  Post-conditions: No change in function.
 ***********************************************************************************/

void two_player(int rows, int cols){
   bool win = false;
   char ** board = create_board(rows, cols);
   do{
      display_board(rows, cols, board);
      if(is_win(board, rows, cols) == true){
	 cout << "Congratulations! Player 2 wins!" << endl;
	 win = true;
	 break;
      }
      if(is_tie(board, rows) == true){
	 cout << "It's a tie!" << endl;
	 win = true;
	 break;
      }
      player_move(board, 1, rows, cols);
      display_board(rows, cols, board);
      if(is_win(board, rows, cols) == true){
	 cout << "Congratulations! Player 1 wins!" << endl;
	 win = true;
	 break;
      }
      if(is_tie(board, rows) == true){
	 cout << "It's a tie!" << endl;
	 win = true;
	 break;
      }
      player_move(board, 2, rows, cols);
   }
   while(win == false);
   clear_memory(board, rows);
}

/***********************************************************************************
 **  Function: player1move
 **  Description: Executes and error handles a move for player 1.
 **  Parameters: char ** board, int rows, int cols
 **  Pre-conditions: Take in the array boundaries and the board values.
 **  Post-conditions: Change the board value at the chosen play location to be the
 **  first players piece.
 ***********************************************************************************/

void player1move(char ** board, int rows, int cols){
   char temp[30];
   int play = 0;
   do{
      do{
	 if(play < 0 || play > cols - 1)
	    cout << "Invalid column choice! Please try again." << endl;
	 cout << "Player 1 turn! Where would you like to play (must be a valid column number): ";
	 cin.getline(temp, 30);
	 play = atoi(temp);
	 play = play - 1;
      }while(play < 0 || play > cols - 1);
      for(int i = rows - 1; i >= 0; i--)
	 if(board[i][play] != 'X' && board[i][play] != 'O'){
	    board[i][play] = 'X';
	    return; 
	 }
      cout << "That column is all filled up! Please play in another column!" << endl;
   }
   while(1);
}

/***********************************************************************************
 **  Function: player2move
 **  Description: Executes and error handles a move for player 2.
 **  Parameters: char ** board, int rows, int cols
 **  Pre-conditions: Take in the array boundaries and the board values.
 **  Post-conditions: Change the board value at the chosen play location to be the
 **  second players piece.
 ***********************************************************************************/

void player2move(char ** board, int rows, int cols){
   char temp[30];
   int play = 0;
   do{
      do{
	 if(play < 0 || play > cols - 1)
	    cout << "Invalid column choice! Please try again." << endl;
	 cout << "Player 2 turn! Where would you like to play (must be a valid column number): ";
	 cin.getline(temp, 30);
	 play = atoi(temp);
	 play = play - 1;
      }while(play < 0 || play > cols - 1);
      for(int i = rows - 1; i >= 0; i--)
	 if(board[i][play] != 'X' && board[i][play] != 'O'){
	    board[i][play] = 'O';
	    return; 
	 }
      cout << "That column is all filled up! Please play in another column: ";
   }while(1);
}

/***********************************************************************************
 **  Function: player_move
 **  Description: Hub to execute a move sequence for both two player and 1 player
 **  games. Includes simple code for unintelligent ai player.
 **  Parameters: char ** board, int player, int rows, int cols
 **  Pre-conditions: Take in the array boundaries, the board, and the current player.
 **  Post-conditions: Changes the value of a random play for the unintelligent ai
 **  if it is the ai turn to play, otherwise no change in function.
 ***********************************************************************************/

void player_move(char ** board, int player, int rows, int cols){
   if(player == 1){
      player1move(board, rows, cols);
   }
   else if(player == 2){
      player2move(board, rows, cols);
   }else{
      int move = rand() % cols;
      for(int i = rows - 1; i >= 0; i--)
	 if(board[i][move] != 'X' && board[i][move] != 'O'){	 
	    board[i][move] = 'O';
	    return;
	 }
   }
}

/***********************************************************************************
 **  Function: create_board
 **  Description: Initializes the board array.
 **  Parameters: int rows, int cols
 **  Pre-conditions: Take in the array boundaries.
 **  Post-conditions: No change in function.
 ***********************************************************************************/

char ** create_board(int rows, int cols){
   //cout << "creating board" << endl;
   char ** board = new char*[rows];
   for(int i = 0; i < rows; i++)
      board[i] = new char[cols];
   //cout << "made it past init of board" << endl;
   for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
	 board[i][j] = ' ';
   //cout << "successfully created board" << endl;
   return board;
}

/***********************************************************************************
 **  Function: display_board
 **  Description: Simple function to display board including pieces played.
 **  Parameters: int rows, int cols, char ** board
 **  Pre-conditions: Take in the array boundaries and the board values.
 **  Post-conditions: No change in function.
 ***********************************************************************************/

void display_board(int rows, int cols, char ** board){
   for(int i = 0; i < cols; i++){
      if(i < 9) 
	 cout << "  " << i + 1 << " ";
      else
	 cout << "  " << i + 1;
   }
   cout << endl;
   for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
	 if(i % 2 == 0 && j % 2 == 0)
	    cout << "|\033[30;47m " << board[i][j] << " ";
	 else if(i % 2 == 1 && j % 2 == 1)
	    cout << "|\033[30;47m " << board[i][j] << " ";
	 else
	    cout << "|\033[0m " << board[i][j] << " ";
	 cout << "\033[0m";
      }
      cout << endl;
   }
}
