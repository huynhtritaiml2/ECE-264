#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "pa04.h"

#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{

  // Average change in value between the upper and lower limit over x intervals
  double delta = (intrg -> upperlimit - intrg -> lowerlimit) / intrg -> intervals;
  double integration = 0; // Value of the integration

  int i = 0; // For Loop Iterator
  for(i = 0; i < intrg -> intervals; i++)
  {
    integration += intrg -> func(intrg -> lowerlimit + i * delta); 
  }

  intrg -> answer = integration * delta;
}
#endif 

#ifdef RUN_INTEGRATE
bool runIntegrate(char * infilename, char * outfilename)
{

  Integration intrg;
  int retVal;

  const char read = 'r';
  const char write = 'w';

  // Open Input File
  FILE * input_File = fopen(infilename, &read);

  if(input_File == NULL) 
  {
    return false;
  }

  retVal = fscanf(input_File, "%lf", &(intrg.lowerlimit));
  if(retVal != 1)
  {
    fclose(input_File);
    return false;
  }
  
  retVal = fscanf(input_File, "%lf", &(intrg.upperlimit));
  if(retVal != 1)
  {
    fclose(input_File);
    return false;
  } 

  retVal = fscanf(input_File, "%d", &(intrg.intervals));
  if(retVal != 1)
  {
    fclose(input_File);
    return false;
  }

  fclose(input_File);

  // Open Output File
  FILE * output_File = fopen(outfilename, &write);

  if(output_File == NULL)
  {
    return false;
  }

  funcptr funcs [5] = {
    func1, func2, func3, func4, func5
  };

  int i = 0; // For-loop iterator
  int func_size = sizeof(funcs) / sizeof(funcptr);

  for(i = 0; i < func_size; i++)
  {
    intrg.func = funcs[i];
    integrate(&intrg);

    retVal = fprintf(output_File, "%lf\n", intrg.answer);
  
    if(retVal < 1)
    {
      fclose(output_File);
      return false;
    }
  }

  fclose(output_File);

  return true;
}
#endif
