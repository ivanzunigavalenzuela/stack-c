/*
 * stack_push.c
 * Agrega un valor arriba de la pila.
 * Devuelve true si pudo agregarlo y false si no.
 */
#include <stdlib.h>
#include "stack.h"

bool stack_push(Stack *stack, int value)
{
    if (stack == NULL) {
        return false;
    }
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return false;           /* no había memoria disponible */
    }
    node->value = value;
    node->next = stack->top;    /* el nuevo nodo queda encima del anterior */
    stack->top = node;          /* y pasa a ser el nuevo tope */
    stack->size = stack->size + 1;
    return true;
}
