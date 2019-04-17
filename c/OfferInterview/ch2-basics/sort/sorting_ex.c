//
// Created by zhenguo on 19-4-16.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
 * Description:
 *
 * Implement daily sorting algorithms in C and compare them on time efficiency and space efficiency.
 *
 * Assumption:
 *
 * Input data is legal.
 *
 */

typedef int ElementType;

static ElementType *randomArray(ElementType *A, int len){
    ElementType *res = malloc(sizeof(ElementType) * len);

    for(int i = 0; i < len; i++){
        res[i] = A[i];
    }

    srand((unsigned int)time(0));
    for(int i = 0; i < len; i++){
        int tmpNum = rand()%len;
        ElementType tmp = res[i];
        res[i] = res[tmpNum];
        res[tmpNum] = tmp;
    }

    return res;
}

static void displayArray(int *A, int len){
    for(int i = 0; i < len; i++){
        printf("%d%c", A[i], (i==len-1)?'\n':' ');
    }
}

static int compareArray(ElementType *A, ElementType *B, int len){
    for(int i = 0; i < len; i++){
        if(A[i] != B[i])
            return 0;
    }
    return 1;
}

static void swap(ElementType *A, ElementType *B){
    ElementType tmp = *A;
    *A = *B;
    *B = tmp;
}

int testSort(void (*sort)(ElementType *, int), char name[]);

//Insert Sort
void insertSort(ElementType *A, int len){
    if(A == NULL || len <= 0){
        fprintf(stderr, "error: invalid sorting array!\n");
        return;
    }
    ElementType tmp;

    for(int i = 1; i < len; i++){
        tmp = A[i];
        int j;
        for(j = i; j > 0; j--){
            if(tmp < A[j-1]){
                A[j] = A[j-1];
            }else{
                break;
            }
        }
        A[j] = tmp;
    }
    return;

}

//Shell Sort
void shellSort(ElementType *A, int len){
    if(A == NULL || len <= 0){
        fprintf(stderr, "error: invalid sorting array!\n");
    }

    ElementType tmp;
    int inc, pivot, j;

    for(inc = len/2; inc > 0; inc /= 2){
        for(pivot = inc; pivot < len; pivot++){
            tmp = A[pivot];
            for(j = pivot; j-inc >= 0; j -= inc){
                if(tmp < A[j-inc]){
                    A[j] = A[j-inc];
                } else{
                    break;
                }
            }
            A[j] = tmp;
        }
    }
    return;
}

//Heap Sort
/*
 * Define the relationship between array index and tree node:
 *
 *          0
 *        1   2
 *       3 4 5 6
 */
#define LEFTNODE(i) (2*(i)+1)
#define RIGHTNODE(i) (2*(i)+2)
#define PARENTNODE(i) (((i)-1)/2)

void percDown(ElementType *A, int i, int len){
    int child;

    for(int node = i; (child = LEFTNODE(node)) < len ;node = child){
        if(RIGHTNODE(node) < len && A[RIGHTNODE(node)] > A[LEFTNODE(node)]){
            child = RIGHTNODE(node);
        }
        if(A[node] < A[child]){
            swap(&A[node],&A[child]);
            //displayArray(A, len);
        }else{
            break;
        }
    }
}

void heapSort(ElementType *A, int len){
    for(int i = len/2; i >= 0; i--){
        percDown(A, i, len);
        //displayArray(A, len);
    }
    for(int i = len-1; i > 0; i--){
        swap(&A[0], &A[i]);
        percDown(A, 0, --len);
    }
}


int main(){
    testSort(insertSort, "insert sort");
    testSort(shellSort, "shell sort");
    testSort(heapSort,"heap sort");

    return 0;
}

int testSort(void (*sort)(ElementType *, int), char name[]){
    int len = 16;
    ElementType res[] = {0,0,0,1,2,3,4,5,5,5,6,7,8,9,9,9};
    ElementType *test = randomArray(res, len);
    sort(test, len);
    printf("%s test: %s\n", name, compareArray(res, test, len)?"pass":"fail");
    if(!compareArray(res, test, len))
        displayArray(test, len);
    free(test);
}