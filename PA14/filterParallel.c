#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "filterParallel.h"

void applyThread(BMPImage * imageIn, BMPImage * imageOut, BoxFilter f, int tid, int numThreads) {
	
	//FILL IN. This is the work that thread #tid should do
	//You may find it useful to know the number of threads (numThreads) to
	//figure out what to do.

  BMPImage * image = imageIn;
  BMPImage * output = imageOut;
  
  int width = (output -> header).width_px;
  int height = output -> norm_height;

  int totHeight = height;

  float normFact = f.norm;

  int heightInit = (height / numThreads) * tid;

  if(tid + 1 != numThreads) {
    totHeight = (height / numThreads) * (tid + 1);
  }

  for(int i = heightInit; i < totHeight; i++) {
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
}

void * applyThreadWrapper(void * args) {
	ApplyArgs * applyArgs = (ApplyArgs *) args;
	fprintf(stdout, "calling thread %d\n", applyArgs->tid);
	
	applyThread(applyArgs->in, applyArgs->out, applyArgs->filter, applyArgs->tid, applyArgs->numThreads);
	
	fprintf(stdout, "finished with thread %d\n", applyArgs->tid);
	
	return NULL;
}

void apply(BMPImage * imageIn, BMPImage * imageOut, BoxFilter f, int numThreads) {

  ApplyArgs * applyArgs = malloc(sizeof(ApplyArgs) * numThreads);
  pthread_t * threads = malloc(sizeof(pthread_t) * numThreads);

  for(int i = 0; i < numThreads; i++) {
    applyArgs[i].in = imageIn;
    applyArgs[i].out = imageOut;
    applyArgs[i].filter = f;
    applyArgs[i].tid = i;
    applyArgs[i].numThreads = numThreads;
  }

  for(int i = 0; i < numThreads; i++) {
    pthread_create(&threads[i], NULL, applyThreadWrapper, &applyArgs[i]);
  }

  for(int i = 0; i < numThreads; i++) {
    pthread_join(threads[i], NULL);
  }

  free(applyArgs);
  free(threads);	
}

