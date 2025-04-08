#include <stdio.h>
#include "board.h"
#include <stdbool.h>

bool isRunning = true;
char board[3][3];

int num1, num2;
int steps;
int main(){
    printf("Welcome to multiplayer console TicTacToe Game!");
    while (isRunning){
        initBoard(board);
        steps = 0;
        printf("Starting the game... \n You both will have to enter two numbers,that means coordinates of a TicTacToe board (Example: 1 1 --- makes a symbol in the center) \n");
            
            while(steps < 9){

                printf("X's turn! \n");
                scanf(" %d %d", &num1, &num2);
                setASymbol(board, num1, num2, 'X');
                steps++;
                displayBoard(board);
                if(checkWinConditions(board, steps) == 'X'){
                    printf("X is a winner! \n ");
                    break;
                }else if(checkWinConditions(board, steps) == 'O'){
                    printf("O is a winner! \n ");
                    break;
                }else if(checkWinConditions(board, steps) == 'D'){
                    printf("Draw! \n ");
                    break;
                }
                //#################################

                printf("O's turn! \n");
                scanf(" %d %d", &num1, &num2);
                setASymbol(board, num1, num2, 'O');
                steps++;
                displayBoard(board);

                
                if(checkWinConditions(board, steps) == 'X'){
                    printf("X is a winner! \n ");
                    break;
                }else if(checkWinConditions(board, steps) == 'O'){
                    printf("O is a winner! \n ");
                    break;
                }else if(checkWinConditions(board, steps) == 'D'){
                    printf("Draw! \n ");
                    break;
                }
                
            }
    }

}