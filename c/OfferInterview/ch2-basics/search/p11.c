//
// Created by zhenguo on 19-4-19.
//

/*
 * Description:
 *
 * Spin Array:
 *
 * Find the minimum element of a spin array.
 *
 */

/*
 * Thinking[必须明确思路!!!]:
 *
 * Using binary search.
 *
 * 1. (left < right): elements are equal.
 *
 * 2. choose the middle element:
 *
 *          if A[mid] < A[left], right = mid;
 *          if A[mid] > A[right], left = mid;
 *
 *
 */

/*
 * New Thinking:
 *
 * stop condition: left < right - 1
 * 0. left == right == mid: 顺序查找
 * 1. A[mid] >= A[left], left = mid;
 * 2. A[mid] >= A[right], right = mid;
 *
 */
#include <stdio.h>

int findSpinArray_OLD(int *A, int length, int *res){
    if(A == NULL || length <= 0 || res == NULL)
        return -1;

    int left, center, right;

    left = 0;
    right = length-1;

    //equal element arrray
    if(A[left] == A[right]){
        *res = A[left];
        return 0;
    }


    while(left < right-1){
        center = (left+right)/2;
        if(A[center] < A[left]){
            printf("[%d %d] -> [%d %d]\n", left, right, left, center);
            right = center;
            continue;
        }
        if(A[center] > A[right]){
            printf("[%d %d] -> [%d %d]\n", left, right, center, right);
            left = center;
            continue;
        }
        fprintf(stderr, "error!\n");
        break;
    }
    printf("finished\n");
    *res = (A[left] < A[right])?A[left]:A[right];
    return 0;
}

int findSpinArray(int *A, int length, int *res){
    if(A == NULL || res == NULL || length <= 0){
        return -1;
    }

    int left, mid, right;

    left = 0;
    right = length -1;

    while(left < right - 1){
        mid = (left + right)/2;
        if(A[left] == A[right] && A[left] == A[mid])
            return -1;
        if(A[mid] >= A[left]){
            left = mid;
            continue;
        }
        if(A[mid] <= A[right]){
            right = mid;
            continue;
        }
    }
    *res = A[right];
    return 0;
}


void test1(){
    int length = 5;
    int A[] = {3,4,5,1,2};
    int res;
    findSpinArray(A, length, &res);
    printf("min element is: %d\n", res);
}

int main(){
    test1();
    return 0;
}