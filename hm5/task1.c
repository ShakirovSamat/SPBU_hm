#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct StackElement
{
    int value;
    struct StackElement *next;
} StackElement;

typedef struct Stack
{
    StackElement *top;
} Stack;

Stack *createStack()
{
    return calloc(1, sizeof(Stack));
}

int pushStack(Stack *stack, int value)
{
    if (stack == NULL)
    {
        return -1;
    }

    StackElement *newElement = calloc(1, sizeof(StackElement));
    // Проверить выделение памяти
    if (newElement == NULL)
    {
        return -1;
    }
    newElement->value = value;

    if (stack->top == NULL)
    {
        stack->top = newElement;
        return 0;
    }

    newElement->next = stack->top;
    stack->top = newElement;
    return 0;
}

int popStack(Stack *stack, int *res)
{
    if (stack == NULL)
    {
        return -1;
    }
    if (stack->top == NULL)
    {
        return -2;
    }
    *res = stack->top->value;
    StackElement *elementToFree = stack->top;
    stack->top = stack->top->next;
    free(elementToFree);

    return 0;
}

int deleteStack(Stack *stack)
{
    if (stack == NULL)
    {
        return -1;
    }

    StackElement *curElement = stack->top;

    while (curElement != NULL)
    {
        StackElement *nextEleement = curElement->next;
        free(curElement);
        curElement = nextEleement;
    }

    free(stack);
    return 0;
}
// Разобраться с Null случаем
int isEmptyStack(Stack *stack)
{
    if (stack == NULL)
    {
        return -2;
    }

    if (stack->top == NULL)
    {
        return -1;
    }
    return 0;
}

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
    // Арифметические исключения + вынести в функцию арифметические опреации
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
            return -1;
        }
    }
    // Добавить проверки: пустой стек после снятия и непустой стек до снятия
    deleteStack(stack);
    return -1;
}
// Доработать тест
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

int main()
{
    switch (test())
    {
    case -1:
        printf("Memory error has occured");
        break;
    case -2:
        printf("Pop has occured");
        break;
    case -3:
        printf("Dividing by zero");
        break;
    case -4:
        printf("Bad input get through function without errors");
        break;
    }
    char inputString[101] = {0};
    printf("Enter reverse polish notation.Max length is 100: ");
    scanf_s("%100s", inputString);
    int result = 0;
    int error = calculatePolishNotaion(inputString, &result);
    if (error != 0)
    {
        switch (error)
        {
        case -1:
            printf("Memory error has occured");
            break;
        case -2:
            printf("Pop has occured");
            break;
        case -3:
            printf("Dividing by zero");
            break;
        }
    }
    else
    {
        printf("Calculated polish notation equals: %d\n", result);
    }

    return 0;
}