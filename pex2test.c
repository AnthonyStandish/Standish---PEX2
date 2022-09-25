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
#include <math.h>

void runAllTests() {
    printf("Running all tests ... \n");

    assert((getNextCard() <= 11));
    assert(getProbabilityOfValueOrLower(11) == 100);
    assert(round(getProbabilityOfValueOrLower(10)) == 92);
    assert(round(getProbabilityOfValueOrLower(9)) == 62);
    assert(round(getProbabilityOfValueOrLower(8)) == 54);
    assert(round(getProbabilityOfValueOrLower(7)) == 46);
    assert(round(getProbabilityOfValueOrLower(6)) == 38);
    assert(round(getProbabilityOfValueOrLower(5)) == 31);
    assert(round(getProbabilityOfValueOrLower(4)) == 23);
    assert(round(getProbabilityOfValueOrLower(3)) == 15);
    assert(round(getProbabilityOfValueOrLower(2)) == 8);
    assert(getProbabilityOfValueOrLower(1) == 0);
    assert(getWinningPlayer(21,20) == 1);
    assert(getWinningPlayer(22,22) == 0);
    assert(getWinningPlayer(20,20) == 3);
    assert(getWinningPlayer(19,21) == 2);

    printf("Testing complete\n");
}