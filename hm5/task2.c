#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool isCorrectString(char string[])
{
    Stack *stack = createStack();
    // Проверить на память
    // Возвращать конкретный код ошибки
    // Добавить проверки пуш и поп
    int a = 0;
    for (int i = 0; string[i] != '\0'; ++i)
    {
        int previousBracket = 0;
        switch (string[i])
        {
        case '(':
        case '{':
        case '[':
            pushStack(stack, (int)string[i]);
            break;
        case ')':
            popStack(stack, &previousBracket);
            if (previousBracket != '(' || isEmptyStack(stack) && previousBracket == 0)
            {
                printf("%c", previousBracket);
                return false;
            }
            break;
        case '}':
            popStack(stack, &previousBracket);
            if (previousBracket != '{' || isEmptyStack(stack) && previousBracket == 0)
            {
                return false;
            }
            break;
        case ']':
            popStack(stack, &previousBracket);
            if (previousBracket != '[' || isEmptyStack(stack) && previousBracket == 0)
            {
                return false;
            }
            break;
        }
    }
    return isEmptyStack(stack);
}

// Добавить разные случаи
bool test()
{
    char strings[4][7] = {"(){}[]", "((()))", "({[})]", "({})[]"};
    if (!isCorrectString(strings[0]))
    {
        return false;
    }
    if (!isCorrectString(strings[1]))
    {
        return false;
    }
    if (isCorrectString(strings[2]))
    {
        return false;
    }
    if (!isCorrectString(strings[3]))
    {
        return false;
    }

    return true;
}

int main()
{
    if (!test())
    {
        printf("Error in isCorrectString function");
        return -1;
    }
    char str[101] = {0};
    printf("Enter your string. Max lenght is 100 signs: ");
    scanf_s("%100s", str);

    // Добавить почему строка неправильная
    if (isCorrectString(str))
    {
        printf("String is correct");
    }
    else
    {
        printf("String is incorrect");
    }
    return 0;
}