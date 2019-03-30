//
// Created by zhenguo on 19-3-30.
//

#include <stdio.h>
#include "calc.h"

#define BUFFER_SIZE 10

int chbuf[BUFFER_SIZE];
int curBuf = 0;

int getch(void){
    return (curBuf > 0) ? chbuf[--curBuf]:getchar();
}

void ungetch(int c){
    if(curBuf >= BUFFER_SIZE){
        printf("error: buffer overflow!\n");
    }else{
        chbuf[curBuf++] = c;
    }
}