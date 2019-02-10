/*

 * Author:  Michael Volz
 * Date:    2/1/2019
 * File:    unittest4.c
 * Description:  A simple program that tests the updateCoins function
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
  int expected_number_of_coins = 0;
  struct gameState test_hand;

  printf("\n----------Testing updateCoins function----------\n");

  // testing set of copper
  for (int i = 0; i < 3; i++) {
    test_hand.hand[0][i] = copper;
    test_hand.handCount[0] += 1;
    expected_number_of_coins++;
  }
  updateCoins(0,&test_hand, 0);
  if(test_hand.coins != expected_number_of_coins) {
    printf("\nError: number of coins from Copper cards expected to be %d, but observed %d total coins.\n",expected_number_of_coins,test_hand.coins); 
    totalErrorCount++;
  }

  // testing set of silvers
  expected_number_of_coins = 0;
  test_hand.handCount[0] = 0;
  for (int i = 0; i < 2; i++) {
    test_hand.hand[0][i] = silver;
    test_hand.handCount[0] += 1;
    expected_number_of_coins += 2;
  }
  updateCoins(0,&test_hand, 0);
  if(test_hand.coins != expected_number_of_coins) {
    printf("\nError: number of coins from Silver cards expected to be %d, but observed %d total coins.\n",expected_number_of_coins,test_hand.coins);
    totalErrorCount++;
  }

  // testing set of golds
  expected_number_of_coins = 0;
  test_hand.handCount[0] = 0;
  for (int i = 0; i < 10; i++) {
    test_hand.hand[0][i] = gold;
    test_hand.handCount[0] += 1;
    expected_number_of_coins += 3;
  }
  updateCoins(0,&test_hand, 0);
  if(test_hand.coins != expected_number_of_coins) {
    printf("\nError: number of coins from Gold cards expected to be %d, but observed %d total coins.\n",expected_number_of_coins,test_hand.coins);
    totalErrorCount++;
  }

  // discard entire hand
  expected_number_of_coins = 5;
  for (int i = 0; i < test_hand.handCount[0]; i++){
    test_hand.discard[0][test_hand.discardCount[0]++] = test_hand.hand[0][i];
    test_hand.hand[0][i] = -1;
  }
  test_hand.handCount[0] = 0;

  // testint the copper bonus parameter
  updateCoins(0,&test_hand, expected_number_of_coins);
  if(test_hand.coins != expected_number_of_coins) {
    printf("\nError: number of coins expected to be %d, but observed %d total coins.\n",expected_number_of_coins,test_hand.coins);
    totalErrorCount++;
  }

  printf("----------End Testing updateCoins function----------\n");
  if (totalErrorCount == 0)
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);
}
