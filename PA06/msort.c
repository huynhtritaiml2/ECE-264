#include "msort.h"
#include "student.h"
#include <stdio.h>

#ifndef OMIT_MSORT

void msort(Student * base, int nel, int (*compar)(const void *, const void *)) {
	
  if(nel <= 1) {
    return;
  }

  int midpoint = nel / 2;
  
  msort(base, midpoint, compar);
  msort(&(base[midpoint + 1]), nel - midpoint - 1, compar);

  Student * mergedArr = merge(base, midpoint, &(base[midpoint]), nel - midpoint, compar);

  copy(base, mergedArr, nel);
  free(mergedArr);

  return;
}
#endif

#ifndef OMIT_MERGE
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *)) {
	
  Student * mergedArr = malloc(sizeof(Student) * (nel1 + nel2));

  int mergedIndx = 0;
  int base1Indx = 0;
  int base2Indx = 0;

  for(mergedIndx = 0; mergedIndx < nel1 + nel2; mergedIndx++) {
    
    if(base1Indx >= nel1) {
      mergedArr[mergedIndx] = base2[base2Indx];
      base2Indx++;
    } else if(base2Indx >= nel2) {
      mergedArr[mergedIndx] = base1[base1Indx];
      base1Indx++;
    } else {

      int mode = compar(&(base1[base1Indx]), &(base2[base2Indx]));
      
      if(mode > 0) {
	mergedArr[mergedIndx] = base2[base2Indx];
	base2Indx++;
      } else {
	mergedArr[mergedIndx] = base1[base1Indx];
	base1Indx++;
      }
    }
  }

  return mergedArr;
}


void copy(Student * to, Student * from, int nel) {
 
 for (int i = 0; i < nel; i++) {
    to[i] = from[i];
  }
  
  return;
}
#endif
