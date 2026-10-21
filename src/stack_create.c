/*
 * stack_create.c
 * Crea una pila vacía en memoria dinámica.
 */
#include <stdlib.h>
#include "stack.h"

Stack *stack_create(void)
{
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;            /* no había memoria disponible */
    }
    stack->top = NULL;          /* una pila vacía no tiene nodo de arriba */
    stack->size = 0;
    return stack;
}
