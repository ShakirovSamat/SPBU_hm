#include <stdio.h>
#include "tree.h"

int main()
{
    int comand = -1;
    Tree *tree = createtTree();
    printf("Comands:\n0 - exit\n1 - insert\n2 - get\n3 - delete\n\n");
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
        case 2:
        {
            int key = 0;
            scanf("%d", &key);
            char *res = get(tree, key);
            printf("%s\n", res);
            break;
        }

        default:
            break;
        }
    }
    return 0;
}