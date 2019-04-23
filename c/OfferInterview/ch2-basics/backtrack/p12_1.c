//
// Created by zhenguo on 19-4-22.
//

/*
 * Description:
 * 矩阵中的路径:寻找矩阵中是否存在一条包含某字符串所有字符的路径.
 */

/*
 * Thinking:
 *
 * 使用回溯法.
 *
 * 1. 寻找第一个字符
 *
 * 2. 搜索下一个字符:　终止条件 最后一个字符 相等  就是寻找到了
 *
 *
 */
#include <stdio.h>


int compareCharacter(char ch, char (*matrix)[4], int row, int col, int height, int width){
    if(row < 0 || row >= height || col < 0 || col >= width)
        return 0;
    if(matrix[row][col] == ch)
        return 1;
    return 0;
}

//order: top down left right
/*
 * return 0 if not find
 * return 1 if find
 */
int find(char *str, int length, char (*matrix)[4], int height, int width, int chPos, int mRow, int mCol, int (*boolChar)[4]){
    if(mRow < 0 || mRow >= height || mCol < 0 || mCol >= width || chPos >= length){
        return 0;
    }

    if(chPos == length - 1){
        return 1;
    }

    char nextCh = str[++chPos];
    int row, col;


    row = mRow - 1;
    col = mCol;
    if(boolChar[row][col] == 0 && compareCharacter(nextCh, matrix, row, col, height, width)){
        boolChar[row][col] = 1;
        if(find(str, length, matrix, height, width, chPos, row, col, boolChar)){
            return 1;
        }
        boolChar[row][col] = 0;
    }

    row = mRow + 1;
    col = mCol;
    if(boolChar[row][col] == 0 && compareCharacter(nextCh, matrix, row, col, height, width)){
        boolChar[row][col] = 1;
        if(find(str, length, matrix, height, width, chPos, row, col, boolChar)){
            return 1;
        }
        boolChar[row][col] = 0;
    }

    row = mRow;
    col = mCol - 1;
    if(boolChar[row][col] == 0 && compareCharacter(nextCh, matrix, row, col, height, width)){
        boolChar[row][col] = 1;
        if(find(str, length, matrix, height, width, chPos, row, col, boolChar)){
            return 1;
        }
        boolChar[row][col] = 0;
    }

    row = mRow;
    col = mCol + 1;
    if(boolChar[row][col] == 0 && compareCharacter(nextCh, matrix, row, col, height, width)){
        boolChar[row][col] = 1;
        if(find(str, length, matrix, height, width, chPos, row, col, boolChar)){
            return 1;
        }
        boolChar[row][col] = 0;
    }

    return 0;
}

/*
 * return 0 if not find.
 * return 1 if find.
 * return -1 if error
 */
int findString(char *str, int length, char (*matrix)[4], int height, int width){
    if(str == NULL || length <= 0 || matrix == NULL || width <= 0 || height <= 0){
        fprintf(stderr, "input args invalid\n");
        return -1;
    }

    int boolChar[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            boolChar[i][j] = 0;
        }
    }

    //find first character
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(matrix[i][j] == str[0]){
                boolChar[i][j] = 1;
                if(find(str, length, matrix, height, width, 0, i, j, boolChar)){
                    for(int k = 0; k < height; k++){
                        for(int l = 0; l < width; l++){
                            if(boolChar[k][l] == 1){
                                printf("[%d,%d] ", k, l);
                                printf("\n");
                            }
                        }
                    }
                    return 1;
                }
                boolChar[i][j] = 0;
            }
        }
    }
    return 0;

}


void test1(){
    int width = 4;
    int height = 3;
    char matrix[3][4] = {
            {'a','b','t','g'},
            {'c','f','c','s'},
            {'j','d','e','h'}
    };
    int length = 4;
    char str[4]= {'d','f','c','t'};
    printf("%s",(findString(str, length, matrix, height, width)==1)?"Yes":"No");
}

void test2(){
    int width = 4;
    int height = 3;
    char matrix[3][4] = {
            {'a','a','a','a'},
            {'a','a','a','a'},
            {'a','a','a','a'}
    };
    int length = 4;
    char str[4]= {'a','a','a','a'};
    printf("%s",(findString(str, length, matrix, height, width)==1)?"Yes":"No");
}

int main(){
    test2();
    return 0;
}
