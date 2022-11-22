#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
    int n = 0;
    int m = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);

    // creating graph
    int **graph = calloc(n + 1, sizeof(int *));
    for (int i = 0; i < n + 1; ++i)
    {
        graph[i] = calloc(n + 1, sizeof(int));
        for (int j = 0; j < n + 1; ++j)
        {
            graph[i][j] = 10000;
        }
    }

    // reading roads
    int i = 0;
    int j = 0;
    int len = 0;

    for (int b = 0; b < m; ++b)
    {
        fscanf(stdin, "%d %d %d", &i, &j, &len);
        if (graph[i][j] == NULL || graph[i][j] > len)
        {
            graph[i][j] = len;
            graph[j][i] = len;
        }
    }

    // reading capitals
    int k = 0;
    printf("Enter k: ");
    scanf("%d", &k);
    int **countries = calloc(k, sizeof(int *));
    for (int i = 0; i < k; ++i)
    {
        countries[i] = calloc(n, sizeof(int));
        for (int j = 0; j < n; ++j)
        {
            countries[i][j] = 0;
        }
    }

    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &countries[i][0]);
    }

    // floyd algorithm
    for (int k = 1; k < n + 1; ++k)
    {
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                graph[i][j] = graph[i][j] <= graph[i][k] + graph[k][j] ? graph[i][j] : graph[i][k] + graph[k][j];
            }
        }
    }

    // sorting cities
    for (int i = 1; i < n + 1; ++i)
    {
        bool isCapital = false;
        for (int j = 0; j < k; ++j)
        {
            if (countries[j][0] == i)
            {
                isCapital = true;
                break;
            }
        }
        if (isCapital)
        {
            continue;
        }
        int min = graph[i][countries[0][0]];
        int capital = 1;
        for (int j = 1; j < k; ++j)
        {
            if (min > graph[i][countries[0][j]])
            {
                min = graph[i][countries[0][j]];
                capital = j;
            }
        }
        int j = 0;
        int b = 0;
        while (countries[b][0] != capital)
        {
            ++b;
        }
        while (countries[b][j] != 0)
        {
            ++j;
        }
        countries[b][j] = i;
    }

    // output
    for (int i = 0; i < k; ++i)
    {
        printf("city %d: ", countries[i][0]);
        for (j = 1; j < n; ++j)
        {
            if (countries[i][j] == 0)
            {
                break;
            }
            printf("%d ", countries[i][j]);
        }
        printf("\n");
    }
    return 0;
}