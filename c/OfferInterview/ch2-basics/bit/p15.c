//
// Created by zhenguo on 19-4-25.
//
#include <stdio.h>

/*
 * Description:
 *
 * Find the occurence of 1 in the binary format of an integer.
 *
 */

/*
 * 假设数字大小： int 类型
 * 每次右移一位 和 0b1 做 & 运算
 *
 * */

/*
 * learning:
 *
 * 负数的右移会补位1！！！！！
 */


/*
 * Assumption:
 * n is in type int(4 bytes/32 bit)
 *
 *
 * return the occurence of number 1
 * return -1 if meets error
 */
int calOne(int n){
    int res;
    unsigned int test;

    res = 0;
    test = 0b1;

    while(test){
        if(n & test)
            res++;
        test = test << 1;
    }

    return res;
}


void test(int num){
    printf("[%d]:%d\n",num, calOne(num));
}

int main(){
    test(0xf0000003);
    return 0;
}