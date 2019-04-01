//
// Created by zhenguo on 19-4-1.
//

/*
 * Description: replace each space of the input string with "%20"
 *
 * Use space-efficient algorithm(do not use extra space to store output string)
 *
 * Lesson Learned:
 *
 * You need to decide the maximum length of the output string.
 * So that when initialize the input string, you can give it efficient space!!
 */


/*
 * Thinking:
 *
 * 1. Find the number of spaces to dicide the length of output string.
 *
 * 2. Replace the space from the back of the input string.
 *
 */
#include <stdio.h>

int replaceSpace(char *s){
    if(s == NULL)
        return -1;
   //find the length of the old string and new string
   int oldLength = 0;
   int newLength = 0;

   while(s[oldLength]!='\0'){
       if(s[oldLength] == ' ')
           newLength+=2;
       oldLength++;
       newLength++;
   }
   //lastindex + 1 = length
   oldLength++;
   newLength++;
   printf("%d %d\n", oldLength, newLength);

   for(int i = oldLength-1, j = newLength-1; i >= 0 && j >= 0; i--){
       if(s[i] == ' '){
           s[j--] = '0';
           s[j--] = '2';
           s[j--] = '%';
       }else{
           s[j--] = s[i];
       }
   }

    return 0;
}

/*
 * testcase:
 *
 * 1    null pointer
 * 2    " we are happy. "
 * 3    "          "
 */

int main(){
    char s[100] = "  ";
    replaceSpace(s);
    printf("%s\n", s);
    return 0;
}