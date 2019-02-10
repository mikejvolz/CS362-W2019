/*
 * Author:  Michael Volz
 * Date:    2/1/2019
 * File:    cardtest2.c
 * Description:  A simple program that tests the Village card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TESTCARD "village"

int main (int argc, char* argv[])
{
  int totalErrorCount = 0;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int seed = 1000;
  int numPlayers = 2;
  int player=0;
  struct gameState test_hand1, test_hand2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &test_hand1);

  printf("\n----------Testing Card: %s----------\n",TESTCARD);

  // copy the game state to a test case
  memcpy(&test_hand2, &test_hand1, sizeof(struct gameState));

  // execute the card for test_hand1 and check for return value
  if(villageFunc(handpos,player,&test_hand1) != 0) {
    printf("Error: greathallFunc return was non-zero\n");
    totalErrorCount++;
  }
  player = whoseTurn(&test_hand2);

  // Check the player's hand count
  if(test_hand1.hand[player][test_hand2.handCount[player]-1] == -1) {
    printf("Error: %s card was not added to the players hand\n",TESTCARD);
    totalErrorCount++;
  }

  // check for discard count
  if(test_hand2.discardCount[player] != test_hand1.discardCount[player]) {
    printf("Error:  the %s was not discarded.\n",TESTCARD);
    totalErrorCount++;
  }

  // check for properly added actions
  if(test_hand1.numActions+2 != test_hand2.numActions) {
    printf("Error: exactly two extra actions were not added\n");
    totalErrorCount++;
  }

  printf("----------End Testing Card: %s----------\n",TESTCARD);
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);

}
