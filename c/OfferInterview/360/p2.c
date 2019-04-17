//
// Created by zhenguo on 19-4-16.
//


/*
 * 时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
构建HASH表，HASH表大小为hashsize，键值key为正整数，hash函数表达为key%hashsize，求解最大桶深和对应等于该桶深的所有桶的索引值及桶中key值
 */

/*
 *
 *
输入
输入为

hashsize/key

格式，其中hashsize为正整数，key值可以是单个数字，数字区间等(如果key值重复的话要进行去重处理)

输出
输出为

maxdepth-index-key

(如果bucket有多个重复的值，输出第一个即可)

(key多个时，使用空格分隔)


样例输入
4/1-20,100
样例输出
6-0-100 20 16 12 8 4
 */

/*
 * thinking:
 *
 * 1. 构建输入的Key数组
 * 2. 构建HashTable
 *
 * struct HashBucket{
 * int size;
 * LinkNode *list;
 * }
 * 3. init HashBucket
 *
 * 4. find the largets bucket
 *
 */
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

typedef struct HashBucket{
    int size;
    ListNode *list;
} HashBucket;

//linkedlist function
ListNode* listFind(ListNode *list, int key){
    if(list == NULL)
        return NULL;
    ListNode *cur=list;
    while(cur != NULL){
        if(cur->val == key)
            break;
        cur = cur->next;
    }
    return cur;
}

int bucketAdd(HashBucket *bucket, int key){
    if(bucket == NULL)
        return -1;

    //repeated keys
    if(listFind(bucket->list, key) != NULL){
        return -2;
    }

    //add key
    ListNode *newKey = malloc(sizeof(ListNode));
    newKey->val = key;
    newKey->next = bucket->list;

    (bucket->size)++;
    bucket->list = newKey;
    return 0;
}


//Main Function
int calHashBucket(int hashSize, int *keys, int keyLen){
    if(hashSize <= 0 || keys == NULL || keyLen <= 0)
        return -1;

    HashBucket bucket[hashSize];

    //init hashbucket
    for(int i = 0; i < hashSize; i++){
        bucket[i].size = 0;
        bucket[i].list = NULL;
    }

    for(int i = 0; i < keyLen; i++){
        bucketAdd(&bucket[keys[i]%hashSize], keys[i]);
    }

    //display hashbucket
/*    for(int i = 0; i < hashSize; i++){
        printf("bucket[%d]:", i);
        ListNode *cur = bucket[i].list;
        while(cur!=NULL){
            printf("%d ", cur->val);
            cur = cur->next;
        }
        printf("\n");
    }*/
    int largeBucket = 0;
    for(int i = 0 ; i < hashSize; i++){
        if(bucket[i].size > bucket[largeBucket].size){
            largeBucket = i;
        }
    }
    //printf("large bucket: %d size: %d\n", largeBucket, bucket[largeBucket].size);
    printf("%d-%d-", bucket[largeBucket].size, largeBucket);
    ListNode *cur = bucket[largeBucket].list;
    while(cur!=NULL){
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
    return 0;

}

#define MAX_CHAR 1024
#define MAX_KEYS 1024
int solution(){

    char InputString[MAX_CHAR];
    int size;
    int keys[MAX_KEYS];
    int keyLen = 0;

    while(fgets(InputString, MAX_CHAR, stdin)){
        char *cur = InputString;
        int offset = 0;
        char tmpChar;
        int tmpKey1, tmpKey2;

        //get keys
        sscanf(cur, "%d/%n", &size, &offset);
        cur += offset;
        while((sscanf(cur, "%d%c%n", &tmpKey1, &tmpChar, &offset))!=EOF){
            cur+=offset;
            keys[keyLen++] = tmpKey1;
            if(tmpChar == '-'){
                sscanf(cur, "%d%c%n", &tmpKey2, &tmpChar, &offset);
                cur+=offset;
                for(int i=tmpKey1+1; i <= tmpKey2; i++){
                    keys[keyLen++] = i;
                }
            }
        }
        //show keys
/*        for(int i = 0; i < keyLen; i++){
            printf("%d ", keys[i]);
        }
        printf("\n");*/

        //printf("testcase: %d %d\n", size, keyLen);
        calHashBucket(size, keys, keyLen);


        //clear data for next loop
        keyLen = 0;
        memset(InputString, 0, sizeof(char)*MAX_CHAR);
    }
    return 0;

}

void test1(){
    int keyLen = 20;
    int keys[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int hashsize = 6;
    calHashBucket(hashsize, keys, keyLen);
}

void test2(){
    int keyLen = 21;
    int keys[21] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,100};
    int hashsize = 4;
    calHashBucket(hashsize, keys, keyLen);
}
int main(){
    solution();
    //test2();
    return 0;
}