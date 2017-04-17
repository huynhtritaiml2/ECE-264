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

#ifndef BLUR_OFF
BMPImage * blur(BMPImage * image) {

  BoxFilter blurFilter;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      blurFilter.filter[i][j] = 1;
    }
  }

  blurFilter.norm = 9.0;

  return apply(image, blurFilter);
}
#endif

// EXTRA CREDIT START
BMPImage * apply(BMPImage * image, BoxFilter f) {

  BMPImage * output = malloc(sizeof(BMPImage));
  copyImage(image, output);
  
  int32_t width = (output -> header).width_px;
  int height = output -> norm_height;
  
  float normFact = f.norm;
  
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {

      Pixel * target = &(output -> pixels)[i][j];

      int bgra [] = {0, 0, 0, 0};

      for(int k = i - 1; k < i + 2; k++) {
        for(int m = j - 1; m < j + 2; m++) {

          Pixel valid;

	  if(k >= 0 && k < height && m >= 0 && m < width) {
	    valid = (image -> pixels)[k][m];
	  } else {
	    
	    if((k < 0 && m < 0) || (k < 0 && m >= width) ||
	       (k >= height && m < 0) || (k >= height && m >= width)) {
	      valid = (image -> pixels)[i][j];
	    } else if(((k < 0 || k >=  height) && m == i) ||
		      ((m < 0 || m >= width) && k == j)) {
	      valid = (image -> pixels)[i][j];
	    } else if(k < 0 || k >= height) {
	      int indx = k < 0 ? 0 : height - 1;
	      valid = (image -> pixels)[indx][m];
	    } else {
	      int indx = m < 0 ? 0 : width - 1;
	      valid = (image -> pixels)[k][indx];
	    }
	  }
	  
	  bgra[0] += valid.blue * f.filter[k - (i - 1)][m - (j - 1)];
	  bgra[1] += valid.green * f.filter[k - (i - 1)][m - (j - 1)];
	  bgra[2] += valid.red * f.filter[k - (i - 1)][m - (j - 1)];
	  bgra[3] += valid.alpha * f.filter[k - (i - 1)][m - (j - 1)];
	}
      }
      
      (*target).blue = (bgra[0] / normFact);
      (*target).green = (bgra[1] / normFact);
      (*target).red = (bgra[2] / normFact);
      (*target).alpha = (bgra[3] / normFact);

      (*target).blue = (*target).blue > 255 ? 255 : ((*target).blue < 0 ? 0 : (*target).blue);
      (*target).green = (*target).green > 255 ? 255 : ((*target).green < 0 ? 0 : (*target).green);
      (*target).red = (*target).red > 255 ? 255 : ((*target).red < 0 ? 0 : (*target).red);
      (*target).alpha = (*target).alpha > 255 ? 255 : ((*target).alpha < 0 ? 0 : (*target).alpha);
    }
  }
  
  return output;  
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
