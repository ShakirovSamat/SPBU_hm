#include <stdbool.h>

typedef int Error;

typedef struct Tree Tree;

Error createTreeFromFile(Tree **tree, FILE *file);

void freeTree(Tree *tree);

int evaluateTree(Tree *tree);

Error printTree(FILE *file);

bool test();