//
// Created by zhenguo on 19-4-24.
//

/*
 * Greedy Algorihm For P14:
 *
 * Cutting Rope:
 *
 * Length:N
 */

/*
 * Thinking:
 *
 * 1. n < 2: return 0
 * 2. n = 2: return 1
 * 3. n = 3: return 2
 * 4. n = 4: return 4
 * 5. n > 5: Cutting the rope with length 3 as many as possible.
 */

/*
 * Learning:
 *
 * 使用循环来计算剪成3段的次数过于慢
 * 应该之间而使用除法计算！
 */

#include <stdio.h>
#include <stdlib.h>


int cutRope(int n){
    if(n < 2)
        return 0;
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    if(n == 4)
        return 4;

    int res;

    res = 1;
    while(n > 4){
        res *= 3;
        n -= 3;
    }
    res *= n;
    return res;
}

void test(int n){
    printf("[%d]: %d\n", n, cutRope(n));
}
int main(){
    for(int i = 0; i < 10; i++){
        test(i);
    }
    return 0;
}