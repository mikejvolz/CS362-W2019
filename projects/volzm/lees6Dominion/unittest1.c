/*
 * Author:  Michael Volz
 * Date:    2/1/2019
 * File:    unittest1.c
 * Description:  A simple program that tests the buyCard function
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
  int totalErrorCount = 0;
  struct gameState hand1, hand2, hand3;
  int supplyPos = 2;

  printf("\n----------Testing buyCard function----------\n");

  hand1.numBuys = 3;
  hand1.coins = 0;
  hand2.numBuys = 3;
  hand2.coins = 12;
  hand3.numBuys = 0;
  hand3.coins = 10;

  // call function with hand that has insufficient funds, but ability to purchase
  if(buyCard(supplyPos, &hand1) != -1) {
    printf("Error: player expected to have 0 coins (insufficient funds), but buyCard return was not expected (-1) value. Test hand how has %d coins.\n", hand1.coins);
    totalErrorCount++;
  }

  // call function with hand that has insufficient funds and the ability to purchase
  if(buyCard(supplyPos, &hand2) != 0) {
    printf("Error: player expected to have 10 coins (sufficient funds), but buyCard return was not expected (0) value. Test hand how has %d coins.\n", hand2.coins);
    totalErrorCount++;
  }

  // call function with hand that has sufficient funds, but does not have the ability to purchase
  if(buyCard(supplyPos, &hand3) != -1) {
    printf("Error: player expected to have 10 coins (sufficient funds) and no Buys, but buyCard return was not expected (-1) value. Test hand how has %d coins.\n", hand3.coins);
    totalErrorCount++;
  }

  printf("----------End Testing getCost function----------\n");
  if (totalErrorCount == 0) 
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);
}
