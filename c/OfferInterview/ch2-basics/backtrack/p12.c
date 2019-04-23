//
// Created by zhenguo on 19-4-22.
//
/*
 * Description:
 *
 * find a path in a character matrix which contains all the characters of a string.
 *
 */
#include <stdio.h>
#include <memory.h>
/*
 * Learning:
 *
 *   传递二维数组变量到函数:
 *          1. 一维指针: A[row*width+col]
 *          2. 数组指针  (*A)[width]
 *
 *   还是不够明确的写出编程的思想, 把流程写具体化
 */
/*
 * Thinking:
 *
 * Backtracking method.
 *
 * 1. find the first character.
 *
 * 2.
 *      top:  if(Ch[top] == str[i] && top is good && i is good && Ch[top] is new) else break;
 *      down:
 *      left:
 *      right:
 *
 * 3.
 *
 *
 * Testcases:
 *
 *      null pointer
 *      find one character
 *      find the string with same multiple characters
 *      find normal character
 *
 */


int compareCharacter(char ch, char (*matrix)[4], int row, int col, int height, int width){
    if(row >= height && col >= width){
        printf("matrix overflow return 0\n");
        return 0;
    }

    if(matrix[row][col] == ch){
        printf("get right character: %c in [%d][%d]\n", ch, row, col);
        return 1;
    }

    return 0;
}


int findNextCharacter(const char *str, int curCh, int length, char (*matrix)[4], int row, int col, int height, int width){
    if(curCh >= length || row >= height || col >= width)
        return 0;

    if(curCh == length - 1)
        return 1;

    printf("find character: %c in [%d][%d]\n", str[curCh], row, col);
    char ch = str[curCh+1];
    if(compareCharacter(ch, matrix, row-1, col, height, width))
        if(findNextCharacter(str, curCh+1, length, matrix, row-1, col, height, width))
            return 1;
    if(compareCharacter(ch, matrix, row+1, col, height, width))
        if(findNextCharacter(str, curCh+1, length, matrix, row+1, col, height, width))
            return 1;
    if(compareCharacter(ch, matrix, row, col-1, height, width))
        if(findNextCharacter(str, curCh+1, length, matrix, row, col-1, height, width))
            return 1;
    if(compareCharacter(ch, matrix, row, col+1, height, width))
        if(findNextCharacter(str, curCh+1, length, matrix, row, col+1, height, width))
            return 1;
}

/*
 * return 1 if find
 * return 0 if not find
 * return -1 if error
 */
int findString(const char *str, int length, char (*matrix)[4], int height, int width){
    if(str == NULL || matrix == NULL || length <= 0 || height <= 0 || width <= 0)
        return -1;

    //find the first character of the string
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            //printf("%c\n", matrix[i][j]);
            if(matrix[i][j] == str[0])
                return findNextCharacter(str, 0, length, matrix, i, j, height, width);
        }
    }
    return 0;
}



int test1(){
    int height = 3;
    int width = 4;
    char A[3][4] = {{'a','b','t','g'},
                   {'c','f','c','s'},
                   {'j','d','e','h'}};
    char str[]="bfce";
    printf("%s\n", (findString(str, (int)strlen(str), A, height, width)==1)?"find!":"Not find!");
}

int test2(){
    int height = 3;
    int width = 4;
    char A[3][4] = {{'a','a','a','a'},
                    {'a','a','a','a'},
                    {'a','a','a','a'}};
    char str[]="aaaa";
    printf("%s\n", (findString(str, (int)strlen(str), A, height, width)==1)?"find!":"Not find!");
}
int main(){
    test2();
    return 0;
}