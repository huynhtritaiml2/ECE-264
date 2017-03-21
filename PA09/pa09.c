#include "linkedlist.h"
#include "answer09.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char * * argv)
{

  srand(time(NULL));
  //THIS IS JUST SAMPLE CODE FOR TESTING. YOU WILL HAVE TO BUILD YOUR OWN
  //TEST CASES
  
  //Build one or more linked lists here
  node_t * head = malloc(sizeof(*head));
  node_t * orgHead = head;
  node_t * tempHead;
  node_t * place;
 
  head -> next = NULL;
  head -> data = 0;

  int number = rand() % 10;
  int toCircular = rand() % 2;
  int placeToTake = number != 0 ? rand() % number : 0;

  if(number == 0) {
    orgHead = NULL;
  }

  printf("SUPPOSED TO CIRCULAR? %s\n", toCircular == 1 ? "YES" : "NO");
  printf("NUMBER OF NODES %d\n", number);

  for(int i = 0; i < number; i++) {
    tempHead = malloc(sizeof(*head));
    tempHead -> data = i + 1;
    tempHead -> next = NULL;

    head -> next = tempHead;
   
    if(placeToTake == i && toCircular == 1) {
      place = head;
    }

    head = tempHead;  
  }

  if(toCircular == 1) {
    head -> next = place;
  }
			 
  //Check to see if the lists you have built are circular
  bool result = isCircular(orgHead);
  
  /* More testing ... */
  printf("IS CIRCULAR? %s\n", result ? "YES" : "NO");
 
}
