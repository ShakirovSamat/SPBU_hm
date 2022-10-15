#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 16


void decToBin(int dec, int size, int* bin)
{
    for (int i = 0; i < size; i++) {
        bin[i] = dec % 2;
        dec /= 2;
    }
}

void addBin(int *bin1, int *bin2, int size, int *res)
{
    for(int i = size - 1; i >= 0; --i)
    {
        res[i] += bin1[i] + bin2[i];
        if (res[i] >= 2)
        {
            res[i + 1] += 1;
        }
        res[i] %= 2;
    }
}

int binToDec(int *bin, int size)
{
    float res = 0;
    for(int i = 0; i < size; ++i)
    {
        res += bin[i] * pow(2.0, i);
    }
    return (int)res;
}

void printBin(int *bin, int size) 
{
    for (int i = size - 1; i >= 0; i--) 
    {
        printf("%d ", bin[i]);
    }
    printf("\n");
}


int testSum()
{
    int a = 0;
    int b = 0;
    int* bin1 = (int *) calloc(SIZE, sizeof(int));
    int* bin2 = (int *) calloc(SIZE, sizeof(int));
    int* res = (int *) calloc(SIZE, sizeof(int));
    for (int i = 0; i < 100; ++i)
    {
        a = i;
        b = 100 - i;
        decToBin(a,SIZE,bin1);
        decToBin(b,SIZE,bin2);
        addBin(bin1, bin2, SIZE, res);
        int sum = binToDec(res, SIZE);
        if (sum != a + b)
        {
            free(bin1);
            free(bin2);
            free(res);
            return -1;
        }
    }
    free(bin1);
    free(bin2);
    free(res);
    return 0;
}

int main()
{
    if (!testSum())
    {
        printf("Sum error");
        return -1;
    }

    setlocale(LC_ALL, "Ru");

    int dec1 = -1;
    int dec2 = -1;
    int* bin1 = (int *) calloc(SIZE, sizeof(int));
    int* bin2 = (int *) calloc(SIZE, sizeof(int));

    do
    {
        printf("Введите первое число. Оно должно быть неотрицательным\n");
        scanf("%d", &dec1);
    } while (dec1 < 0);
    
    do
    {
        printf("Введите второе число. Оно должно быть неотрицательным\n");
    scanf("%d", &dec2);
    } while (dec2 < 0);
    

    decToBin(dec1, SIZE, bin1);
    decToBin(dec2, SIZE, bin2);

    printf("Двоичная запись первого числа: ");
    printBin(bin1, SIZE);
    printf("Двоичная запись второго числа: ");
    printBin(bin2, SIZE);

    int *res = (int *) calloc(SIZE, sizeof(int));
    addBin(bin1, bin2, SIZE, res);
    printf("Десятичная запись суммы чисел: ");
    printf("%d\n",binToDec(res, SIZE));

    free(bin1);
    free(bin2);
    free(res);
    return 0;
}