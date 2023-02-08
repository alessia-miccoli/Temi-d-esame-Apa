#ifndef UNTITLED1_T_H
#define UNTITLED1_T_H
#include <stdlib.h>
#include <stdio.h>
typedef struct tree *TREE;
typedef struct node *link;

struct node{
    int data;
    link *children;
    int N;
};
int f(TREE t);
TREE init();

#endif //UNTITLED1_T_H
