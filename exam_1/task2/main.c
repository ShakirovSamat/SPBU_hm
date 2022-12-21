#include <stdio.h>
#include <string.h>

typedef struct Product
{
    int cost;
    char name[100];
} Product;

void bubbleSort(Product *prodcts, int size, char *iterator)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (prodcts[j - 1].cost > prodcts[j].cost && strcmp(iterator, "cost") == 0 || strcmp(prodcts[j - 1].name, prodcts[j].name) < 0 && strcmp(iterator, "name") == 0)
            {
                Product temp = prodcts[j - 1];
                prodcts[j - 1] = prodcts[j];
                prodcts[j] = temp;
            }
        }
    }
}

int main()
{
    Product products[1000] = {0};
    FILE *file = fopen("storage.txt", "r");
    int size = 0;

    int products50 = 0;
    int products25 = 0;

    printf("Enter amount of products with 50%% discount: ");
    scanf("%d", &products50);
    if (products50 < 0)
    {
        printf("Wrong input: anount of products with 50%% discount should be positive or should equal to zero\n");
        return 0;
    }

    printf("Enter amount of products with 25%% discount: ");
    scanf("%d", &products25);
    if (products25 < 0)
    {
        printf("Wrong input: anount of products with 25%% discount should be positive or should equal to zero\n");
        return 0;
    }
    printf("\n");
    char c = 0;
    for (;; size++)
    {
        if (size == 1000 || fscanf(file, "%s %c %d", products[size].name, &c, &products[size].cost) == EOF)
        {
            break;
        }
    }
    if (products25 + products50 > size)
    {
        printf("Wrong input: amount of products less than sum of products with 50%% discount and 25%% discount\n");
        return -1;
    }
    bubbleSort(products, size, "cost");
    printf("Products with 50%% discount:\n");
    for (int i = size - 1; i >= (size - products50); --i)
    {
        printf("%s - %d\n", products[i].name, products[i].cost);
    }
    printf("\n");

    bubbleSort(products, (size - products50), "name");
    printf("Products with 25%% discount:\n");
    for (int i = size - products50 - 1; i >= (size - products50 - products25); --i)
    {
        printf("%s - %d\n", products[i].name, products[i].cost);
    }
    printf("\n");

    return 0;
}