#pragma once

typedef struct Stack Stack;

Stack *createStack();

int push(Stack *stack, int value);

int pop(Stack *stack, int *res);

int add(Stack *stack);

int print(Stack *stack);