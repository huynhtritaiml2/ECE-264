#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "mazehelper.h"
#include "path.h"
#include "list.h"

PathLL * solveMaze(Maze * m) {
	
	PathLL * successPaths = buildPaths();
	char * retval = malloc(((m->height * m->width) + 1) * sizeof(char));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	depthFirstSolve(m, mp, retval, 0, successPaths);
	
	free(retval);
	
	return successPaths;
}

bool dirCheck(Maze * m, MazePos curpos, char dir) {
  int yDir = (dir == SOUTH) - (dir == NORTH);
  int xDir = (dir == EAST) - (dir == WEST);

  return curpos.xpos + xDir >= 0 && curpos.xpos + xDir < m -> width && // In X Bounds
    curpos.ypos + yDir >= 0 && curpos.ypos + yDir < m -> height &&  // In Y Bounds                    
    m -> maze[curpos.ypos + yDir][curpos.xpos + xDir].type != WALL && // Not A Wall
    !(m -> maze[curpos.ypos + yDir][curpos.xpos + xDir].visited); // Not Visited
}

void depthFirstSolve(Maze * m, MazePos curpos, char * path, int step, PathLL * successPaths) {
	
  if(m -> maze[curpos.ypos][curpos.xpos].type == END) {
    addNode(successPaths, path);
    return;
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

      depthFirstSolve(m, cpyPos, path, step + 1, successPaths);
    }

    (m -> maze[curpos.ypos][curpos.xpos]).visited = false;
  }
}
