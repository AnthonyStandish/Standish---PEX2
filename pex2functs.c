/** pex2functs.c
 * =============================================================
 * Name: Anthony Standish
 * Section:  T6/7
 * Project:  PEX2
 * Purpose:  Blackjack
 * ============================================================= */

#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pex2functs.h"

#define MAX_LENGTH 20 // The max length of all string variables
#define MAX_RAND 13 // The maximum value for the random number generator

void playGame() {
    srand(time(0)); // Initializes the seed for the random number generator as the current time
    char playerName[MAX_LENGTH]; // Initializes the playerName variable with a max length 50
    char dealerName[MAX_LENGTH]; // Initializes the dealerName variable with a max length 50

    printf("\n\nWELCOME TO C3C STANDISH'S SPECIAL EDITION OF BLACKJACK!\n\n");
    printf("=========================================================================\n\n");
    printf("Enter Player 1 Name: ");
    scanf("%s", playerName);
    printf("Enter Player 2 Name: ");
    scanf("%s", dealerName);

    // Plays the entire game of Blackjack for both players and records the scores
    int playerScore = playBlackjack(playerName);
    int dealerScore = playBlackjack(dealerName);

    // Determines the winner based on final scores
    int winnerInt = getWinningPlayer(playerScore, dealerScore);
    if (winnerInt == 1) {
        printf("%s won!\n", playerName);
    } else if (winnerInt == 2) {
        printf("%s won!\n", dealerName);
    } else if (winnerInt == 3) {
        printf("The game is a tie!\n");
    } else if (winnerInt == 0) {
        printf("Both players lose!\n");
    }
    return;
}
int playBlackjack(char* playerName) {
    bool goPlay = true; // The game continues only if this variable is true.
                        // When the turn is over, this variable becomes false.
    int nextCard = 0;   // This variable is the value of the next card.

    int startCard1 = getNextCard();
    int startCard2 = getNextCard();
    int total = startCard1 + startCard2; // The variable 'total' begins with the
                                         // two start cards and subsequent cards   
                                         // are added to it as the game progresses

    // Print the header of the player's turn (once)
    printf("\n\n========================================\n");
    printf("PLAYER TURN: %s\n", playerName);
    printf("========================================\n\n");

    // Print the starting two cards
    printf("Welcome, %s!\n\n", playerName);
    printf("Your starting cards are %d and %d.\n\n", startCard1, startCard2);

    // This loop only executes at the beginning of the turn, or if the player 'hits'
    while (goPlay == true) {

        displayGameState(playerName, total);

        // These if/else if statements check if there is a blackjack or if the player has busted.
        // In either case, an appropriate statement is printed and the game ends.
        if (total == 21) {
            printf("\tBlackjack! Congradulations %s!\n\n", playerName);
            goPlay = false;

        } else if (total > 21) {
            printf("\tBusted! Better luck next time.\n\n");
            goPlay = false;
        }

        // This if statement only executes if the game has not ended.
        if (goPlay == true) {
            printf("\n\nDo you want to hit (h) or stay (s)?\n");

            char inputChar = getCharSafe(); // This variable is the reading of the user's input

            // This if statement executes if the player 'hits'
            if (inputChar == 'h') {
                nextCard = getNextCard();
                printf("Your next card: %d\n\n", nextCard);
                total += nextCard;

            // This else if statement executes if the player 'stays'
            } else if (inputChar == 's') {
                goPlay = false;
            }
        }
    }
    printf("Turn complete. %s ends the game with a total of %d\n\n", playerName, total);


    return total;
}

int getNextCard() {
    int nextCardNum = 0; // This initializes the variable that holds the value of the next card
    
    nextCardNum = rand() % 13 + 1;

    // This if statement sets the value of the next card to 10 if the random number is above 10
    // i.e. if the card is a jack, queen, or king.
    if (nextCardNum > 10) {
        nextCardNum = 10;

    // This else if statement sets the value of the next card to 11 if the random number is 1 (ace)
    } else if (nextCardNum == 1) {
        nextCardNum = 11;
    }

    // If the random number is not above 10 or equal to 1, the function just returns the value
    // itself. This results in a 1/13 chance for numbers 2-9, a 1/13 chance for 11, and a 4/13 
    // chance for each number above 9.
    return nextCardNum;
}

double getProbabilityOfValueOrLower(int desiredValue) {
    double probabilityOfStay = 0; // This initializes the value of the probability

    // This if statement determines the probability for cards valued 2-9
    if ((desiredValue <= 9) && (desiredValue > 1)) {
        probabilityOfStay = (((desiredValue - 1) * ((double)4/52)) * 100);
    
    // This else statement determines the probability for cards valued 10 (10, J, Q, K)
    // The probability of drawing a card valued 10 or less is always 48/52, because there
    // are only 4 cards valued above 10 (the four aces).
    } else if (desiredValue == 10) {
        probabilityOfStay = (((double)48/52) * 100);

    // The probability of drawing a card valued 11 or less is 100%, because all cards are valued
    // 11 or less
    } else if (desiredValue >= 11) {
        probabilityOfStay = 100;

    // This statement will only execute if the desired value is 1. Because no card is valued 1,
    // the probability success in this case is always zero.
    } else {
        probabilityOfStay = 0;
    }

    return probabilityOfStay;
}

char getCharSafe() {
    char input[1];
    bool inputValid = false;

    do {
    scanf(" %c", input);
 
    if (strncmp(input, "h", 1) == 0) {
        return 'h';
        inputValid = true;
    } else if (strncmp(input, "s", 1) == 0) {
        return 's';
        inputValid = true;
    } else {
        printf("INVALID INPUT, TRY AGAIN\n");
    }
    } while (inputValid == false);

    // 'return 'z';' is a case that will never execute, because all possible cases
    // are covered in the above if statements. This line of code exists so the
    // compiler does not show an error.
    return 'z';
}

void displayGameState(char* playerName, int playerScore) {
    printf("%s, your current total is: %d\n", playerName, playerScore);

    // these if/else if statements determine if the player's total is busted or
    // a blackjack. In either case, the function terminates.
    if (playerScore == 21) {
        return;
    } else if (playerScore > 21) {
        return;

    } else {
        printf("\nYour next card needs to be less than %d to stay in the game.\n", (21 - playerScore)); 

        double probabilityOfStay = getProbabilityOfValueOrLower((21 - playerScore));

        printf("\tThe probability of this happening on the next hit is: %0.2lf", probabilityOfStay);
    }

    return;
}

int getWinningPlayer(int player1Score, int player2Score) {
    if ((player1Score > 21) && (player2Score > 21)) {
        return 0;
    } else if ((player1Score <= 21) && (player2Score <= 21)) {
        if (player1Score > player2Score) {
            return 1;
        } else if (player2Score > player1Score) {
            return 2;
        } else {
            return 3;
        }
    } else {
        if (player1Score <= 21) {
            return 1;
        } else if (player2Score <= 21) {
            return 2;
        }
    }

    // 'return 4;' will never execute, because all possible cases are
    // covered in the above if/else if/else statements. This line of
    // code exists so the compiler does not show an error.
    return 4;
}