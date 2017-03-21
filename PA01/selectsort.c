#ifdef SELECTION_SORT
#include "pa01.h"

void selectSort(int * arr, int size)
//arr : the array to be sorted
//size : the number of elements in the array

// In each iteration, the number of elements to be sorted shrinks by one
// i.e., one element is at the correct position.
//
// Among the remaining elements, find the smallest value and put it 
// before the other unsorted elements
{
  int i; // i : for-loop iterator
  int j; // j : for-loop iterator
  int smallest; // smallest : index of smallest number in unsorted array
  int temp; // temp : temporary storage for swapping numbers

  if(size > 1)
  {
    for(i = 0; i < size; i++)
    {
      smallest = i;

      for(j = i + 1; j < size; j++)
      {
        if(arr[smallest] > arr[j])
	{
	  smallest = j;
        }
      }

      // Swap Elements
      temp = arr[smallest];
      arr[smallest] = arr[i];
      arr[i] = temp;
    }
  }
}
#endif
