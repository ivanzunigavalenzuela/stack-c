/*
 * test_stack.c
 * Pruebas unitarias de la pila usando assert.
 * Si una condición es falsa, el programa se detiene e indica la línea.
 */
#include <assert.h>
#include <stdio.h>
#include "stack.h"

static void test_new_stack_is_empty(void)
{
    Stack *stack = stack_create();
    assert(stack != NULL);
    assert(stack_is_empty(stack));
    stack_destroy(stack);
}

static void test_push_then_peek_returns_last_value(void)
{
    Stack *stack = stack_create();
    int value = 0;
    stack_push(stack, 1);
    stack_push(stack, 2);
    assert(stack_peek(stack, &value));
    assert(value == 2);
    assert(stack->size == 2);       /* peek no saca nada */
    stack_destroy(stack);
}

static void test_pop_follows_lifo_order(void)
{
    Stack *stack = stack_create();
    int value = 0;
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    assert(stack_pop(stack, &value) && value == 3);
    assert(stack_pop(stack, &value) && value == 2);
    assert(stack_pop(stack, &value) && value == 1);
    assert(stack_is_empty(stack));
    stack_destroy(stack);
}

static void test_pop_on_empty_stack_fails(void)
{
    Stack *stack = stack_create();
    int value = 0;
    assert(!stack_pop(stack, &value));
    assert(!stack_peek(stack, &value));
    stack_destroy(stack);
}

int main(void)
{
    test_new_stack_is_empty();
    test_push_then_peek_returns_last_value();
    test_pop_follows_lifo_order();
    test_pop_on_empty_stack_fails();
    printf("Todas las pruebas pasaron\n");
    return 0;
}
