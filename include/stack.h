/*
 * stack.h
 * Declaraciones de la pila (stack) de enteros.
 * Todos los archivos .c que usan la pila incluyen este archivo.
 */
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>   /* para el tipo bool (true / false) */
#include <stddef.h>    /* para NULL */

/* Un nodo guarda un valor y apunta al nodo que está debajo de él. */
typedef struct Node {
    int value;
    struct Node *next;
} Node;

/* La pila solo necesita saber cuál es el nodo de arriba (top)
   y cuántos elementos tiene (size). */
typedef struct Stack {
    Node *top;
    int size;
} Stack;

Stack *stack_create(void);
bool   stack_push(Stack *stack, int value);
bool   stack_pop(Stack *stack, int *value);
bool   stack_peek(const Stack *stack, int *value);
bool   stack_is_empty(const Stack *stack);
void   stack_destroy(Stack *stack);

#endif
