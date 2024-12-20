#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateComputerMove() {
    return rand() % 3; 
}

void determineWinner(int playerMove, int computerMove) {
    if (playerMove == computerMove) {
        printf("It's a tie!\n");
    } else if ((playerMove == 0 && computerMove == 2) ||
               (playerMove == 1 && computerMove == 0) ||
               (playerMove == 2 && computerMove == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    int playerMove;

    srand(time(NULL)); 

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("0: Rock, 1: Paper, 2: Scissors\n");
    printf("You have 5 chances!\n");

    for (int i = 0; i < 5; i++) {
        printf("Enter your move: ");
        scanf("%d", &playerMove);

        if (playerMove < 0 || playerMove > 2) {
            printf("Invalid move. Please enter a number between 0 and 2.\n");
            continue;  
        }

        int computerMove = generateComputerMove();

        printf("You chose: %d\n", playerMove);
        printf("Computer chose: %d\n", computerMove);

        determineWinner(playerMove, computerMove);
    }

    return 0;
}
