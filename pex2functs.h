/** pex2functs.h
 * =============================================================
 * Name: Anthony Standish
 * Section:  T6/7
 * Project:  PEX 2
 * Purpose:  Blackjack
 * ============================================================= */

/**
 * @brief plays the game of blackjack
 * @param // no parameters
 * @pre N/A
 * @post the game of Blackjack is played
 * @return void
 */
void playGame();

/**
 * @brief gets a single character input from the user
 * @param // no parameters
 * @pre N/A
 * @post N/A
 * @return the character read from the keyboard, or terminates if unsuccessful input
 */
char getCharSafe();

/**
 * @brief randomly selects a card from the deck
 * @param // no parameters
 * @pre N/A
 * @post N/A
 * @return the integer value of the selected card
 */
int getNextCard();

/**
 * @brief determines the probability that the next card drawn will result in a total equal to or
 *        less than 21
 * @param desiredValue the difference between 21 and the player's current total
 * @pre N/A
 * @post N/A
 * @return the probability that the next card drawn will result in a total equal to or
 *        less than 21
 */
double getProbabilityOfValueOrLower(int desiredValue);

/**
 * @brief displays the current game state, including the player's total, the highest card that a
 *        player can hit to stay in the game
 * @param playerName the name of the current player
 * @param playerScore the score of the current player
 * @pre player's current total must be <= 20
 * @post N/A
 * @return void
 */
void displayGameState(char* playerName, int playerScore);

/**
 * @brief determines the winning player
 * @param player1Score the score of player 1 (Player)
 * @param player2Score the score of player 2 (Dealer)
 * @pre the game must be complete
 * @post N/A
 * @return 1 if player 1 wins, 2 if player 2 wins, 3 if the scores are equal and both <=21,
 *         or 0 if neither player wins (both bust)
 */
int getWinningPlayer(int player1Score, int player2Score);

/**
 * @brief plays the entire game of blackjack for a given player
 * @param playerName the name of the player/dealer
 * @pre the player must exist
 * @post N/A
 * @return the current player's total
 */
int playBlackjack(char* playerName);