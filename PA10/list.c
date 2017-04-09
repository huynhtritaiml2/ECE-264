#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/** INTERFACE FUNCTIONS **/

PathLL * buildPaths() {
	PathLL * retval = malloc(sizeof(PathLL));
	retval->head = NULL;
	return retval;
}

void freePaths(PathLL * p) {
	
  PathNode * head = p -> head;
  PathNode * tempHead;
  
  // Iterate through each node and free Node
  while(head != NULL) {
    tempHead = head -> next;
    freeNode(head);
    head = tempHead;
  }

  free(p);
}

PathNode * buildNode(char * path) {

  PathNode * node = malloc(sizeof(PathNode));
  node -> next = NULL;
  node -> path = malloc(sizeof(char) * (strlen(path) + 1));

  strcpy(node -> path, path);

  return node;
}

void freeNode(PathNode * p) {
  free(p -> path);
  free(p);
}

int turns(char * path) {

  int numTurns = 0;
  int i = 0;
  char last = path[0];

  while(path[i] != '\0') {
    if(last != path[i]) {
      numTurns++;
      last = path[i];
    }

    i++;
  }

  return numTurns;
}

bool sortNode(char * headPath, char * nodePath) {
  
  int lenHead = strlen(headPath);
  int lenNode = strlen(nodePath);

  if(lenHead == lenNode) {
    int turnHead = turns(headPath);
    int turnNode = turns(nodePath);

    if(turnHead == turnNode) {
      return strcmp(headPath, nodePath) > 0 ? true : false; 
    } else {
      return turnHead > turnNode;
    }
  } else {
    return lenHead > lenNode;
  }
}

bool addNode(PathLL * paths, char * path) {

  if(containsNode(paths, path)) {
    return false;
  }

  PathNode * head = paths -> head;

  // Case if no elements
  if(head == NULL) {
    paths -> head = buildNode(path);
    return true;
  }

  PathNode * headNext = head -> next;

  // Case if first element
  if(sortNode(head -> path, path)) {

    PathNode * newNode = buildNode(path);
    paths -> head = newNode;
    newNode -> next = head;

    return true;
  }

  // Case if not last element
  while(headNext != NULL) {
    if(sortNode(headNext -> path, path)) {
      
      PathNode * newNode = buildNode(path);
      head -> next = newNode;
      newNode -> next = headNext;

      return true;
    }

    head = headNext;
    headNext = headNext -> next;
  }
     
  // We have reached this point if we are at end of list
  head -> next = buildNode(path);
  return true;
}

bool removeNode(PathLL * paths, char * path) {
	
  PathNode * head = paths -> head;
  PathNode * headNext = head -> next;

  // Case if first element
  if(!strcmp(head -> path, path)) {
    paths -> head = headNext;
    freeNode(head);

    return true;
  }

  // Case if any other element
  while(headNext != NULL) {
    if(!strcmp(headNext -> path, path)) {
      head -> next = headNext -> next;
      freeNode(headNext);
      
      return true;
    }

    head = headNext;
    headNext = headNext -> next;
  }

  return false;
}

bool containsNode(PathLL * paths, char * path) {
  
  PathNode * head = paths -> head;

  // Iterate through each node
  while(head != NULL) {
    if(!strcmp(head -> path, path)) {
      return true;
    }

    head = head -> next;
  }

  return false;
}

void printPaths(PathLL * paths, FILE * fptr) {
  
  PathNode * head = paths -> head;
  int i = 0;
  
  while (head != NULL) {
    fprintf(fptr, "Path %2d: %s\n", i, head -> path);
    i++;
    head = head -> next;
  }
}
