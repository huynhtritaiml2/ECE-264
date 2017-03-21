#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "path.h"

char * solveMaze(Maze *);

int main(int argc, char ** argv) {
  
  if (argc != 2) {
    fprintf(stderr, "Wrong number of command line args\n");
    fprintf(stderr, "Usage: ./pa08 mazeFile\n");
    return EXIT_FAILURE;
  }
	
  Maze * m = readMaze(argv[1]);
  
  if (m == NULL) {
    return EXIT_FAILURE;
  }

  char * str = solveMaze(m);
 
  free(str);
  freeMaze(m);
  free(m);

  return EXIT_SUCCESS;
}
