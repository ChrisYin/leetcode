//
// Created by zhenguo on 19-3-26.
//

#include <stdio.h>

#define MAXLINE 100
#define TAPSTOP 8


int detab(char inputArray[], char outputArray[], int length);
int getlineN(char s[], int len);


int main(){
    char inputArray[MAXLINE];
    char outputArray[MAXLINE];
    size_t newSize;

    while((newSize = getlineN(inputArray, MAXLINE)) != 0){
        detab(inputArray, outputArray, newSize);
        printf("%s\n", inputArray);
        printf("%s\n", outputArray);
    }
}

/*
 * return the size of this new line
 */
int getlineN(char s[], int len){

    int c;
    int count = 0;
    /*
     * boundary condition:
     * 1. c == EOF
     * 2. count = len - 1
     *
     **/
    while(count < len-1){
        if((c = getchar()) != EOF && c != '\n'){
            s[count] = c;
            ++count;
        }
        else{
            s[count] = '\0';
            ++count;
            break;
        }
    }
    return count;
}

/*
 * replace tab with strings of blanks
 * return outputArray length
 */
int detab(char inputArray[], char outputArray[], int length){
    int outputLength = 0;
    int blanks;

    for(int i = 0; i < length; ++i){
        if(inputArray[i] == '\t'){
            blanks = TAPSTOP-outputLength%TAPSTOP;
            for(int j = 0; j < blanks; j++){
                outputArray[outputLength++] = ' ';
            }
        }else{
            outputArray[outputLength] = inputArray[i];
            ++outputLength;
        }
    }
    return outputLength;
}