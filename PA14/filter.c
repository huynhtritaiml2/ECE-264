#include <stdlib.h>
#include <stdio.h>
#include "filter.h"

void copyImage(BMPImage * src, BMPImage * dest) {

  dest -> header = src -> header;
  dest -> norm_height = src -> norm_height;
  dest -> pixels = malloc(sizeof(Pixel *) * src -> norm_height);

  for(int i = 0; i < src -> norm_height; i++) {
    (dest -> pixels)[i] = malloc(sizeof(Pixel) * (src -> header).width_px);
  }

  for(int i = 0; i < src -> norm_height; i++) {
    for(int j = 0; j < (src -> header).width_px; j++) {
      (dest -> pixels)[i][j] = (src -> pixels)[i][j];
    }
  }
}

BoxFilter * readFilter(FILE * infile) {

  BoxFilter * filter = malloc(sizeof(BoxFilter));
  
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      fscanf(infile, "%d", &((filter -> filter)[i][j]));
      printf("%d ", (filter -> filter)[i][j]);
    }
    printf("\n");
  }

  fscanf(infile, "%f", &(filter -> norm));
  printf("%f\n", filter -> norm);
  return filter;
}
// EXTRA CREDIT END
