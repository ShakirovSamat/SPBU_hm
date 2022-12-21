#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "stack.h"

#define STRING_LENGTH 100

int add(int a, int b) { return a + b; }

int substract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b) { return a / b; }

int makeArithmeticOperation(Stack *stack, char operation, int *res)
{
    int firstOperand = 0;
    int secondOperand = 0;

    int popError = popStack(stack, &secondOperand);
    if (popError != 0)
    {
        return popError;
    }

    popError = popStack(stack, &firstOperand);
    if (popError != 0)
    {
        return popError;
    }

    switch (operation)
    {
    case '+':
        *res = add(firstOperand, secondOperand);
        break;
    case '-':
        *res = substract(firstOperand, secondOperand);
        break;
    case '*':
        *res = multiply(firstOperand, secondOperand);
        break;
    case '/':
        if (secondOperand == 0)
        {
            return -3;
        }
        *res = divide(firstOperand, secondOperand);
        break;

    default:
        break;
    }
    return 0;
}

bool isArithmeticSign(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int calculatePolishNotaion(char polishNotaion[], int *result)
{
    Stack *stack = createStack();
    if (stack == NULL)
    {
        return -1;
    }

    for (int i = 0; polishNotaion[i] != '\0'; ++i)
    {
        if (isArithmeticSign(polishNotaion[i]))
        {
            int result = 0;
            int error = makeArithmeticOperation(stack, polishNotaion[i], &result);
            if (error != 0)
            {
                return error;
            }
            error = pushStack(stack, result);
            if (error != 0)
            {
                return error;
            }
        }
        else
        {
            if ('0' <= (int)polishNotaion[i] && (int)polishNotaion[i] <= '9')
            {
                pushStack(stack, (int)(int)polishNotaion[i] - 48);
            }
        }
    }
    // разобрать коварные случаи
    if (isEmptyStack(stack) == 0)
    {
        popStack(stack, result);
        if (isEmptyStack(stack) != 0)
        {
            deleteStack(stack);
            return 0;
        }
        else
        {
            deleteStack(stack);
            return -4;
        }
    }
    deleteStack(stack);
    return -4;
}

int test()
{
    int result = 0;
    char strings[6][4] = {"56+", "97-", "65*", "82/", "ab/", "57L"};
    int error = calculatePolishNotaion(strings[0], &result);
    if (result != 11 || error != 0)
    {
        return error;
    }
    error = calculatePolishNotaion(strings[1], &result);
    if (result != 2 || error != 0)
    {
        return error;
    }
    error = calculatePolishNotaion(strings[2], &result);
    if (result != 30 || error != 0)
    {
        return error;
    }
    error = calculatePolishNotaion(strings[3], &result);
    if (result != 4 || error != 0)
    {
        return error;
    }
    error = calculatePolishNotaion(strings[5], &result);
    if (error == 0)
    {
        return -4;
    }
    error = calculatePolishNotaion(strings[6], &result);
    if (error == 0)
    {
        return -4;
    }

    return 0;
}

void printErrorMessage(int error)
{
    switch (error)
    {
    case -1:
        printf("Memory error has occured");
        break;
    case -2:
        printf("Pop error has occured");
        break;
    case -3:
        printf("Dividing by zero error has occured");
        break;
    case -4:
        printf("Bad input get through function without errors");
        break;
    }
}

int main()
{
    printErrorMessage(test());

    char inputString[STRING_LENGTH + 1] = {0};

    printf("Enter reverse polish notation.\nMax length is %d: ", STRING_LENGTH);
    fgets(inputString, STRING_LENGTH + 1, stdin);

    int result = 0;
    int error = calculatePolishNotaion(inputString, &result);

    if (error != 0)
    {
        printErrorMessage(error);
    }
    else
    {
        printf("Calculated polish notation equals: %d\n", result);
    }

    return 0;
}