#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINNING_POSITION 100

int rollDice() {
    return (rand() % 6) + 1;
}

int checkForSnakesOrLadders(int position) {
    // Snakes
    if (position == 16) return 6;
    if (position == 47) return 26;
    if (position == 49) return 11;
    if (position == 56) return 53;
    if (position == 62) return 19;
    if (position == 64) return 60;
    if (position == 87) return 24;
    if (position == 93) return 73;
    if (position == 95) return 75;
    if (position == 98) return 78;

    // Ladders
    if (position == 1) return 38;
    if (position == 4) return 14;
    if (position == 9) return 31;
    if (position == 21) return 42;
    if (position == 28) return 84;
    if (position == 36) return 44;
    if (position == 51) return 67;
    if (position == 71) return 91;
    if (position == 80) return 100;

    return position;
}

void printPosition(int player, int position) {
    printf("Player %d is at position %d\n", player, position);
}

int main() {
    srand(time(0));  // Seed random number generator

    int player1_position = 0;
    int player2_position = 0;
    int currentPlayer = 1;
    int diceRoll;

    while (player1_position < WINNING_POSITION && player2_position < WINNING_POSITION) {
        printf("Player %d's turn.\n", currentPlayer);
        
        diceRoll = rollDice();
        printf("Player %d rolled a %d\n", currentPlayer, diceRoll);

        if (currentPlayer == 1) {
            player1_position += diceRoll;
            player1_position = checkForSnakesOrLadders(player1_position);
            printPosition(1, player1_position);
            if (player1_position >= WINNING_POSITION) {
                printf("Player 1 wins!\n");
                break;
            }
            currentPlayer = 2;  // Switch turn to player 2
        } else {
            player2_position += diceRoll;
            player2_position = checkForSnakesOrLadders(player2_position);
            printPosition(2, player2_position);
            if (player2_position >= WINNING_POSITION) {
                printf("Player 2 wins!\n");
                break;
            }
            currentPlayer = 1;  // Switch turn to player 1
        }
    }

    return 0;
}

