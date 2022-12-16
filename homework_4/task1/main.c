#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 32
// 16 бит
void decToBin(int dec, int size, int *bin)
{
    for (int i = 0; i < size; i++)
    {
        bin[i] = dec & 1;
        dec >>= 1;
    }
}
void addBin(int *bin1, int *bin2, int size, int *res)
{
    int transferBit = 0;
    int extraSum = 0;
    for (int i = 0; i < size; ++i)
    {
        extraSum = bin1[i] + bin2[i] + transferBit;
        res[i] = extraSum & 1;
        transferBit = extraSum >> 1;
    }
}

int binToDec(int *bin, int size)
{
    int result = 0;
    int power = 1;

    for (int i = 0; i < size; ++i)
    {
        result += bin[i] * power;
        power <<= 1;
    }

    return result;
}

void printBin(int *bin, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", bin[i]);
    }
    printf("\n");
}

bool testSum()
{
    int a = 0;
    int b = 0;
    int *bin1 = (int *)calloc(SIZE, sizeof(int));
    int *bin2 = (int *)calloc(SIZE, sizeof(int));
    int *res = (int *)calloc(SIZE, sizeof(int));
    for (int i = 0; i < 100; ++i)
    {
        a = i;
        b = 100 - i;
        decToBin(a, SIZE, bin1);
        decToBin(b, SIZE, bin2);
        addBin(bin1, bin2, SIZE, res);
        int sum = binToDec(res, SIZE);
        if (sum != a + b)
        {
            free(bin1);
            free(bin2);
            free(res);
            return false;
        }
    }
    free(bin1);
    free(bin2);
    free(res);
    return true;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    if (!testSum())
    {
        printf("Тесты не пройдены");
        return -1;
    }

    int dec1 = -1;
    int dec2 = -1;
    int *bin1 = (int *)calloc(SIZE, sizeof(int));
    int *bin2 = (int *)calloc(SIZE, sizeof(int));
    // Добавить отрицательные числа
    printf("Введите первое число. Оно должно быть неотрицательным\n");
    scanf("%d", &dec1);

    printf("Введите второе число. Оно должно быть неотрицательным\n");
    scanf("%d", &dec2);

    decToBin(dec1, SIZE, bin1);
    decToBin(dec2, SIZE, bin2);

    printf("Двоичная запись первого числа: ");
    printBin(bin1, SIZE);
    printf("Двоичная запись второго числа: ");
    printBin(bin2, SIZE);

    int *res = (int *)calloc(SIZE, sizeof(int));
    addBin(bin1, bin2, SIZE, res);
    printBin(res, SIZE);
    printf("Десятичная запись суммы чисел: ");
    printf("%d\n", binToDec(res, SIZE));

    free(bin1);
    free(bin2);
    free(res);
    return 0;
}