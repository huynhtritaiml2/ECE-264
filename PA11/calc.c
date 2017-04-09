#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "calc.h"
#include "stack.h"

int calculate(NumberNode * nodeA, NumberNode * nodeB, char operator, float * newVal) {
  
  double valueA = nodeA -> value;
  double valueB = nodeB -> value;

  freeNode(nodeA);
  freeNode(nodeB);

  valueA = fabs(valueA) < 10e-20 ? 0 : valueA;
  valueB = fabs(valueB) < 10e-20 ? 0 : valueB;

  switch(operator) {
    case '*':
      *newVal = valueB * valueA;
      break;
    case '/':
      *newVal = valueB / valueA;
      break;
    case '+':
      *newVal = valueB + valueA;
      break;
    case '-':
      *newVal = valueB - valueA;
  }

  return 1;
}

bool isOperator(char operator) {
  return (operator == '-' || operator == '/' ||
     operator == '*' || operator == '+');
}
