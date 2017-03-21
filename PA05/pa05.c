#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"

/**
 * This is the main function (entry point of the program)
 */
int main(int argc, char * * argv)
{
  // if we dont have five argument we got a problem
  if (argc < 5)
    {
      return EXIT_FAILURE;
    }

  // init variables  
  Student * students;
  int length;

  // read students from the input file & check if failed
  if(!StudentRead(argv[1], &students, &length))
  {
    return EXIT_FAILURE;
  }

  // sort and write to file, if failure, return
  StudentSortbyID(students, length);
  if(!StudentWrite(argv[2], students, length))
  {
    return EXIT_FAILURE;
  }

  // sort and write to file, if failure, return
  StudentSortbyFirstName(students, length);
  if(!StudentWrite(argv[3], students, length))
  {
    return EXIT_FAILURE;
  }

  // sort and write to file, if failure, return
  StudentSortbyLastName(students, length);
  if(!StudentWrite(argv[4], students, length))
  {
    return EXIT_FAILURE;
  }

  // free heap memory 
  free(students);

  return EXIT_SUCCESS;
}
