#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <stdlib.h>

void clearTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void displayBoard(const char board[3][3]){
    clearTerminal();
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %c", board[i][j]);
        }
        printf(" \n");
    }
}

void setASymbol(char board[3][3], int num1, int num2, char symbol){
    board[num1][num2] = symbol;
}

char checkWinConditions(const char board[3][3], const int steps){
    //string check
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' '){
            return board[i][0];
        }
    }

    //columns check
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' '){
            return board[0][i];
        }
    }

    //diagonal check

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    if(steps == 9){
        return 'D'; //Draw
    }

    return 'N'; //game continues
}

#endif