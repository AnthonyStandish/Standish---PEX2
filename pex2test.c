/** pex2test.c
 * =============================================================
 * Name: Anthony Standish
 * Section:  T6/7
 * Project:  PEX 2
 * Purpose:  Blackjack
 * ============================================================= */

#include "pex2functs.h"
#include <stdio.h>
#include <assert.h>

void runAllTests() {
    printf("Running all tests ... \n");

    assert((getNextCard() <= 11));
    assert(getProbabilityOfValueOrLower(11) == 100);
    assert(getProbabilityOfValueOrLower(1) == 0);
    assert(getWinningPlayer(21,20) == 1);
    assert(getWinningPlayer(22,22) == 0);
    assert(getWinningPlayer(20,20) == 3);
    assert(getWinningPlayer(19,21) == 2);

    printf("Testing complete\n");
}