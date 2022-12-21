#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <stdbool.h>

typedef struct Stack Stack;

Stack *createStack();

int pushStack(Stack *stack, int value);

int popStack(Stack *stack, int *res);

int deleteStack(Stack *stack);

int isEmptyStack(Stack *stack);

#endif // CORE_H_INCLUDED