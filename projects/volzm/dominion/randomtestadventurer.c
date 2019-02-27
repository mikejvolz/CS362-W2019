/*
 * Author:  Michael Volz
 * Date:    2/23/2019
 * File:    randomtestadventurer.c
 * Description:  A simple program that tests the Adventurer card
 *               using random methodologies.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define TESTCARD "adventurer"

int main (int argc, char* argv[]) {
  //srand(time(NULL));
  int totalErrorCount = 0;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int player=0;
  struct gameState test_hand1, test_hand2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
  int count1 = 0;
  int count2 = 0;
	
  printf("\n----------Testing Card: %s----------\n",TESTCARD);

  srand(time(NULL));

  for(int idx = 1; idx <= 100; idx++) {
    int numPlayers = (rand() % 50);
    int seed = (rand() % 10000);

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
    cardEffect(adventurer, choice1, choice2, choice3, &test_hand1, handpos, &bonus);
    player = whoseTurn(&test_hand2);
		
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

    //Check players hand
    if(test_hand1.hand[player][test_hand2.handCount[player]] == -1) {
      printf("Error: %s card was not added to the player's hand\n",TESTCARD);
      totalErrorCount++;
    }

    // check .playedCardCount expecteation
    if(test_hand2.playedCardCount+2 != test_hand1.playedCardCount) {
      printf("Error: player did not play %s card\n",TESTCARD);
      totalErrorCount++;
    }

    //Count Adventurer cards in hand
    for (int idx = 0; idx < test_hand1.handCount[0]; idx++)
      if(test_hand1.hand[0][idx] == "adventurer")
        count1++;

    for (int idx = 0; idx < test_hand2.handCount[0]; idx++)
      if(test_hand2.hand[0][idx] == "adventurer")
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

	
  }

  printf("----------End Testing Card: %s----------\n",TESTCARD);
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);

}
