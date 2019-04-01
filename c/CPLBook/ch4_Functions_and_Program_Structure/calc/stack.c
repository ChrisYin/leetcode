//
// Created by zhenguo on 19-3-30.
//
#include <stdio.h>
#include "calc.h"

#define STACK_SIZE 100

double stack[STACK_SIZE];
int stkp = 0;

void push(double num){
    if(stkp >= STACK_SIZE){
        printf("error: stack overflow!\n");
    }else{
        stack[stkp++] = num;
    }
}

double pop(void){
    if(stkp <= 0){
        printf("error: stack empty\n");
        return 0.0;
    }else{
        return stack[--stkp];
    }
}

void clearStack(void){
    stkp = 0;
}