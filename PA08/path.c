#include <stdio.h>
#include <stdlib.h>
#include "path.h"

#ifndef READPATH_OFF
char * readPath(char * pathFilename) {
  
  FILE * file = fopen(pathFilename, "r");
  
  if(file == NULL) {
    return NULL;
  }

  int charCount = -1;
  char val;
  int code;

  do {
    code = fscanf(file, "%c", &val);
    charCount++; 
  } while(code != EOF);
  
  fseek(file, 0, SEEK_SET);

  char * str = malloc(sizeof(char) * (charCount + 1));

  int i;
  for(i = 0; i < charCount; i++) {
    fscanf(file, "%c", &str[i]);
  }

  str[charCount] = '\0';

  fclose(file);
  return str;
}
#endif //#ifndef READPATH_OFF

#ifndef CHECKPATH_OFF
bool checkPath(Maze * m, char * path) {

  int i = 0;

  MazePos init = m -> start;
  MazePos goal = m -> end;

  while(path[i] != '\0') {
    
    char dir = path[i];

    init.xpos += (SOUTH == dir) - (NORTH == dir);
    init.ypos += (EAST == dir) - (WEST == dir);

    // Check If In Array Bounds
    if(init.xpos < 0 || init.xpos >= m -> height || init.ypos < 0 || init.ypos >= m -> width) {
      return false;
    }

    // Check if hit a wall
    if((m -> maze)[init.xpos][init.ypos].type == WALL) {
      return false;
    }

    // Check if we have visited before
    if((m -> maze)[init.xpos][init.ypos].visited) {
      return false;
    }

    // Check if we got to target
    if(init.xpos == goal.xpos && init.ypos == goal.ypos) {
      return true;
    }

    i++;

    (m -> maze)[init.xpos][init.ypos].visited = true;
  }

  return false;
}
#endif //#ifndef CHECKPATH_OFF
