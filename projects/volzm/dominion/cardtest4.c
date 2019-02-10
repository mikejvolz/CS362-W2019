/*
 * Author:  Michael Volz
 * Date:    2/1/2019
 * File:    cardtest4.c
 * Description:  A simple program that tests the Adventurer card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TESTCARD "adventurer"

int main (int argc, char* argv[])
{
  int totalErrorCount = 0;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int seed = 1000;
  int numPlayers = 2;
  int player=0;
  int count1=0;
  int count2=0;

  struct gameState test_hand1, test_hand2;
  int k[10] = {7, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &test_hand1);

  printf("\n----------Testing Card: %s----------\n",TESTCARD);

  memcpy(&test_hand2, &test_hand1, sizeof(struct gameState));
  cardEffect(adventurer, choice1, choice2, choice3, &test_hand1, handpos, &bonus);

  // Check the deck count
  if(test_hand2.deckCount[player]-1 != test_hand1.deckCount[player]) {
    printf("Error: deck count is incorrect\n");
    totalErrorCount++;
  }

  // Check the player's hand count
  if(test_hand2.handCount[player]-1 != test_hand1.handCount[player]) {
    printf("Error: hand count is not correct\n");
    totalErrorCount++;
  }

  // Check player's hand
  if(test_hand1.hand[player][test_hand2.handCount[player]] == -1) {
    printf("Error: %s card was not added to the player's hand\n",TESTCARD);
    totalErrorCount++;
  }

  // check .playedCardCount expecteation
  if(test_hand2.playedCardCount+2 != test_hand1.playedCardCount) {
    printf("Error: player did not play %s card\n",TESTCARD);
    totalErrorCount++;
  }

  // Count Adventurer cards in hand
  for (int idx = 0; idx < test_hand1.handCount[0]; idx++)
    if(test_hand1.hand[0][idx] = TESTCARD)
      count1++;

  for (int idx = 0; idx < test_hand2.handCount[0]; idx++)
    if(test_hand2.hand[0][idx] = TESTCARD)
      count2++;

  // check previous counts
  if(count1 != count2-1) {
    printf("Error: there is a discrepency in %s cards\n",TESTCARD);
    totalErrorCount++;
  }

  // check for discard count
  if(test_hand2.discardCount[player] != test_hand1.discardCount[player]) {
    printf("Error: the %s was not discarded.\n",TESTCARD);
    totalErrorCount++;
  }

  // check for properly added actions
  if(test_hand2.numActions+2 != test_hand1.numActions) { 
    printf("Error: two additional actions were not added\n");
    totalErrorCount++;
  }

  printf("----------End Testing Card: %s----------\n",TESTCARD);
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);
}
