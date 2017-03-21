#include "student.h"
#include "msort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Print the students.
 */
void StudentPrint(Student * stu, int num)
{
  printf("There are %d students\n", num);
  
  int ind;
  for (ind = 0; ind < num; ind ++)
    {
      printf("ID = %d, First Name = %s, Last Name = %s\n",
	     stu[ind].ID,  stu[ind].firstname, stu[ind].lastname);
    }
}

#ifdef TEST_READ

/**
 * Reads student data from a file <filename>.
 */
bool StudentRead(char * filename, Student * * stu, int * numelem)
{
  // Open the file
  FILE * file = fopen(filename, "r");

  // Check if file open was successful
  if(file == NULL)
  {
    return false;
  }

  // Variables
  char currChar;
  *numelem = 0;

  // Count number of new lines in file
  while(true)
  {

    int code = fscanf(file, "%c", &currChar);

    if(code == EOF)
    {
      break;
    }

    if(code != 1)
    {
      fclose(file);
      return false;
    }

    if(currChar == '\n')
    {
      (*numelem)++;
    }
  }

  // go back to the beginning of file
  int failure = fseek(file, 0, SEEK_SET);
  // check if seek was successful
  if(failure)
  {
    return false;
  }

  // allocate memory for the data
  *stu = malloc(sizeof(Student) * (*numelem));

  // check if allocated memory successfully
  if(*stu == NULL)
  {
    return false;
  }

  // read the data from the file and store the data in the allocated memory
  int i;
  for(i = 0; i < *numelem; i++)
  {
    Student * student = &((*stu)[i]);
    
    failure = fscanf(file, "%d %s %s", &(student -> ID), student -> firstname, student -> lastname);

    if(failure == EOF)
    {
      return false;
    }

    if(failure != 3)
    {
      fclose(file);
      return false;
    }
  }

  fclose(file);
  
  return true;
}
#endif

#ifdef TEST_WRITE

/**
 * Write student data to a file named <filename>.
 */
bool StudentWrite(char * filename, Student * stu, int numelem)
{
  // open the file to read
  FILE * file = fopen(filename, "w");

  // check if file open was successful
  if(file == NULL)
  {
    return false;
  }

  // write the students to the output file
  int i;
  for(i = 0; i < numelem; i++)
  {
    Student student = stu[i];

    fprintf(file, "%d %s %s\n", student.ID, student.firstname, student.lastname);
  }

  // close file
  fclose(file);

  return true;
}
#endif 

#ifdef TEST_SORTID

/**
 * Compares two IDs from a Student struct
 */
int compInt(const void * arg1, const void * arg2)
{
  const Student * comp1 = (const Student *) arg1;
  const Student * comp2 = (const Student *) arg2;

  return (comp1 -> ID) - (comp2 -> ID);
}

/**
 * Sorts Students by ID usinq quicksort
 */
void StudentSortbyID(Student * stu, int numelem)
{
  msort(stu, numelem, compInt);
}
#endif

#ifdef TEST_SORTFIRSTNAME

/**
 * Compares two first Names from a Student struct
 */
int compStudentFirstName(const void * arg1, const void * arg2)
{
  const Student * comp1 = (const Student *) arg1;
  const Student * comp2 = (const Student *) arg2;
  
  return strcmp(comp1 -> firstname, comp2 -> firstname);
}

/**
 * Sorts Students by First Name using quicksort
 */
void StudentSortbyFirstName(Student * stu, int numelem)
{
  msort(stu, numelem, compStudentFirstName);
}

#endif

#ifdef TEST_SORTLASTNAME

/**
 * Compares two last Names from a Student struct;
 */
int compStudentLastName(const void * arg1, const void * arg2)
{
  const Student * comp1 = (const Student *) arg1;
  const Student * comp2 = (const Student *) arg2;
  
  return strcmp(comp1 -> lastname, comp2 -> lastname);
}

/**
 * Sorts students by last name using quick sort
 */
void StudentSortbyLastName(Student * stu, int numelem)
{
  msort(stu, numelem, compStudentLastName);
}

#endif
