#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pa04.h"

#define TOLERANCE 0.1 // acceptable difference in floating point numbers

int main(int argc, char * * argv)
{

  if(argc != 3)
  {
    return EXIT_FAILURE;
  }

  char * in_file = argv[1];
  char * out_file = argv[2];

  return runIntegrate(in_file, out_file) ? EXIT_SUCCESS : EXIT_FAILURE;
}
