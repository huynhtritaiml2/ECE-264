#include "pa03.h"
double integrate1(Range rng)
{  
  // Average change in value between the upper and lower limit over x intervals
  double delta = (rng.upperlimit - rng.lowerlimit) / rng.intervals;
  double integration = 0; // Value of the integration

  int i = 0; // For Loop Iterator
  for(i = 0; i < rng.intervals; i++)
  {
    integration += func(rng.lowerlimit + i * delta); 
  }

  integration *= delta;

  return integration;
}

void integrate2(RangeAnswer * rngans)
{
  rngans -> answer = integrate1(rngans -> rng);
}
