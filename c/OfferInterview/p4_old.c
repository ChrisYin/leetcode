//
// Created by zhenguo on 19-3-31.
//

/* Description:
 * two dimensional matrix:
 * row: small to large
 * coloum: small to large
 * You need to find the assigned number
 */

/*
 * Thinking:
 *
 * 1. find the smallest matrix: [n-1   n]
 *
 *     1. find the rightest element
 *
 *       1.1 find through diagonal line
 *
 *       1.2 find through rows
 *
 *       1.3 find through cololums
 *
 *     2. find the leftest element
 *
 *       the same as part 1
 *
 * 2. find the number through four elements
 *
 *     find the number
 */
#include <stdio.h>
#include <stdbool.h>

/*
 *  return false if no such number and meets error
 *  return true if the number exits.
 */
bool findNum(int *s, int height, int width, int num){
    if(s == NULL || height <= 0 || width <= 0)
        return false;

    int right_r, right_c;
    int left_r, left_c;

    //find the rightest element
    right_c = 0;
    right_r = 0;
    while(s[width * right_r + right_c] < num){
        if(right_r >= height-1 && right_c >= width-1)
            return false;
        if(right_r < height-1)
            right_r++;
        if(right_c < width-1)
            right_c++;
    }
    //printf("right: %d %d\n", right_r, right_c);

    //find the leftest element
    left_c = (right_c-1 < 0) ? right_r:(right_c-1);
    left_r = (right_r-1 < 0) ? right_r:(right_r-1);
    while(s[width*left_r+left_c] > num){
        if(left_r <= 0 && left_c <= 0)
            break;
        if(left_r > 0)
            left_r--;
        if(left_c > 0)
            left_c--;
    }
    //printf("left: %d %d\n", left_r, left_c);

    //find the number in the minial matrix
    for(int r = left_r; r <= right_r; r++){
        for(int c = left_c; c <= right_c; c++){
            //printf("%d ", s[r][c]);
            if(s[r*width+c] == num)
                return true;
        }
        //printf("\n");
    }



    return false;
}


/*
 * testcase
 *
 * 1. null pointer of array
 *
 * 2.
 */

int main(){
    int inputMatrix[5][5] = {
            {1, 2, 3, 4, 5},
            {2, 4, 5, 6, 7},
            {3, 5, 6, 7, 8},
            {4, 6, 7, 8, 19},
            {5, 7, 8, 18, 20},
    };
    int num = 4;
    if(findNum(inputMatrix, 5, 5, num)){
        printf("find the number\n");
    }else{
        printf("the number doesn't exit\n");
    }
    return 0;
}