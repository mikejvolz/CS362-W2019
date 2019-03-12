/*
 * Author:  Michael Volz
 * Date:    2/1/2019
 * File:    unittest3.c
 * Description:  A simple program that tests the whoseTurn function
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv)	
{
  struct gameState state1;
  struct gameState state2;
  state1.whoseTurn = 1;
  state2.whoseTurn = 2;
  int totalErrorCount = 0;

  printf("\n----------Testing whoseTurn function----------\n");

  if(whoseTurn(&state1) != 1) {
    printf("Error: current player is incorrect. Expected player 1, current player is player %d\n", state1.whoseTurn);
    totalErrorCount++;
  }

  if(whoseTurn(&state2) != 2) {
    printf("Error: current player is incorrect. Expected player 2, current player is player %d\n", state2.whoseTurn);
    totalErrorCount++;
  }

  printf("----------End Testing whoseTurn function----------\n");
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);

}
