#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    int command = -1;
    TreeNode *tree = createTree();
    printf("Comands:\n  0: add\n  1: get\n  2: is Exist\n  3: delete\n  4: exit\n\n");

    while (command != 4)
    {
        printf("Enter command: ");
        scanf("%d", &command);
        int key = 0;
        switch (command)
        {
        case 0:;
            char *value = calloc(100, sizeof(char));
            printf("Enter key: ");
            scanf_s("%d", &key);
            printf("Enter value: ");
            fflush(stdin);
            fgets(value, 100, stdin);
            add(tree, key, value);
            break;

        case 1:;
            printf("Enter key: ");
            scanf_s("%d", &key);
            printf("%s\n", get(tree, key));
            break;

        case 2:;
            printf("Enter key: ");
            scanf_s("%d", &key);
            if (isExist(tree, key))
            {
                printf("Exist\n");
            }
            else
            {
                printf("Doesn't exist\n");
            }
            break;
        case 3:;
            printf("Enter key: ");
            scanf_s("%d", &key);
            delete (tree, key);
            break;
        case 4:
            return 0;
        }
    }
    return -1;
}