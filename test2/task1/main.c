#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *maxDataFunction(char *data1, char *data2)
{
    // year
    int index1 = 6;
    int index2 = 6;
    while (data1[index1] != '\0')
    {
        ++index1;
    }
    while (data2[index2] != '\0')
    {
        ++index2;
    }

    if (index1 > index2)
    {
        return data1;
    }
    if (index1 < index2)
    {
        return data2;
    }

    int index = 6;

    for (;;)
    {
        if (data1[index] > data2[index])
        {
            return data1;
        }
        if (data1[index] < data2[index])
        {
            return data2;
        }
        ++index;
    }

    // month
    if (data1[3] > data2[3])
    {
        return data1;
    }
    if (data1[3] < data2[3])
    {
        return data2;
    }
    if (data1[4] > data2[4])
    {
        return data1;
    }
    if (data1[4] < data2[4])
    {
        return data2;
    }

    // day
    if (data1[0] > data2[0])
    {
        return data1;
    }
    if (data1[0] < data2[0])
    {
        return data2;
    }
    if (data1[1] > data2[1])
    {
        return data1;
    }
    if (data1[1] < data2[1])
    {
        return data2;
    }

    // if equal
    return data1;
}

int main()
{
    FILE *file = fopen("text.txt", "r");

    bool isDataInText = false;
    char currentSign;

    char *data = calloc(15, sizeof(char));

    char *maxData = calloc(15, sizeof(char));
    maxData = "01.01.01";

    for (;;)
    {
        currentSign = fgetc(file);
        if (currentSign == EOF)
        {
            break;
        }
        // is it a data
        if ('0' <= currentSign && currentSign <= '3')
        {
            data[0] = currentSign;
            currentSign = fgetc(file);
            if (data[0] == '3' && '0' <= currentSign && currentSign <= '1' || data[0] != '3' && '0' <= currentSign && currentSign <= '9')
            {
                data[1] = currentSign;
                currentSign = fgetc(file);
                if (currentSign == '.')
                {
                    data[2] = currentSign;
                    currentSign = fgetc(file);
                    if ('0' <= currentSign <= '1')
                    {
                        data[3] = currentSign;
                        currentSign = fgetc(file);
                        if (data[3] == '0' && '0' <= currentSign && currentSign <= '9' || data[3] == '1' && '0' <= currentSign && currentSign <= '2')
                        {
                            data[4] = currentSign;
                            currentSign = fgetc(file);
                            if (currentSign == '.')
                            {
                                data[5] = currentSign;
                                int index = 6;
                                for (;;)
                                {
                                    currentSign = fgetc(file);
                                    if (currentSign == EOF || currentSign < '0' || currentSign > '9')
                                    {
                                        break;
                                    }
                                    data[index] = currentSign;
                                    ++index;
                                }
                                // is it currently maxData data
                                char *curData = data;
                                maxData = maxDataFunction(maxData, data);
                                if (maxData != curData)
                                {
                                    free(curData);
                                }
                                data = calloc(15, sizeof(char));
                                isDataInText = true;
                            }
                        }
                    }
                }
            }
        }
    }
    if (isDataInText)
    {
        printf("%s\n", maxData);
    }
    else
    {
        printf("No data in the text\n");
    }
    return 0;
}