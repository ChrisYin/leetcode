//
// Created by zhenguo on 19-4-2.
//
#include <stdio.h>
#include <lib/stack.h>

/*
 * testcase:
 */
int main(){
    STACK *stack = STACKcreate(2);
    STACKpush(stack, 10);
    STACKpush(stack, 11);
    STACKpop(stack);
    STACKpop(stack);
    STACKpop(stack);
    STACKpop(stack);
    STACKpush(stack, 11);
    STACKpush(stack, 12);
    STACKpush(stack, 31);
    int element;
    while((element = STACKpop(stack))!=NULL){
        printf("%d\n", element);
    }
    printf("end\n");
    return 0;
}