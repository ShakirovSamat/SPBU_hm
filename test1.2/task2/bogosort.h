#pragma once
#include <stdbool.h>

typedef int Error;

bool correct(int *arrray, int len);

Error swap(int *arrray, int indexFirst, int indexSecond);

Error randomSort(int *array, int len);

Error bogoSort(int *array, int len);
