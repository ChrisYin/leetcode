//
// Created by zhenguo on 19-4-11.
//


#include <stdint.h>
#include <stdio.h>

/*
 * Description:
 *
 * Several solution to calculate fibnonacci number,
 *
 */

/*
 * recursion method
 */
uint64_t fibonacciOrigin(uint32_t order){
    if(order <= 0)
        return 0;
    if(order == 1)
        return 1;
    if(order == 2)
        return 1;
    return fibonacciOrigin(order-1) + fibonacciOrigin(order-2);
}

uint64_t fibonacciImprove(uint32_t order){
    if(order <= 0)
        return 0;
    if(order == 1)
        return 1;
    if(order == 2)
        return 1;

    uint64_t old1 = 1;
    uint64_t old2 = 1;
    uint64_t cur = 0;
    for(int i= 3; i <= order; i++){
        //overflow
        if(old2 > UINT64_MAX - old1){
            printf("overflow!\n");
            cur = 0;
            break;
        }
        cur = old1 + old2;
        old1 = old2;
        old2 = cur;
    }
    return cur;
}
/*
 * testcases:
 *
 * 1. (0, 0)
 *
 * 2. (1, 1)
 *
 * 3. (2, 1)
 *
 * 4. (14, 377)
 *
 * 5. (50, 12586269025)
 *
 * 6. (100, overflow)
 *
 */
int main(){
    printf("%ld\n", fibonacciImprove(50));
    return 0;
}
