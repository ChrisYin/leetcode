//
// Created by zhenguo on 19-4-23.
//

/*
 * Description:
 *
 * Rope length: n (n>1)
 * cut it into m pieces (m>1)
 * Max(mulitplexing of each small pieces)
 *
 *
 */

/*
 * Thinking:
 *
 * Dynamic Programming:
 *
 * 1. 最优解
 * 2. 划分成多个子问题
 * 3. 寻找子问题的最优解 还能够重复利用
 *
 */
#include <stdio.h>
#include <memory.h>
/*
 * n: rope length
 * m: number of pieces
 * return the max muliplexing result
 * return -1 if it is impossible to cut
 * Assumption: n>1
 */

int maxMultiplexCut(int n){
    int res[n+1];
    int cnt;
    int tmp;

    memset(res, 0, sizeof(int)*(n+1));
    cnt = 4;

    res[1] = 1;
    res[2] = 2;
    res[3] = 3;

    if(n == 2)
        return 1;
    if(n == 3)
        return 2;

    while(cnt <= n){
        tmp = 0;
        for(int i = 2; i <= cnt/2; i++){
            if(res[i]*res[cnt-i] > tmp)
                tmp = res[i]*res[cnt-i];
        }
        //printf("[%d]: %d\n", cnt, tmp);
        res[cnt]= tmp;
        cnt++;
    }

    return res[n];

}

//n=8
void test1(){
    int n = 20;
    int res = maxMultiplexCut(n);
    printf("[%d]: %d\n", n,res);
}

void test2(){
    int n = 2;
    int res = maxMultiplexCut(n);
    printf("[%d]: %d\n", n,res);
}

void test3(){
    int n = 3;
    int res = maxMultiplexCut(n);
    printf("[%d]: %d\n", n,res);
}

void test4(){
    int n = 4;
    int res = maxMultiplexCut(n);
    printf("[%d]: %d\n", n,res);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    return 0;
}