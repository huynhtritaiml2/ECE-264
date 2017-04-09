#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

NumberNode * createNode(float value) {
  
  NumberNode * node = malloc(sizeof(NumberNode));
  node -> value = value;
  node -> next = NULL;

  return node;
}

void freeNode(NumberNode * node) {
  free(node);
}

void pushNode(NumberStack * stack, NumberNode * node) {
  
  NumberNode * head = stack -> head;

  if(head == NULL) {
    stack -> head = node;
    return;
  }

  while(head -> next != NULL) {
    head = head -> next;
  }

  head -> next = node;
}

NumberNode * popNode(NumberStack * stack) {
  
  NumberNode * head = stack -> head;
  NumberNode * headPrev = head;

  if(head == NULL) {
    return NULL;
  }

  if(head -> next == NULL) {
    stack -> head = NULL;
  }

  while(head -> next != NULL) {
    headPrev = head;
    head = head -> next;
  }

  headPrev -> next = NULL;
  return head;
}

void printStack(NumberStack * stack) {
  
  NumberNode * head = stack -> head;
  int i = 0;

  while(head != NULL) {
    printf("%.2f ", head -> value);
    head = head -> next;
    i++;
  }

  printf("\n");
}

int stackHeight(NumberStack * stack) {

  NumberNode * head = stack -> head;
  int i = 0;

  while(head != NULL) {
    head = head -> next;
    i++;
  }

  return i;
}
