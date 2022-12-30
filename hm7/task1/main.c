#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree *tree = createTree();
    if (tree == NULL)
    {
        return -1;
    }

    printf("Commands:\n1 - add new element to tree\n2 - get element from tree\n3 - check out if element exists\n4 - delete element form tree\n5 - print tree\n6 - show commands\n\n");

    int command = -1;

    while (command != 0)
    {
        printf("Enter command: ");
        scanf("%d", &command);

        switch (command)
        {
        case 1:
        {
            int key = 0;
            char *value = calloc(31, sizeof(char));
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value. Max length is 30 sighs: ");
            scanf("%30s", value);
            int error = insert(tree, key, value);
            if (error == NOT_FOUND)
            {
                printf("There is not such key");
                break;
            }
            if (error != OK)
            {
                return error;
            }
            break;
        }
        case 2:
        {
            int key = 0;
            char *result = NULL;
            printf("Enter key: ");
            scanf("%d", &key);
            int error = get(tree, key, &result);
            if (error != OK)
            {
                return error;
            }
            if (result == NULL)
            {
                printf("There wasn't found such key\n");
                break;
            }
            printf("value: %s\n", result);
            break;
        }
        case 3:
        {
            int key = 0;
            printf("Enter key: ");
            scanf("%d", &key);
            if (isExist(tree, key))
            {
                printf("Such key exists\n");
            }
            else
            {
                printf("Such key wasn't found\n");
            }
            break;
        }
        case 4:
        {
            int key = 0;
            printf("Enter key: ");
            scanf("%d", &key);
            int error = delete (tree, key);
            if (error == NOT_FOUND)
            {
                printf("Such key wasn't found\n");
                break;
            }
            else if (error != OK)
            {
                return error;
            }
            printf("Key %d was deleted\n", key);
            break;
        }
        case 5:
            printTree(tree);
            break;
        case 6:
            printf("Commands:\n1 - add new element to tree\n2 - get element from tree\n3 - check out if element exists\n4 - delete element form tree\n5 - print tree\n6 - show commands\n\n");
            break;
        }
    }
    return 0;
}