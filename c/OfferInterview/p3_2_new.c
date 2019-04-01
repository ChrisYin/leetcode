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
 * Using binary search method:
 *
 * while(start < end){
 *      val = countrange(start, middle);
 *      compare(val , middle - start + 1)
 *      if(>) newloop
 *
 *      countrange(middle+1, end);
 *      compare(val, end - middle)
 *      if(>) newloop
 *
 *      no repearted num;
 *
 * }
 */

#include <stdio.h>

/*
 * return occurence of the number in the from start to end;
 * return -1 if error happens;
 */
int countRange(int s[], int length, int start, int end){
    if(s == NULL || length <= 0)
        return -1;

    int count = 0;
    for(int i = 0; i < length; i++){
        if(s[i] >= start && s[i] <= end){
            count++;
        }
    }
    return count;
}
/*
 * return repeated number.
 * return 0 if no repeated number
 * return -1 if error happens;
 */
int searchNum(const int *s, int length){
    if(s == NULL || length <= 0)
        return -1;

    for(int i = 0; i < length; i++){
        if(s[i] < 1 || s[i] > length-1)
            return -1;
    }

    int start = 1;
    int end = length-1;
    int middle;
    while(start <= end){

        if(start == end){
            if(countRange(s, length, start, start) > 1){
                return start;
            }else{
                return 0;
            }
        }

        middle = (start + end)/2;
        if(countRange(s, length, start, middle) > (middle-start+1)){
            end = middle;
            continue;
        }
        if(countRange(s, length, middle+1, end) > (end-middle)){
            start = middle+1;
            continue;
        }
        break;
    }

    return 0;
}



/*
 * testcases:
 *
 * length: 6
 *
 * 1 1 1 1 1 1
 * 5 5 5 5 5 5
 * 1 2 3 4 5 5
 * 1 2 3 4 5 1
 * 1 2 1 4 5 1
 *
 */
int main(){
    int s[]={1, 2, 1, 4, 5, 1};
    int length = 6;
    //searchNum(s, length);
    printf("%d\n", searchNum(s, length));
}