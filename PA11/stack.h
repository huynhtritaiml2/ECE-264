#ifndef STACK
#define STACK

typedef struct NumberNode {

  float value;
  struct NumberNode * next;

} NumberNode;

typedef struct {
  
  NumberNode * head;

} NumberStack;

/* Pushes Node To A Stack */
void pushNode(NumberStack * stack , NumberNode * node);

/* Pops Node From A Stack */
NumberNode * popNode(NumberStack * stack);

/* Creates a Number Node */
NumberNode * createNode(float value);

/* Frees A Node */
void freeNode(NumberNode * node);

/* Prints Stack */
void printStack(NumberStack * stack);

/* Determine Stack "Height" */
int stackHeight(NumberStack * stack);

#endif
