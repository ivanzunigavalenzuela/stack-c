/*
 * stack_is_empty.c
 * Indica si la pila no tiene elementos.
 */
#include "stack.h"

bool stack_is_empty(const Stack *stack)
{
    return stack == NULL || stack->top == NULL;
}
