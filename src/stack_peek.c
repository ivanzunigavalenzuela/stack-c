/*
 * stack_peek.c
 * Mira el valor de arriba sin sacarlo y lo deja en *value.
 * Devuelve false si la pila está vacía.
 */
#include "stack.h"

bool stack_peek(const Stack *stack, int *value)
{
    if (stack == NULL || stack->top == NULL) {
        return false;
    }
    *value = stack->top->value;
    return true;
}
