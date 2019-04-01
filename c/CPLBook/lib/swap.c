//
// Created by zhenguo on 19-4-1.
//

#include "cpllib.h"

void swap(char *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

