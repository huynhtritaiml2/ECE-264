#include "answer09.h"

bool isCircular(const node_t * head)
{

  if(head == NULL) {
    return false;
  }

  // Define Two Heads
  const node_t * head_slow = head;
  const node_t * head_fast = head -> next;

  // Loop Through The Heads Until NULL or Loop Detected
  while(head_slow != NULL && head_fast != NULL && head_slow != head_fast) {
    head_slow = head_slow -> next;
    head_fast = head_fast -> next;
    
    if(head_fast != NULL) {
      head_fast = head_fast -> next;
    }
  }

  if(head_slow == head_fast && head_fast != NULL) {
    return true;
  } else {
    return false;
  }
}
