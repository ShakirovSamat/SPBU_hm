#include <stdlib.h>
#include <stdio.h>
typedef struct Tree
{
    int balance;
    int key;
    char *value;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *createtTree()
{
    return NULL;
}
Tree *leftRotate(Tree *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    Tree *head = tree->right;
    tree->right = head->left;
    head->left = tree;

    if (head->balance == 0)
    {
        head->balance = -1;
        head->left->balance = 1;
    }
    else
    {
        head->balance = 0;
        head->left->balance = 0;
    }
    return head;
}

Tree *rightRotate(Tree *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    Tree *head = tree->left;
    tree->left = head->right;
    head->right = tree;

    if (head->balance == 0)
    {
        head->balance = 1;
        head->right->balance = -1;
    }
    else
    {
        head->balance = 0;
        head->right->balance = 0;
    }

    return head;
}

Tree *bigLeftRotate(Tree *tree)
{
    Tree *head = tree->right->left;

    Tree *rightChild = tree->right;
    rightChild->left = head->right;

    Tree *leftChild = tree;
    leftChild->right = head->left;

    head->left = leftChild;
    head->right = rightChild;

    switch (head->balance)
    {
    case -1:
        head->right->balance = 1;
        head->left->balance = 0;
        break;
    case 0:
        head->right->balance = 0;
        head->left->balance = 0;
        break;
    case 1:
        head->right->balance = 0;
        head->left->balance = -1;
        break;
    }
    head->balance = 0;

    return head;
}

Tree *bigRightRotate(Tree *tree)
{
    Tree *head = tree->left->right;

    Tree *leftChild = tree->left;
    leftChild->right = head->left;

    Tree *rightChild = tree;
    rightChild->left = head->right;

    head->left = leftChild;
    head->right = rightChild;

    switch (head->balance)
    {
    case -1:
        head->left->balance = 0;
        head->right->balance = 1;
        break;
    case 0:
        head->left->balance = 0;
        head->right->balance = 0;
        break;
    case 1:
        head->left->balance = -1;
        head->right->balance = 0;
        break;
    }
    head->balance = 0;
    return head;
}

Tree *balance(Tree *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->balance == 2)
    {
        if (tree->right->balance >= 0)
        {
            return leftRotate(tree);
        }
        return bigLeftRotate(tree);
    }
    if (tree->balance == -2)
    {
        if (tree->left->balance <= 0)
        {

            return rightRotate(tree);
        }
        return bigRightRotate(tree);
    }
    return tree;
}

Tree *insert(Tree *tree, int key, char *value)
{
    if (tree == NULL)
    {
        Tree *newTree = calloc(1, sizeof(Tree));
        newTree->key = key;
        newTree->value = value;
        newTree->balance = 0;
        return newTree;
    }
    if (tree->key > key)
    {
        tree->left = insert(tree->left, key, value);
        tree->balance--;
    }
    else
    {
        tree->right = insert(tree->right, key, value);
        tree->balance++;
    }
    return balance(tree);
}

char *get(Tree *tree, int key)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->key == key)
    {
        return tree->value;
    }
    else if (tree->key > key)
    {
        return get(tree->left, key);
    }
    else
    {
        return get(tree->right, key);
    }
}

int delete (Tree *tree, int key)
{
    if (tree == NULL)
    {
        return 0;
    }
    Tree *currentTree = tree;
    Tree *previousTree = NULL;
    while (currentTree != NULL && currentTree->key != key)
    {
        previousTree = currentTree;
        if (currentTree->key > key)
        {
            currentTree = currentTree->left;
        }
        else
        {
            currentTree = currentTree->right;
        }
    }
    if (currentTree == NULL)
    {
        return 0;
    }
}