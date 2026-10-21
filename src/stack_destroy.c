/*
 * stack_destroy.c
 * Libera todos los nodos y la pila misma.
 * Después de llamarla, el puntero a la pila ya no se puede usar.
 */
#include <stdlib.h>
#include "stack.h"

void stack_destroy(Stack *stack)
{
    if (stack == NULL) {
        return;
    }
    Node *current = stack->top;
    while (current != NULL) {
        Node *next = current->next; /* se guarda el siguiente antes de liberar */
        free(current);
        current = next;
    }
    free(stack);
}
