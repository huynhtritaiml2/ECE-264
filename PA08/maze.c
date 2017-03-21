#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

#ifndef READMAZE_OFF

void allocate(Maze * maze) {
  
  MazeSquare * * * mazeSq = &(maze -> maze);
  int rows = maze -> height;
  int cols = maze -> width;

  *mazeSq = malloc(sizeof(MazeSquare *) * rows);

  int i;
  for(i = 0; i < rows; i++) {
    (*mazeSq)[i] = malloc(sizeof(MazeSquare) * cols);
  }
}

#ifdef DEBUG

void printMaze(Maze * maze) {

  MazeSquare * * mazeSq = maze -> maze;
  int rows = maze -> height;
  int cols = maze -> width;

  int i, j;
  for(i = 0; i < rows; i++) {
    for(j = 0; j < cols; j++) {
      printf("%c", mazeSq[i][j].type);
    }
    printf("\n");
  }
}

#endif

Maze * readMaze(char * mazeFilename) {

  Maze * maze = malloc(sizeof(Maze));
  FILE * file = fopen(mazeFilename, "r");
  
  // Read Rows & Cols
  fscanf(file, "%d %d", &(maze -> height), &(maze -> width));

  // Allocate Space of MazeSquare
  allocate(maze);

  int i, j;
  char temp;
  for(i = 0; i < maze -> height; i++) {
    for(j = 0; j < maze -> width; j++) {
      
      fscanf(file, "%c", &temp);
      (maze -> maze)[i][j].type = temp;
      (maze -> maze)[i][j].visited = false;

      switch(temp) {
        case 's':
          (maze -> start).xpos = i;
	  (maze -> start).ypos = j;
  	  break;
        case 'e':
	  (maze -> end).xpos = i;
	  (maze -> end).ypos = j;
	  break;
        case '\n':
          j--;
      }
    }
  } 

#ifdef DEBUG
  printMaze(maze);
#endif

  fclose(file);
  return maze;
}
#endif //#ifndef READMAZE_OFF

#ifndef FREEMAZE_OFF
void freeMaze(Maze * m) {
	//1. Free each of the "rows" of the maze
  int rows = m -> height;

  int i;
  for(i = 0; i < rows; i++) {
    free((m -> maze)[i]);
  }

  free(m -> maze);
}
#endif //#ifndef FREEMAZE_OFF
