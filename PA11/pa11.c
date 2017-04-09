#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "calc.h"

int runPolishNotation(FILE * file);
void freeMemory(NumberStack ** stack, char ** temp, FILE ** file);
int getWord(FILE * file, char * word);

int main (int argc, char ** argv) {
	
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of arguments.\n");
    fprintf(stderr, "Usage: ./pa11 <input file>\n");		
    return EXIT_FAILURE;
  }

  FILE * inputFile = fopen(argv[1], "r");

  if(inputFile == NULL) {
    return EXIT_FAILURE;
  }

  return runPolishNotation(inputFile);
}

int runPolishNotation(FILE * file) {
  
  NumberStack * stack = malloc(sizeof(NumberStack));
  stack -> head = NULL;

  char * temp = malloc(sizeof(char) * 20);

  while(!feof(file)) {
    
    int code = getWord(file, temp);

    if(!strlen(temp) && !code) {
      freeMemory(&stack, &temp, &file);
      return EXIT_FAILURE;
    }

    if(!strlen(temp) && code) {
      break;
    }

    if(isOperator(temp[0]) && strlen(temp) == 1) {
      
      NumberNode * nodeA = popNode(stack);
      NumberNode * nodeB = popNode(stack);
      
      if(nodeB == NULL) {
	
	if(nodeA != NULL) {
	  freeNode(nodeA);
	}
	
	freeMemory(&stack, &temp, &file);
	return EXIT_FAILURE;
      }
      
      float result;
      int success = calculate(nodeA, nodeB, temp[0], &result);
      
      if(!success) {
	freeMemory(&stack, &temp, &file);
	  return EXIT_FAILURE;
      } else {
	pushNode(stack, createNode(result));
      }
    } else {
      
      float tempValue = (float) atof(temp);
	
      pushNode(stack, createNode(tempValue));
    }
  }

  fclose(file);

  int stack_h = stackHeight(stack);

  if(stack_h == 1) {
    printf("%f\n", (stack -> head) -> value);
  }

  while(stack -> head != NULL) {
    freeNode(popNode(stack));
  }
  
  free(stack);
  free(temp);

  return stack_h != 1 ? EXIT_FAILURE : EXIT_SUCCESS;
}

int getWord(FILE * file, char * word) {

  char c = '\0'; // Temp
  int size = 1;

  word[0] = c;

  while(!feof(file)) {
    fscanf(file, "%c", &c);

    if(c == '\n' || c == ' ' || feof(file)) {
      break;
    }

    word[size - 1] = c;
    word[size] = '\0';
    size++;
  }

  return feof(file);
}

void freeMemory(NumberStack ** stack, char ** temp, FILE ** file) {
 
  free(*temp);
  
  while((*stack) -> head != NULL) {
    freeNode(popNode(*stack));
  }

  free(*stack);
  fclose(*file);
}
