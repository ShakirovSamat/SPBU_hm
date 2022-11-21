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
        head->balance = 1;
        head->left->balance = -1;
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
        head->balance = -1;
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
        return bigRightRotate(tree);
    }
    if (tree->balance == -2)
    {
        if (tree->left->balance <= 0)
        {

            return rightRotate(tree);
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

int main()
{
    int comand = -1;
    Tree *tree = createtTree();
    printf("Comands:\n0 - exit\n1 - insert\n2 - is exist\n3 - delete\n\n");
    while (comand != 0)
    {
        printf("Enter comand: ");
        scanf("%d", &comand);

        switch (comand)
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            int key = 0;
            char *value = calloc(100, sizeof(char));
            scanf("%d", &key);
            fflush(stdin);
            fgets(value, 100, stdin);
            tree = insert(tree, key, value);
            break;
        }

        default:
            break;
        }
    }
    return 0;
}