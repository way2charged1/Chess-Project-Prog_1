#include "variables.h"
#include "criticalscenarios.h"
#include "isitfns.h"
#include "movement.h"
#include "renderfns.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <time.h>
#include "sidenotes.h"

void sidenote(){
  int qoute = rand()%13;
  switch(qoute){
    case 0:
    printf("2 is forever lonely in the prime world!");
    break;
    case 1:
    printf("Error 404: Motivation Not Found");
    break;
    case 2:
    printf("One man's constant is another man's variable");
    break;
    case 3:
    printf("while(alive){ code; }");
    break;
    case 4:
    printf("1 + 1 = 10 (but in binary!)");
    break;
    case 5:
    printf("Just keep taking chances and having fun");
    break;
    case 6:
    printf("!false (it's true!)");
    break;
    case 7:
    printf("Recursion: see 'Recursion'");
    break;
    case 8:
    printf("It always seems impossible until it's done");
    break;
    case 9:
    printf("Real Programmers Count From 0");
    break;
    case 10:
    printf("Decimals have a point.");
    break;
    case 11:
    printf("π: Be Rational,i: Get Real");
    break;
    case 12:
    printf("It's not a bug, it's a feature");
    break;
    default:
    break;
  }
}