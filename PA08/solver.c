#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"

char * solveMaze(Maze * m) {
  char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));
  retval[0] = '\0';
  
  MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
  if (!depthFirstSolve(m, mp, retval, 0)) {
    fprintf(stderr, "No solution found!\n");
  } else {
    printf("Solution found: %s\n", retval);
  }
  
  return retval;
}

bool dirCheck(Maze * m, MazePos curpos, char dir) {
  int yDir = (dir == SOUTH) - (dir == NORTH);
  int xDir = (dir == EAST) - (dir == WEST);
  
  return curpos.xpos + xDir >= 0 && curpos.xpos + xDir < m -> width && // In X Bounds
    curpos.ypos + yDir >= 0 && curpos.ypos + yDir < m -> height &&  // In Y Bounds
    m -> maze[curpos.ypos + yDir][curpos.xpos + xDir].type != WALL && // Not A Wall
    !(m -> maze[curpos.ypos + yDir][curpos.xpos + xDir].visited); // Not Visited
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {

  if(m -> maze[curpos.ypos][curpos.xpos].type == END) {
    return true;
  }
  
  PathType direct [] = {NORTH, SOUTH, EAST, WEST};
  int sizeArr = sizeof(direct) / sizeof(PathType);

  for(int i = 0; i < sizeArr; i++) {
    
    PathType dir = direct[i];
    
    if(dirCheck(m, curpos, dir)) {
      MazePos cpyPos = curpos;
      
      (m -> maze[curpos.ypos][curpos.xpos]).visited = true;
      
      cpyPos.ypos += (dir == SOUTH) - (dir == NORTH);
      cpyPos.xpos += (dir == EAST) - (dir == WEST);
      
      path[step] = dir;
      path[step + 1] = '\0';
      
      if(depthFirstSolve(m, cpyPos, path, step + 1)) {
	return true;
      }
    }
  }
  
  return false;
}
