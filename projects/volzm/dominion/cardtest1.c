/*
 * Author:  Michael Volz
 * Date:    2/1/2019
 * File:    cardtest2.c
 * Description:  A simple program that tests the Smithy card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TESTCARD "smithy"

int main (int argc, char* argv[])
{
  int totalErrorCount = 0;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int seed = 1000;
  int numPlayers = 2;
  int player=0;
  struct gameState hand1, hand2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  int count1 = 0;
  int count2 = 0;

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &hand1);

  printf("\n----------Testing Card: %s----------\n",TESTCARD);

  // copy the game state to a hand2 case
  memcpy(&hand2, &hand1, sizeof(struct gameState));
  smithyFunc(handpos, player, &hand1);

  // Check the player's hand count
  if(hand2.handCount[player]+2 != hand1.handCount[player]) {
    printf("Error: hand count is incorrect: expected %d, observed %d\n",(hand2.handCount[player]+2),hand1.handCount[player]);
    totalErrorCount++;
  }

  // Check player's actual hand
  if(hand1.hand[player][hand2.handCount[player]] == -1) {
    printf("Error: %s card was not added to the players hand\n",TESTCARD);
    totalErrorCount++;
  }

  // check the discard count
  if(hand2.discardCount[player] != hand1.discardCount[player]) {
    printf("Error: the %s was not discarded.\n",TESTCARD);
    totalErrorCount++;
  }

  printf("----------End Testing Card: %s----------\n",TESTCARD);
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);

}
