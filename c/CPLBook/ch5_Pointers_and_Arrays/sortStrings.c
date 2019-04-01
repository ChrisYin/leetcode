//
// Created by zhenguo on 19-4-1.
//

#include <stdio.h>
#include "lib/cpllib.h"
#include <string.h>

/*
 * Decription:
 * sort strings by their length
 */

/*
 * Thinking:
 *
 * Using array of pointers to store the pointer of each string, then use quick sort to sort them.
 *
 */


#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

/*
 * *lineptr[]: array of pointers
 * nlines: maxlines
 * return 0 if fine
 * return -1 when too much input
 */
int readline(char *lineptr[], int nlines);

/*
 * *lineptr[]: array of pointers
 * nlines: the length of the array
 * return void
 */
void writelines(char *lineptr[], int nlines);

/*
 * *lineprt[]: array of string pointers
 * left: start index
 * right: end index
 * return void
 */
/*
 * Think about quicksort
 *
 * 1. recursion end condition
 *      left >= right
 *
 * 2. partition the array
 *
 *    2.1 choose rightest element as the pivot element;
 *
 *    2.2 find the element which greater or equal than the pivot element from the left(don't need sentinel)
 *
 *    2.3 find the element which less or equal than the pivot element form the right(need a sentinel to test length)
 *
 *    2.4 if(i >= j) break;
 *        else swap(i, j)
 *
 *    2.5 swap pivot element with i element
 *
 * 3. quicksort recursion
 *
 */
void qsort(char *lineptr[], int left, int right){

    if(left >= right)
        return;

    char *pivot = lineptr[right];

    int i = left - 1;
    int j = right;

    while(1){
        while(strcmp(lineptr[++i], pivot) < 0)
            ;
        while(strcmp(lineptr[--j], pivot) > 0){
            if(j <= left)
                break;
        }
        if(j <= i)
            break;
        swap(lineptr, i, j);
    }
    swap(lineptr, i, right);
    qsort(lineptr, left, i-1);
    qsort(lineptr, i+1, right);
}

int main() {
    int nlines;
    if((nlines = readline(lineptr, MAXLINES)) <= 0){
        printf("readline error\n");
        return -1;
    }
    //printf("sorted strings: %d %d \n", 0, nlines-1);
    qsort(lineptr, 0, nlines-1);
    //swap(lineptr, 0, 1);
    writelines(lineptr, nlines);
}

int readline(char *lineptr[], int nlines){
    if(lineptr == NULL || nlines <= 0)
        return 0;

    int i;
    char *string;
    /*
     * Considering the condition: using getline() > 0 is better.
     */
    for(i = 0; i < nlines; i++){
        //allocate extra spaces!
        //firstly, get the length and get the content in a temperal variable.
        if((string= alloc(MAXLEN)) == 0)
            return -1;

        if(__getline(string, MAXLEN) <= 0)
            return 0;

        lineptr[i] = string;
    }

    return i;
}

void writelines(char *lineptr[], int nlines){
    if(lineptr == NULL || nlines <= 0)
        return;

    for(int i = 0; i < nlines; i++){
        printf("%s", lineptr[i]);
    }

    return;
}