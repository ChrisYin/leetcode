//
// Created by zhenguo on 19-3-30.
//
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100
int main(){

    char inputArray[MAXOP];

    int op, op2;
    while((op = getop(inputArray)) != EOF){
        switch (op){
            case NUMBER:
                push(atof(inputArray));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0){
                    push(pop()/op2);
                }else{
                    printf("zero divisor\n");
                }
                break;
            case '\n':
                printf("res: %g\n", pop());
                clearStack();
                break;
            default:
                printf("unknown character: %c\n", op);
        }
    }
    return 0;
}
