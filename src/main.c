/*
 * main.c
 * Programa de demostración: usa cada operación de la pila.
 */
#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack *stack = stack_create();
    if (stack == NULL) {
        printf("Error: no se pudo crear la pila\n");
        return 1;
    }

    printf("La pila esta vacia? %s\n", stack_is_empty(stack) ? "si" : "no");

    printf("Apilando 10, 20 y 30\n");
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    int value;
    if (stack_peek(stack, &value)) {
        printf("Valor en la cima: %d\n", value);
    }

    printf("Desapilando todo:\n");
    while (stack_pop(stack, &value)) {
        printf("  sale %d\n", value);
    }

    printf("La pila esta vacia? %s\n", stack_is_empty(stack) ? "si" : "no");

    stack_destroy(stack);
    return 0;
}
