#pragma once

typedef struct Tree Tree;

Tree *createtTree();

Tree *insert(Tree *tree, int key, char *value);

char *get(Tree *tree, int key);

int delete (Tree *tree, int key);
