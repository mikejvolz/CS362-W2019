/*

 * Author:  Michael Volz
 * Date:    2/1/2019
 * File:    unittest2.c
 * Description:  A simple program that tests the getCost function
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
  printf("\n----------Testing getCost function----------\n");

  for(int cardNumber = 0; cardNumber < 28; cardNumber++) {
    int returned = getCost(cardNumber);

    // testing each card, in turn, based on cardNumber index, and then invalid input
    switch(cardNumber) {
      case 0:  // Curse
        if (returned != 0) {
          printf("Error: getCost return for Curse is incorrect. Expected value is 0, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 1:  // Estate
        if (returned != 2) {
          printf("Error: getCost return for Estate is incorrect. Expected value is 2, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 2:  // Duchy
        if (returned != 5) {
          printf("Error: getCost return for Duchy is incorrect. Expected value is 5, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
          break;
      case 3:  // Province
        if (returned != 8) {
          printf("Error: getCost return for Province is incorrect. Expected value is 8, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 4:  // Copper
        if (returned != 0) {
          printf("Error: getCost return for Copper is incorrect. Expected value is 0, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 5:  // Silver
        if (returned != 3) {
          printf("Error: getCost return for Silver is incorrect. Expected value is 3, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 6:  // Gold
        if (returned != 6) {
          printf("Error: getCost return for Gold is incorrect. Expected value is 6, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 7:  // Adventure
        if (returned != 6) {
          printf("Error: getCost return for Adventure is incorrect. Expected value is 6, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 8:  // Council Room
        if (returned != 5) {
          printf("Error: getCost return for Council Room is incorrect. Expected value is 5, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 9:  // Feast
        if (returned != 4) {
          printf("Error: getCost return for Feast is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 10:  // Gardens
        if (returned != 4) {
          printf("Error: getCost return for Gardens is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 11:  // Mine
        if (returned != 5) {
          printf("Error: getCost return for Mine is is incorrect. Expected value is 5, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 12:  // Remodel
        if (returned != 4) {
          printf("Error: getCost return for Remodel is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 13:  // Smithy
        if (returned != 4) {
          printf("Error: getCost return for Smithy is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 14:  // Village
        if (returned != 3) {
          printf("Error: getCost return for Village is incorrect. Expected value is 3, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 15:  // Baron
        if (returned != 4) {
          printf("Error: getCost return for Baron is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 16:  // Great Hall
        if (returned != 3) {
          printf("Error: getCost return for Great Hall is incorrect. Expected value is 3, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 17:  // Minion
        if (returned != 5) {
          printf("Error: getCost return for Minion is incorrect. Expected value is 5, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 18:  // Steward
        if (returned != 3) {
          printf("Error: getCost return for Steward is incorrect. Expected value is 3, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 19:  // Tribute
        if (returned != 5) {
          printf("Error: getCost return for Tribute is incorrect. Expected value is 5, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 20:  // Ambassador
        if (returned != 3) {
          printf("Error: getCost return for Ambassador is incorrect. Expected value is 3, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 21:  // Cutpurse
        if (returned != 4) {
          printf("Error: getCost return for Cutpurse is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 22:  // Embargo
        if (returned != 2) {
          printf("Error: getCost return for Embargo is incorrect. Expected value is 2, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 23:  // Outpost
        if (returned != 5) {
          printf("Error: getCost return for Outpost is incorrect. Expected value is 5, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 24:  // Salvager
        if (returned != 4) {
          printf("Error: getCost return for Salvager is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 25:  // Sea Hag
        if (returned != 4) {
          printf("Error: getCost return for Sea Hag is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 26:  // Treasure Map
        if (returned != 4) {
          printf("Error: getCost return for Treasure Map is incorrect. Expected value is 4, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      case 27:  // Invalid
        if (returned != -1) {
          printf("Error: getCost return for invalid index is incorrect. Expected value is -1, function returned: %d.\n", returned); 
          totalErrorCount++;
        }
        break;
      default:
        printf("Error: cardNumber is incorrect. Expected value between 0 and 26, value is: %d.\n", cardNumber); 
        totalErrorCount++;
    }
  }

  printf("----------End Testing getCost function----------\n");
  if (totalErrorCount == 0) 
    printf("----------Test Passed with Error Count: %d ------\n", totalErrorCount);
  else
    printf("----------Test Failed with Error Count: %d ------\n", totalErrorCount);
}
