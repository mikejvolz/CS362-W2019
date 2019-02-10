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

  struct gameState state, test;
  int k[10] = {7, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &state);

  printf("\n----------Testing Card: %s----------\n",TESTCARD);

  memcpy(&test, &state, sizeof(struct gameState));
  adventurerFunc(handpos, player, &state,0,0,0);
//cardEffect(TESTCARD, choice1, choice2, choice3, &state, handpos, &bonus);

  // Check the deck count
  if(test.deckCount[player]-1 != state.deckCount[player]) {
    printf("Error: deck count is incorrect\n");
    totalErrorCount++;
  }

  // Check the player's hand count
  if(test.handCount[player]-1 != state.handCount[player]) {
    printf("Error: hand count is not correct\n");
    totalErrorCount++;
  }

  // Check player's hand
  if(state.hand[player][test.handCount[player]] == -1) {
    printf("Error: %s card was not added to the player's hand\n",TESTCARD);
    totalErrorCount++;
  }

  // check .playedCardCount expecteation
  if(test.playedCardCount+2 != state.playedCardCount) {
    printf("Error: player did not play %s card\n",TESTCARD);
    totalErrorCount++;
  }

  // Count Adventurer cards in hand
  for (int idx = 0; idx < state.handCount[0]; idx++)
    if(state.hand[0][idx] = TESTCARD)
      count1++;

  for (int idx = 0; idx < test.handCount[0]; idx++)
    if(test.hand[0][idx] = TESTCARD)
      count2++;

  // check previous counts
  if(count1 != count2-1) {
    printf("Error: there is a discrepency in %s cards\n",TESTCARD);
    totalErrorCount++;
  }

  // check for discard count
  if(test.discardCount[player] != state.discardCount[player]) {
    printf("Error: the %s was not discarded.\n",TESTCARD);
    totalErrorCount++;
  }

  // check for properly added actions
  if(test.numActions+2 != state.numActions) { 
    printf("Error: two additional actions were not added\n");
    totalErrorCount++;
  }

  printf("----------End Testing Card: %s----------\n",TESTCARD);
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);
}
