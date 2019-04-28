//
// Created by zhenguo on 19-4-28.
//


/*
 * Description:
 *
 * double power ( double base, int exponent)
 */


/*
 * 利用乘法
 *
 * 考虑情况：
 *
 * exponent： 正数 负数  0
 *
 * 1. 正数： 正常情况
 *
 * 2. 负数： 正常情况  取倒数
 *
 * 3. 结果为1
 *
 *
 *
 */

/*
 * Learning:
 *
 * 每一次除法都必须检查除数是否有可能为0
 */
#include <stdio.h>
#include <limits.h>

double powder(double base, int exponent){
    if(exponent == 0)
        return 1.0;
    if(base == 0 && exponent < 0){
        fprintf(stderr, "invalid input!\n");
        return 0.0;
    }


    double res;
    int negative;

    negative = 0;
    if(exponent < 0){
        negative = 1;
        exponent = -exponent;
    }

    res = 1.0;
    while(exponent-->0){
        res *= base;
    }

    if(negative)
        res = 1.0/res;

    return res;
}


void test(double base, int exp){
    printf("[%f]^[%d] = %f\n",base, exp, powder(base,exp));
}


int main(){
    //normal test
    test(10.0,2);
    //boundary test
    test(0,0);
    test(0,-1);
    test(0.5,INT_MAX);
    test(0.5,INT_MIN);
    //negative test
    //test()
    return 0;
}

