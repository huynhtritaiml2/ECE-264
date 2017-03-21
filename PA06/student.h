#ifndef PA05_H
#define PA05_H

#include "constant.h"
#include <stdbool.h>

typedef struct
{
  int ID;
  char firstname[NAME_LENGTH];
  char lastname[NAME_LENGTH];
} Student;

bool StudentRead(char * filename, Student * * stu, int * numelem);
bool StudentWrite(char * filename, Student * stu, int numelem);
void StudentSortbyID(Student * stu, int numelem);
void StudentSortbyFirstName(Student * stu, int numelem);
void StudentSortbyLastName(Student * stu, int numelem);
void StudentPrint(Student * stu, int num);

#endif
