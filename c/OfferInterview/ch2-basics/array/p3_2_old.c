//
// Created by zhenguo on 19-3-31.
//

/*
 * Description:
 *
 * Find the duplicate number in an array of length N+1.
 *
 * The range of the interger array is from 1 to N, which means only one number is repeated.
 *
 * Don't change the original number.
 *
 */

/*
 * Thinking:
 *
 * Using Hashtable.
 *
 * 1. Initialize hashtable: loop input array.
 *
 * 2. if val > 1, return the number.
 *    else return -1;
 */


/*
 * Interface:
 *
 * int duplicate(int s[], int length);
 *
 * s: input arrau
 * length: length of array
 *
 * return:
 * -1: no repeated number
 * 1-N: repeated number()
 */


/*
 * testcase:
 *
 * length: 6
 * number: 1 - 5
 *
 * 1. null array
 *
 * 2. 1 2 3 4 5 1
 *
 * 3. 4 1 2 3 5 4
 *
 * 4. 1 1 1 1 1 1
 *
 * 5. 4 4 4 4 4 4
 *
 */

#include <stdio.h>


int duplicate(int s[], int length){
    if(s == NULL || length <= 0)
        return -2;

    int hashtable[length];

    for(int i = 0; i < length; i++){
        //printf("%d", s[i]);
        if(++hashtable[s[i]]>1){
            return s[i];
        }
    }

    return -1;
}

int main(){
    int testArray[] = {4, 1, 2, 3, 5, 4};
    int length = 6;
    printf("%d\n", duplicate(testArray, length));
    return 0;
}