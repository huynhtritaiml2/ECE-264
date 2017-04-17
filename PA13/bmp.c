#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

#ifndef READIMAGE_OFF

BMPImage * readImage(FILE * fp) {

  // Allocate New BMP Image
  BMPImage * image = malloc(sizeof(BMPImage));

  // Read the Header
  fread(&(image -> header), sizeof(image -> header), 1, fp);

  // Get the BMP Header & Set the normalized height
  BMPHeader h = image -> header;
  image -> norm_height = h.height_px < 0 ? -h.height_px : h.height_px;

  // Allocate Pixels, then Read Em
  image -> pixels = malloc(sizeof(Pixel *) * image -> norm_height);

  for(int i = 0; i < image -> norm_height; i++) {   
    (image -> pixels)[i] = malloc(sizeof(Pixel) * h.width_px);
    fread((image -> pixels)[i], sizeof(Pixel), h.width_px, fp); 
  }

  return image;
}

void freeImage(BMPImage * image) {
	
  for(int i = 0; i < image -> norm_height; i++) {
    free((image -> pixels)[i]);
  }

  free(image -> pixels);
  free(image);
}
#endif

#ifndef WRITEIMAGE_OFF
void writeImage(BMPImage * image, FILE * fp) {
  
  // Write Image Header
  fwrite(&(image -> header), sizeof(image -> header), 1, fp);  

  // Write The Pixels
  for(int i = 0; i < image -> norm_height; i++) {
    Pixel * row = (image -> pixels)[i];
    fwrite(row, sizeof(Pixel), (image -> header).width_px, fp);
  }
}
#endif
