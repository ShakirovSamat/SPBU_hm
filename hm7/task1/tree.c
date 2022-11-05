#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

typedef int Error;

typedef struct TreeNode
{
    int key;
    char *value;
    struct TreeNode *parent;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode * createTree()
{
    return calloc(1, sizeof(TreeNode));
}

Error add(TreeNode *tree, int key, char *value)
{
    if (tree == NULL)
    {
        return -1;
    }

    TreeNode *newNode = calloc(1, sizeof(TreeNode));
    newNode->value = value;
    newNode->key = key;

    if (tree->value == NULL || tree->key == key)
    {
        tree->key = key;
        tree->value = value;
        return 0;
    }
    TreeNode *currentNode = tree;
    TreeNode *previousNode = NULL;

    while (currentNode != NULL)
    {
        previousNode = currentNode;
        if (currentNode->key == key)
        {
            if (previousNode->key > key)
            {
                previousNode->left = newNode;
            }
            else
            {
                previousNode->right = newNode;
            }
            newNode->parent = previousNode;
            return 0;
        }
        else if (currentNode->key > key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    if (previousNode->key > key)
    {
        previousNode->left = newNode;
    }
    else
    {
        previousNode->right = newNode;     
    }
    newNode->parent = previousNode;
    return 0;
}

char * get(TreeNode *tree, int key)
{
    if (tree == NULL)
    {
        return NULL;
    }

    TreeNode *currentNode = tree;

    while (currentNode != NULL)
    {
        if (currentNode->key == key)
        {
            return currentNode->value;
        }
        else if (currentNode->key > key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }
    return NULL;
}

bool isExist(TreeNode *tree, int key)
{
    if (tree == NULL)
    {
        return -1;
    }

    TreeNode *currentNode = tree;
    
    while (currentNode != NULL)
    {
        if (currentNode->key == key)
        {
            return true;
        }
        else if(currentNode-> key > key)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }
    return false;
}

Error delete(TreeNode * tree, int key)
{
    if (tree == NULL)
    {
        return 0;
    }
    
    if (tree->key > key)
    {
        delete(tree->left, key);
    }
    else if (tree->key < key)
    {
        delete(tree->right, key);
    }
    else
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            if (tree->parent->left == tree)
            {
                tree->parent->left = NULL;
            }
            else
            {
                tree->parent->right = NULL;
            }
            free(tree);
            return 0;
        }
        else if (tree->left != NULL && tree->right != NULL)
        {
            if (tree->right->left == NULL)
            {
                if (tree->parent->left == tree)
                {
                    tree->parent->left = tree->right;
                }
                else
                {
                    tree->parent->right = tree->right;
                }
                tree->right->parent = tree->parent;
                free(tree);
                return 0;
            }
            TreeNode *currentNode = tree->right->left;
            while (currentNode->left != NULL)
            {
                currentNode = currentNode->left;
            }
            tree->value = currentNode->value;
            tree->key = currentNode->key;
            delete(currentNode, currentNode->key); 
        }
    }
    return 0;
}