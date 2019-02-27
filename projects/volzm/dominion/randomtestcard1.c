/*
 * Author:  Michael Volz
 * Date:    2/23/2019
 * File:    randomtestadventurer.c
 * Description:  A simple program that tests the Villager card
 *               using random methodologies.
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "village"

int main (int argc, char* argv[]) {
  int totalErrorCount = 0;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int player=0;
  struct gameState test_hand1, test_hand2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy, council_room};

  printf("\n----------Testing Card: %s----------\n",TESTCARD);

  srand(time(NULL));

  for(int idx = 1; idx <= 100; idx++) {
    int numPlayers = (rand() % 2)+2;
    int seed = (rand() % 5000);
		
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &test_hand1);

    printf("\n----------Testing iteration %d/100----------\n",idx);

    // copy the game state to a test case
    memcpy(&test_hand2, &test_hand1, sizeof(struct gameState));

     // randomize choice inputs
    choice1 = (rand()%1000);
    choice2 = (rand()%1000);
    choice3 = (rand()%1000);

    // call the cardEffect method 
    cardEffect(village, choice1, choice2, choice3, &test_hand1, handpos, &bonus);
    player = whoseTurn(&test_hand2);
		
    //Check players hand
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

  }

  printf("----------End Testing Card: %s----------\n",TESTCARD);
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);
}
