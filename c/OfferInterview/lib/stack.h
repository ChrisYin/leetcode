//
// Created by zhenguo on 19-4-2.
//

#ifndef FOROFFER_STACK_H
#define FOROFFER_STACK_H

typedef int ITEM;

typedef struct STACK{
    ITEM *array;
    int top;
    int stackSize;
}STACK;

STACK* STACKcreate(int stackSize);

int STACKempty(STACK *stack);

void STACKpush(STACK *stack, ITEM item);

ITEM STACKpop(STACK *stack);

#endif //FOROFFER_STACK_H
