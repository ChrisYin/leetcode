//
// Created by zhenguo on 19-3-30.
//
#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char string[]) {

    /*
     * using getch and ungetch to getop
     *
     * 1. skip spaces and blanks
     * 2. get operations: + - * /
     * 3. get digit number
     */
    int c;

    //skip spaces
    while ((c = getch()) == ' ');

    //get op
    if (!isdigit(c))
        return c;

    //get digit number
    int i = 0;
    string[i++] = c;

    while (isdigit(c = string[i++] = getch()));
    if(c == '.'){
        while(isdigit(c = string[i++] = getch()));
    }
    string[i] = '\0';
    ungetch(c);
    return NUMBER;
}