#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>

void displayBoard(char board[3][3]){
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %c", board[i][j]);
        }
        printf(" \n");
    }
}

char checkWinConditions(char board[3][3]){
    if(board[1][0] == board[1][1] && board[1][0] == board[1][2]){
        return board[1][0];
    }else if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
        return  board[0][0];
    }else if (board[2][0] == board[2][1] && board[2][0] == board[2][2]) {
        return board[2][0];
    }else if (board[]) {
    
    }
}

#endif