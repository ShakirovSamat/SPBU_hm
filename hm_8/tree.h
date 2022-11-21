#pragma once

typedef struct Tree Tree;

Tree *leftRotate(Tree *tree);

Tree *rihghtRotate(Tree *tree);

Tree *bigLeftRotate(Tree *tree);

Tree *bigRightRotate(Tree *tree);

Tree *balance(Tree *tree);

Tree *insert(Tree *tree, int key, char *value);
