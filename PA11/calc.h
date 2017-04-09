#ifndef CALC
#define CALC

#include <stdbool.h>
#include "stack.h"

int calculate(NumberNode * nodeA, NumberNode * nodeB, char operator, float * newVal);
bool isOperator(char operator);

#endif
