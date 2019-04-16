//
// Created by zhenguo on 19-4-11.
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
   int j,p;
   ElementType tmp;

   for(p = 1; p < len; p++){
       tmp = A[p];
       for(j = p; j > 0 && A[j-1] > tmp; j--){
           A[j] = A[j-1];
       }
       A[j] = tmp;
   }
}

//Shell Sort
void shellSort(ElementType *A, int len){
    ElementType tmp;
    int i, j, inc;

    for(inc = len/2; inc > 0; inc /=2){
        for(i = inc; i < len; i++){
            tmp = A[i];
            for(j = i; j >= inc; j-=inc){
                if(tmp < A[j-inc])
                    A[j] = A[j-inc];
                else
                    break;
            }
            A[j] = tmp;
        }
    }
}

//Heap Sort
#define LEFTCHILD(i) (2*(i)+1)
void percDown(ElementType *A, int i, int len){
    int child;
    ElementType tmp;

    for(tmp = A[i]; LEFTCHILD(i) < len; i = child){
        child = LEFTCHILD(i);
        if(child != len-1 && A[child+1] > A[child])
            child++;
        if(tmp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i]=tmp;
}
void heapSort(ElementType *A, int len){
    int i;
    for(i = len/2; i >= 0; i--){
        percDown(A, i, len);
    }
    for(i = len-1; i > 0; i--){
        swap(&A[0], &A[i]);
        percDown(A,0,i);
    }
}

//MergeSort
void merge(ElementType *A, ElementType *tmpArray, int lPos, int rPos, int rightEnd){
    int i, leftEnd, numElements, tmpPos;

    leftEnd = rPos - 1;
    tmpPos = lPos;
    numElements = rightEnd - lPos + 1;

    /* mainloop */
    while(lPos <= leftEnd && rPos <= rightEnd){
        if(A[lPos] <= A[rPos])
            tmpArray[tmpPos++] = A[lPos++];
        else
            tmpArray[tmpPos++] = A[rPos++];

    }

    /* Copy rest */
    while(lPos <= leftEnd)
        tmpArray[tmpPos++] = A[lPos++];
    while (rPos <= rightEnd)
        tmpArray[tmpPos++] = A[rPos++];

    /* Copy TmpArray back */
    for( i = 0; i < numElements; i++, rightEnd--){
        A[rightEnd] = tmpArray[rightEnd];
    }
}

void MSort(ElementType *A, ElementType *tmpArray, int left, int right){
    int center;

    if(left < right){
        center = (left+right)/2;
        MSort(A, tmpArray, left, center);
        MSort(A, tmpArray, center+1, right);
        merge(A, tmpArray, left, center+1, right);
    }
}

void mergeSort(ElementType *A, int N){
    ElementType *tmpArray;

    tmpArray = malloc(N * sizeof(ElementType));

    if(tmpArray != NULL){
        MSort(A, tmpArray, 0, N-1);
        free(tmpArray);
    }else{
        fprintf(stderr, "No space for tmp array!!\n");
    }
}

//Quick Sort
ElementType Median3(ElementType *A, int Left, int Right){
    int Center = (Left + Right)/2;

    if(A[Left] > A[Center])
        swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])
        swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])
        swap(&A[Center], &A[Right]);

    swap(&A[Center], &A[Right-1]);
    return A[Right-1];
}

#define CUTOFF (3)

void Qsort(ElementType *A, int left, int right){
    int i, j;
    ElementType pivot;
    //printf("old:");
    //displayArray(A+left, right-left+1);
    if(left + CUTOFF <= right){
        pivot = Median3(A, left, right);
        i =left; j =right-1;
        while(1){
            while(A[++i] < pivot);
            while(A[--j] > pivot);
            if(i < j)
                swap(&A[i], &A[j]);
            else
                break;
        }
        swap(&A[i], &A[right-1]);
        //printf("pivot num [%d]: %d\n", i, A[i]);
        //printf("new:");
        //displayArray(A+left, right-left+1);
        Qsort(A, left, i-1);
        Qsort(A, i+1, right);
    } else{
        insertSort(A+left, right-left+1);
    }

}

void quicksort(ElementType *A, int N){
    Qsort(A, 0, N-1);
}
int main(){
    testSort(insertSort, "insert sort");
    testSort(shellSort, "shell sort");
    testSort(heapSort, "heap sort");
    testSort(mergeSort, "merge sort");
    testSort(quicksort, "quick sort");
    return 0;
}

int testSort(void (*sort)(ElementType *, int), char name[]){
    int len = 16;
    ElementType res[] = {0,0,0,1,2,3,4,5,5,5,6,7,8,9,9,9};
    ElementType *test = randomArray(res, len);
    sort(test, len);
    printf("%s test: %s\n", name, compareArray(res, test, len)?"pass":"fail");
    if(!compareArray(res, test, len))
        displayArray(test,len);
    free(test);
}