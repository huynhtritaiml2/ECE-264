#ifndef PA04_H
#define PA04_H

double func1(double);
double func2(double);
double func3(double);
double func4(double);
double func5(double);

typedef double (* funcptr) (double);

typedef struct
{
  double upperlimit;
  double lowerlimit;
  int intervals;
  double answer;
  funcptr func;

} Integration;

void integrate(Integration * intrg);
bool runIntegrate(char * infilename, char * outfilename);

#endif
