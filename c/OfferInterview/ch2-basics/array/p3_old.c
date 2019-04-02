#include <stdio.h>

/*
 * Description:
 *
 * find the repeated number in a N-length array
 *
 * range of number: 0 ~ n-1
 *
 * Thinking:
 *
 * Hashtable -> array
 *
 *
 * 1. Initialize N length array(hashtable) as a hashtable
 *
 * 2. loop the input array to hashtable
 *
 * 3. if value > 2, print this number
 *
 * 4. if no repeated number, return -1
 *
 *
 * Testcase:
 * InputArray:
 * 4 {0 0 0 0}
 * 4 {1 2 3 4}
 *
 *
 *
 */

int main() {
    int length;
    scanf("%d", &length);
    //printf("%d\n", length);

    int inputArray[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &inputArray[i]);
    }
    //test input array
    /*for (int i = 0; i < length; i++) {
        printf("%d ", inputArray[i]);
    }*/

    int hashtable[length];
    for(int i = 0; i < length; i++){
        if(++hashtable[inputArray[i]] > 1){
            printf("repeated num: %d\n", inputArray[i]);
            return 0;
        }
    }

    printf("no repeated num\n");
    return 0;
}