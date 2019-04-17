//
// Created by zhenguo on 19-4-16.
//

/*
 * 时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给出一个有n(0 < n <= 10000)个整数的数组A（-10000 <= Ai <=10000) ， 请问是否可以至多修改一个元素， 使这个数组成为非递减数组。
 *
 */

/*
 * Thinking:
 * 1. 首先遍历数组, 寻找第一个inversion
 * 2. A[i-1]>A[i]
 *    Let these two elements has equal value
 *    + A[i+1] > A[i-1] || i+1 > size : A[i] = A[i-1]
 *    + A[i-2] < A[i] || i-2 < 0: A[i-1] = A[i]
 *    + cnt++>1: false
 * */

#include <memory.h>
#include <stdio.h>


//interface:
int checkArray(int *nums, int len);
int solution();
int test1();

int array[10005];
int solution(){
    int len = 0;
    char c;
    while(scanf("%d%c", &array[len++], &c)){
        if(c == '\n'){
            printf("length: %d\n", len);
            for(int i = 0; i < len; i++){
                printf("%d%c", array[i], (i==len-1)?'\n':' ');
            }
            len = 0;
        }
    }
}

int main() {
    test1();
    return 0;
}

int test1(){
    int len = 3;
    int array[3] = {4,2,1};
    printf("%s\n", (checkArray(array, len)==0)?"Pass":"Fail");
}
int checkArray(int *nums, int len) {
    if(nums == NULL || len <= 0)
        return -1;
    int cnt = 0;

    for(int i = 1; i < len; i++){
        if(nums[i-1] > nums[i]){
            if(++cnt>1)
                return -1;
            if(i+1 >= len || nums[i-1] < nums[i+1]){
                nums[i] = nums[i-1];
            }else if(i-2<0 || nums[i-2] < nums[i]){
                nums[i-1] = nums[i];
            }else{
                return -1;
            }
        }
    }
    return 0;
}