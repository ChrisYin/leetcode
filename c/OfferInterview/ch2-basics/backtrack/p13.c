//
// Created by zhenguo on 19-4-23.
//

/*
 * Description:
 * m*n 矩阵   从(0,0) 开始移动
 * 机器人不能进入行座标和列座标的数位之和大于k的格子
 * 请问机器人能够到达多少格子
 */

/*
 * Thinking:
 *
 * 回溯法
 *
 * visited[m][n]: whether robot can visit or not
 *
 * function calDigit: cal sum of each digit
 *
 * function:
 *
 */

#include <stdio.h>
#include <memory.h>
/*
 * return the digit sum of the number
 * Assumption: num >= 0
 */
int calDigit(int num){
    int digit;
    int res;

    res = 0;
    while((digit = num % 10)){
        res += digit;
        num /= 10;
    }
    return res;
}

/*
 * return 0 if it cannot visit.
 */
int visitMatrx(int *matrix, int row, int col, int height, int width, int k){
    //boundary
    if(row < 0 || row >= height || col < 0 || col >= width){
        return 0;
    }

    //visited before
    if(matrix[row*width+col]){
        return 1;
    }

    //condition
    if(calDigit(row)+calDigit(col) > k){
        //printf("digit sum: %d\n", calDigit(row)+calDigit(col));
        return 0;
    }
    printf("%d %d\n", row, col);
    matrix[row*width+col] = 1;

    visitMatrx(matrix, row+1, col, height, width, k);
    visitMatrx(matrix, row-1, col, height, width, k);
    visitMatrx(matrix, row, col+1, height, width, k);
    visitMatrx(matrix, row, col-1, height, width, k);
    return 1;
}

/*
 * return -1 if error
 * return the number of visited position
 */
int calVisitedPos(int m, int n, int k){
    if(m <= 0 || n <= 0){
        return -1;
    }

    int cnt;
    int visitMatrix[m][n];

    cnt = 0;
    memset(visitMatrix, 0, sizeof(int)*m*n);

    visitMatrx((int *)visitMatrix, 0, 0, m, n, k);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(visitMatrix[i][j] == 1)
                cnt++;
        }
    }

    return cnt;

}


/*
 * testcases
 */
//normal
void test1(){
    int m = 3;
    int n = 3;
    int k = 2;
    printf("[%d,%d]: %d\n", m,n,calVisitedPos(m,n,k));
}

//k = 0
void test2(){
    int m = 3;
    int n = 3;
    int k = 0;
    printf("[%d,%d]: %d\n", m,n,calVisitedPos(m,n,k));
}

//k = 4
void test3(){
    int m = 3;
    int n = 3;
    int k = 4;
    printf("[%d,%d]: %d\n", m,n,calVisitedPos(m,n,k));
}

void test4(){
    int m = 3;
    int n = 3;
    int k = 3;
    printf("[%d,%d]: %d\n", m,n,calVisitedPos(m,n,k));
}

int main(){
    test4();
    return 0;
}