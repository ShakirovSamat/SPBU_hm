#include <stdlib.h>
typedef struct Tree
{
    int balance;
    int key;
    char *value;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *leftRotate(Tree *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->right->balance == -1)
    {
        tree->right->balance = 0;
        tree->balance = 0;
    }
    else
    {
        tree->right->balance = 1;
        tree->balance = -1;
    }
    Tree *head = tree->right;
    tree->right = head->left;
    head->left = tree;
    return head;
}

Tree *rihghtRotate(Tree *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->left->balance == -1)
    {
        tree->left->balance = 0;
        tree->balance = 0;
    }
    else
    {
        tree->left->balance = 1;
        tree->balance = -1;
    }

    Tree *head = tree->left;
    tree->left = head->right;
    head->right = tree;
    return head;
}

Tree *bigLeftRotate(Tree *tree)
{
    tree = rihghtRotate(tree);
    return leftRotate(tree);
}

Tree *bigRightRotate(Tree *tree)
{
    tree = leftRotate(tree);
    return rihghtRotate(tree);
}

Tree *balance(Tree *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->balance == 2)
    {
        if (tree->right->balance > 0)
        {
            return leftRotate(tree);
        }
        return bigRightRotate(tree);
    }
    if (tree->balance == -2)
    {
        if (tree->left->balance < 0)
        {

            return rihghtRotate(tree);
        }
        return bigLeftRotate(tree);
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
