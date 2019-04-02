//
// Created by zhenguo on 19-4-1.
//

/*
 * description: replace each space of the input string with "%20"
 *
 * Lessons Learned:
 *
 * 1. How to modify the pointer as a function's paramter
 *    Use *pp*: the ponter of the pointer
 *
 * 2. *p[N] and (*p)[N]
 *    Array of pointer
 *    Pointer of array(Pointer of Pointer)
 *
 */

#include <stdlib.h>
#include <stdio.h>

/*
 * Thinking: We need more efficient algorithm from the perspective of space and time.
 *
 * loop each character to find space
 *
 * then replace the space
 *
 * More attention needs to be paid in length of the output string.
 *
 */


int replaceSpace(char **s, int maxLength){
    int inputIndex = 0;
    int outputIndex = 0;
    char *outputString = malloc(sizeof(char)*maxLength);

    while((*s)[inputIndex] != '\0' && inputIndex < maxLength && outputIndex < maxLength){
        if((*s)[inputIndex] == ' '){
            outputString[outputIndex++] = '%';
            outputString[outputIndex++] = '2';
            outputString[outputIndex++] = '0';
        }else{
            outputString[outputIndex++] = (*s)[inputIndex];
        }
        inputIndex++;
    }
    outputString[outputIndex] = '\0';
    *s = outputString;

    return 0;
}

/*
 * testcase
 *
 * "we we we "
 *
 * nullpointer
 *
 * "   "
 */
int main(){
    char *s = "we are happy\n";
    //char *test = s;
    replaceSpace(&s, 100);
    printf("%s\n", s);
    return 0;
}