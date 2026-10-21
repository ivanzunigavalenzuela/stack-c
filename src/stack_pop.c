/*
 * stack_pop.c
 * Saca el valor de arriba de la pila y lo deja en *value.
 * Devuelve false si la pila estaba vacía.
 */
#include <stdlib.h>
#include "stack.h"

bool stack_pop(Stack *stack, int *value)
{
    if (stack == NULL || stack->top == NULL) {
        return false;           /* no hay nada que sacar */
    }
    Node *old_top = stack->top;
    *value = old_top->value;
    stack->top = old_top->next; /* el de abajo pasa a ser el tope */
    free(old_top);              /* se libera la memoria del nodo sacado */
    stack->size = stack->size - 1;
    return true;
}
