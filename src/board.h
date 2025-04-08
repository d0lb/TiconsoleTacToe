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

void initBoard(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const char board[3][3]){
    clearTerminal();
    printf("\n");
    printf(" -- -- --\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("| %c", board[i][j]);
        }
        printf("|");
        printf(" \n");
    }
    printf(" -- -- --\n");
}

void setASymbol(char board[3][3], char symbol){
    int num1, num2;
    scanf(" %d %d", &num1, &num2);
    if(board[num1][num2] == 'X' || board[num1][num2] == 'O' || num1 > 2 || num1 < 0 || num2 > 2 || num2 < 0){
        printf("Please enter the correct coordinates!\n");
        setASymbol(board, symbol);
        return;
    }else{
        board[num1][num2] = symbol;
    }
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