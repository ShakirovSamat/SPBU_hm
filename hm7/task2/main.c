#include <stdio.h>
#include "tree.h"

int main()
{
    
    Tree *tree = NULL;
    FILE *file = fopen("data.txt", "r");
    printTree(file);
    createTreeFromFile(&tree, file);
    int num = evaluateTree(tree);
    printf("%d", num);
    return 0;
}