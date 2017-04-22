#include "bmp.h"
#include "filterParallel.h"

//Read in a box filter spec from the given input file
BoxFilter * readFilter(FILE * infile);

void copyImage(BMPImage * src, BMPImage * dest);
