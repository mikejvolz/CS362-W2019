/*
 * Author:  Michael Volz
 * Date:    2/1/2019
 * File:    cardtest3.c
 * Description:  A simple program that tests the Great Hall card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TESTCARD "great_hall"

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

  memcpy(&test_hand2, &test_hand1, sizeof(struct gameState));
  cardEffect(great_hall, choice1, choice2, choice3, &test_hand1, handpos, &bonus);

  // Check the player's hand for card added by drawCard
  if(test_hand1.hand[player][test_hand2.handCount[player]-1] == -1) {
    printf("Error: %s card was not added to the player's hand\n",TESTCARD);
    totalErrorCount++;
  }

  // Check if playedCardCount increased
  if(test_hand2.playedCardCount+1 != test_hand1.playedCardCount) {
    printf("Error: player did not play %s card\n",TESTCARD);
    totalErrorCount++;
  }

  // check for discard count
  if(test_hand2.discardCount[player] != test_hand1.discardCount[player]) {
    printf("Error: the %s was not discarded.\n",TESTCARD);
    totalErrorCount++;
  }

  // check for properly added action
  if(test_hand2.numActions+1 != test_hand1.numActions) {
    printf("Error: an extra action was not added\n");
    totalErrorCount++;
  }

  printf("----------End Testing Card: %s----------\n",TESTCARD);
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);

}
