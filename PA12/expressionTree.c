#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) {

  TreeNode * l_node = NULL;
  TreeNode * r_node = NULL;
  Token operator;

  Token t = nextToken(s);

  while(t.type != T_EOF) {
    
    if(t.type == T_LPAREN) {
      l_node = buildExpressionTree(s);
    } else if(t.type == T_RPAREN) {
      TreeNode * h_node = buildTreeNode(operator);
      h_node -> left = l_node;
      h_node -> right = r_node;
      return h_node;
    } else if(t.type == T_ADD || t.type == T_SUB ||
	      t.type == T_MUL || t.type == T_DIV) {
      operator = t;
      r_node = buildExpressionTree(s);
    } else if(t.type == T_VAL) {
      return buildTreeNode(t);
    }

    t = nextToken(s);
  }

  return NULL;
}
#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) {

  if(t == NULL) {
    return;
  } else if((t -> t).type == T_VAL) {
    fprintf(fptr, "%f ", (t -> t).value);
  } else {
    makePostFix(t -> left, fptr);
    makePostFix(t -> right, fptr);
    fprintf(fptr, "%c ", (t -> t).type);
  }
}
#endif
