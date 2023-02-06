#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node
{
    int key;
    char *value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree
{
    struct Node *root;
} Tree;

Tree *createTree()
{
    return calloc(1, sizeof(Tree));
}
int insert(Tree *tree, int key, char *value)
{
    if (tree == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return OUT_OF_MEMORY;
    }
    newNode->key = key;
    newNode->value = value;

    Node *currentNode = tree->root;
    Node *previousNode = NULL;
    while (currentNode != NULL)
    {
        previousNode = currentNode;

        if (newNode->key < currentNode->key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    if (previousNode == NULL)
    {
        tree->root = newNode;
    }
    else if (newNode->key < previousNode->key)
    {
        previousNode->left = newNode;
    }
    else
    {
        previousNode->right = newNode;
    }
    return OK;
}

int get(Tree *tree, int key, char **result)
{
    if (tree == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *currentNode = tree->root;
    while (currentNode != NULL && key != currentNode->key)
    {
        if (key < currentNode->key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    if (currentNode == NULL)
    {
        return NOT_FOUND;
    }

    *result = currentNode->value;
    return OK;
}

bool isExist(Tree *tree, int key)
{
    if (tree == NULL)
    {
        return false;
    }

    Node *currentNode = tree->root;
    while (currentNode != NULL && key != currentNode->key)
    {
        if (key < currentNode->key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    return currentNode != NULL;
}

int getMin(Node *node, Node *min, Node *minParent)
{
    if (node == NULL)
    {
        OUT_OF_MEMORY;
    }
    Node *currentNode = node;
    Node *previousNode = NULL;
    while (node->left != NULL)
    {
        previousNode = currentNode;
        currentNode = currentNode->left;
    }
    minParent = previousNode;
    min = currentNode;

    return OK;
}

int delete(Tree *tree, int key)
{
    if (tree == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *currentNode = tree->root;
    Node *previousNode = NULL;

    while (currentNode != NULL && key != currentNode->key)
    {
        previousNode = currentNode;
        if (key < currentNode->key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    if (currentNode == NULL)
    {
        return NOT_FOUND;
    }

    // Если удаляем лист
    if (currentNode->left == NULL && currentNode->right == NULL)
    {
        if (previousNode->left == currentNode)
        {
            previousNode->left = NULL;
        }
        else
        {
            previousNode->right = NULL;
        }
        free(currentNode);
        return OK;
    }

    // Если одного ребёнка не существует
    if (currentNode->left != NULL && currentNode->right == NULL)
    {
        // Если корень
        if (tree->root == currentNode)
        {
            tree->root = currentNode->left;
            free(currentNode);
            return OK;
        }
        if (previousNode->left == currentNode)
        {
            previousNode->left = currentNode->left;
        }
        else
        {
            previousNode->right = currentNode->left;
        }
        free(currentNode);
        return OK;
    }
    else if (currentNode->left == NULL && currentNode->right != NULL)
    {
        if (tree->root == currentNode)
        {
            tree->root = currentNode->right;
            free(currentNode);
            return OK;
        }
        if (previousNode->left == currentNode)
        {
            previousNode->left = currentNode->left;
        }
        else
        {
            previousNode->left = currentNode->left;
        }
        free(currentNode);
        return OK;
    }

    // если оба ребёнка существуют
    Node *min = currentNode->right;
    previousNode = currentNode;
    while (min->left != NULL)
    {
        previousNode = min;
        min = min->left;
    }
    currentNode->key = min->key;
    currentNode->value = min->value;
    if (previousNode == currentNode)
    {
        currentNode->right = NULL;
    }
    else
    {
        previousNode->left = NULL;
    }
    free(min);
    return OK;
}

void print(Node *node)
{
    if (node != NULL)
    {
        print(node->left);
        printf("%s\n", node->value);
        print(node->right);
    }
}

void printTree(Tree *tree)
{
    print(tree->root);
}