#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMaxInRow(int **matrix, int columnIndex, int rowIndex, int columnLength, int rowLength)
{
    for (int i = 0; i < rowLength; ++i)
    {
        if (rowIndex == i)
        {
            continue;
        }
        if (matrix[columnIndex][rowIndex] <= matrix[columnIndex][i])
        {
            return false;
        }
    }
    return true;
}

bool isMinInRow(int **matrix, int columnIndex, int rowIndex, int columnLength, int rowLength)
{
    for (int i = 0; i < rowLength; ++i)
    {
        if (rowIndex == i)
        {
            continue;
        }
        if (matrix[columnIndex][rowIndex] >= matrix[columnIndex][i])
        {
            return false;
        }
    }
    return true;
}

bool isMaxInColumn(int **matrix, int columnIndex, int rowIndex, int columnLength, int rowLength)
{
    for (int i = 0; i < columnLength; ++i)
    {
        if (columnIndex == i)
        {
            continue;
        }
        if (matrix[columnIndex][rowIndex] <= matrix[i][rowIndex])
        {
            return false;
        }
    }
    return true;
}

bool isMinInColumn(int **matrix, int columnIndex, int rowIndex, int columnLength, int rowLength)
{
    for (int i = 0; i < columnLength; ++i)
    {
        if (columnIndex == i)
        {
            continue;
        }
        if (matrix[columnIndex][rowIndex] >= matrix[i][rowIndex])
        {
            return false;
        }
    }
    return true;
}

bool isSaddlePoint(int **matrix, int columnIndex, int rowIndex, int columnLength, int rowLength)
{
    if (isMaxInColumn(matrix, columnIndex, rowIndex, columnLength, rowLength) && isMinInRow(matrix, columnIndex, rowIndex, columnLength, rowLength))
    {
        return true;
    }
    if (isMinInColumn(matrix, columnIndex, rowIndex, columnLength, rowLength) && isMaxInRow(matrix, columnIndex, rowIndex, columnLength, rowLength))
    {
        return true;
    }
    return false;
}

int main()
{
    FILE *file = fopen("matrix.txt", "r");
    if (file == NULL)
    {
        return -1;
    }

    int rowLength = 0;
    int columnLength = 0;
    int error = fscanf(file, "%d %d", &columnLength, &rowLength);
    if (error != 2)
    {
        return -1;
    }
    if (rowLength <= 0 || columnLength <= 0)
    {
        printf("Wrong matrix length");
        return -1;
    }

    int **matrix = (int **)malloc(sizeof(int *) * columnLength);
    if (*matrix == NULL)
    {
        return -1;
    }
    for (int i = 0; i < columnLength; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * rowLength);
        if (matrix[i] == NULL)
        {
            return -1;
        }
    }

    for (int i = 0; i < columnLength; ++i)
    {
        int error = 0;
        for (int j = 0; j < rowLength; ++j)
        {
            char c = 0;
            error = fscanf(file, "%d%c", &matrix[i][j], &c);
            if (c == '\n' && j + 1 != rowLength)
            {
                printf("Wrong input");
                return -1;
            }
            if (error != 2 && i + 1 != columnLength)
            {
                printf("Wrong matrix input");
                return -1;
            }
        }
    }

    for (int i = 0; i < columnLength; ++i)
    {
        for (int j = 0; j < rowLength; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Saddle points:\n");
    for (int i = 0; i < columnLength; i++)
    {
        for (int j = 0; j < rowLength; ++j)
        {
            if (isSaddlePoint(matrix, i, j, columnLength, rowLength))
            {
                printf("%d %d\n", i + 1, j + 1);
            }
        }
    }

    return 0;
}