//
// Created by zhenguo on 19-3-31.
//


/*
 * Description:
 * 面试题3（一）：找出数组中重复的数字
 * 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
 * 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
 * 那么对应的输出是重复的数字2或者3。
 */

/*
 * 思路:
 * 使用Hashtable
 *
 * 1. 创建Hashtable
 * 2. 遍历输入数组, 每一个输入值对应hashtable一个key, val++
 * 3. if val > 1, break
 */

/*
 * interface:
 *
 * bool duplicate(int s[], int length, int *dupNum);
 *
 * s: input array
 * length: array length
 * dupNum: duplicate number pointer
 *
 * return:
 * if repeated number exists, return true
 * else return false;
 */

/*
 * testcases:
 * length: 4
 * 1. 3 3 3 3
 * 2. 0 0 0 0
 * 3.  0 1 2 3
 * 4. null array
 */

#include <stdio.h>
#include <stdbool.h>

bool duplicate(int s[], int length, int *dupNum){
    if(s == NULL){
        printf("error input array\n");
        return false;
    }


    int hashtable[length];
    for(int i = 0; i < length; i++){
        hashtable[i] = 0;
    }

    for(int i = 0; i < length; i++){
        if(++hashtable[s[i]] > 1){
            *dupNum = s[i];
            return true;
        }
    }

    return false;
}


int main(){
    int test1 = NULL;
    int dupNum;

    if(duplicate(test1, 4, &dupNum)){
        printf("duplicate num: %d\n", dupNum);
    }else{
        printf("no duplicate num\n");
    }

    return 0;
}