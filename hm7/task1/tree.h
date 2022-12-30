#include <stdbool.h>

enum Errors
{
    OUT_OF_MEMORY,
    OK,
    NOT_FOUND
};

typedef struct Tree Tree;

Tree *createTree();

int insert(Tree *tree, int ley, char *value);

int get(Tree *tree, int key, char **result);

bool isExist(Tree *tree, int key);

int delete(Tree *tree, int key);

void printTree(Tree *tree);