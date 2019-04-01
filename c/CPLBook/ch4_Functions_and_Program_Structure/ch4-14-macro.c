//
// Created by zhenguo on 19-3-30.
//

#include <stdio.h>


#define swap(t,x,y) {t temp;\
temp = x;\
x = y;\
y = temp;\
}\

int main(){
    int x = 4, y = 5;
    printf("old:%d %d\n", x , y);
    swap(int, x, y);
    printf("new:%d %d\n", x , y);
    return 0;
}
