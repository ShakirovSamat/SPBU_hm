#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "tree.h"


typedef int Error;

typedef struct Tree
{
    int num;
    char value;
    struct Tree *left;
    struct Tree *right;
}Tree;

Error createTreeFromFile(Tree **tree, FILE *file)
{
    (*tree) = calloc(1, sizeof(Tree));
    if (tree == NULL)
    {
        return -1;
    }
    for(;;)
    {
        char c = getc(file);
        if (c == EOF)
        {
            return 0;
        }

        switch(c)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            {
                (*tree)->value = c;
                (*tree)->num = NULL;
                Tree *leftChild = NULL;
                Tree *rightChild = NULL;
                Error errro1 = createTreeFromFile(&leftChild, file);
                Error errro2 = createTreeFromFile(&rightChild, file);
                if (errro1 != 0 || errro2 != 0)
                {
                    freeTree(leftChild);
                    freeTree(rightChild);
                    freeTree((*tree));
                    return -1;
                }
                (*tree)->left = leftChild;
                (*tree)->right = rightChild;
                return 0;
            }
            default:
            {
                if (c < '0' || c > '9')
                {
                    break;
                }
                ungetc(c, file);
                int num = 0;
                fscanf(file, "%d", &num);
                (*tree)->num = num;
                return 0;
            }
        }
    }      
    return 0;
}

void freeTree(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

int evaluateTree(Tree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    if (tree->num != NULL)
    {
        return tree->num;
    }

    switch(tree->value)
    {
        case '+':
            return evaluateTree(tree->left) + evaluateTree(tree->right);
        case '-':
            return evaluateTree(tree->left)  - evaluateTree(tree->right);
        case '*':
            return evaluateTree(tree->left)  * evaluateTree(tree->right);
        case '/':
            return evaluateTree(tree->left)  / evaluateTree(tree->right);
    }
    return 0;
}

Error printTree(FILE *file)
{
    char c;
    while(0 == 0)
    {
        char c = fgetc(file);
        if (c == EOF)
        {
            break;
        }
        printf("%c ", c);       
    }
    printf("\n");
    fclose(file);
    file = fopen("data.txt", "r");
}

bool test()
{
    FILE *file = fopen("test.txt", "r");
    Tree *tree = NULL;
    createTreeFromFile(&tree, file);
    int num = evaluateTree(tree);
    if (num != 16)
    {
        return false;
    }
    return true;
}