//
// Created by zhenguo on 19-4-2.
//

/*
 *  Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
 *  Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
 *  Peek or Top: Returns top element of stack.
 *  isEmpty: Returns true if stack is empty, else false.
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

/*
 * typedef struct STACK{
 *   ITEM *array;
 *   int top;
 *   int stackSize;
 * }STACK;
 */
STACK* STACKcreate(int stackSize){

    if(stackSize <= 0 || stackSize > INT_MAX)
        return NULL;

    STACK *stack = malloc(sizeof(STACK));

    ITEM *itemArray = malloc(sizeof(ITEM) * stackSize);

    stack->array = itemArray;
    stack->top = 0;
    stack->stackSize = stackSize;

    return stack;
}

int STACKempty(STACK *stack){
    if(stack == NULL)
        return -1;
    memset(stack->array, 0, sizeof(ITEM) * stack->stackSize);
    stack->top = 0;
}

void STACKpush(STACK *stack, ITEM item){
    if(stack == NULL)
        return;

    if(stack->top >= stack->stackSize)
        return;

    stack->array[stack->top++] = item;
    return;
}

ITEM STACKpop(STACK *stack){
    if(stack == NULL)
        return NULL;

    if(stack->top <= 0)
        return NULL;

    return stack->array[--stack->top];
}