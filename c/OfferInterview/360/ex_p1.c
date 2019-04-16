//
// Created by zhenguo on 19-4-16.
//

/*
 * Description:
 *
 * 马贼分金子:
 *
 * dp[i][j]: 表示先手在i段到j段可以获得的最大收益
 * 状态转移方程: dp[i][j] = sum[i,j]-min{dp[i+1][j], dp[i][j-1]}
 * 准备获取dp数值
 *
 * dp[i][i]为本身
 *
 * 计算顺序:
 * dp[i][i]
 * dp[i-1][i] dp[i-2][i]
 */
#include <stdio.h>
#include <memory.h>


/*
 * interface:
 *
 */
#define MIN(x, y) ((x) < (y) ? (x) : (y))
typedef struct {
    int goldA;
    int goldB;
} pair;

pair getGold(int *gold, int N){
    int dp[N+1][N+1];
    int sum[N+1];
    pair res;

    memset(dp,0, sizeof(int)*(N+1)*(N+1));
    memset(sum,0, sizeof(int)*(N+1));

    //only one element
    for(int i = 1; i <= N; i++){
        dp[i][i] = gold[i];
    }

    sum[0] = 0;
    sum[1] = gold[1];

    for(int i = 2; i <= N; i++){
        sum[i] = sum[i-1] + gold[i];
        for(int j = i-1; j >= 1; j--){
            dp[j][i] = sum[i] - sum[j-1] - MIN(dp[j+1][i], dp[j][i-1]);
            //printf("dp[%d][%d]:%d\n", j, i, dp[j][i]);
        }
    }

    res.goldA = dp[1][N];
    res.goldB = sum[N]-dp[1][N];

    return res;
}

int solution(){
    int testCases;
    scanf("%d", &testCases);
    while(--testCases>=0){
        int N;
        scanf("%d", &N);
        int gold[N+1];
        for(int i= 1; i <= N; i++){
            scanf("%d",&gold[i]);
        }
        getGold(gold, N);
        /*
        for(int i = 1; i <= N; i++){
            printf("%d ", gold[i]);
        }
        printf("\n");
         */
    }
}

int test1(){
    int N = 6;
    int gold[7]= {0,4,7,2,9,5,2};
    pair res = getGold(gold,N);
    printf("%d %d\n", res.goldA, res.goldB);
}

int test2(){
    int N = 10;
    int gold[11]= {0,140,649,340,982,105,86,56,610,340,879};
    pair res = getGold(gold,N);
    printf("%d %d\n", res.goldA, res.goldB);
}
int main(){
    test2();
    return 0;
}