//
// Created by zhenguo on 19-4-2.
//

/*
 * Description:
 *
 * Implement a linked list data structure
 *
 */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * add a new node at the tail of the linked list
 *
 * return the ponter of the new node
 */
LinkedList* addNode(LinkedList** root, int val){

    if(root == NULL)
        return NULL;

    LinkedList* newNode = malloc(sizeof(LinkedList));
    newNode->val = val;
    newNode->next = NULL;

    if(*root == NULL){
        return (*root = newNode);
    }

    LinkedList* tail = *root;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
    return newNode;

}

/*
 * delete the node with value val firstly appeared in the linked list
 *
 */
void deleteNode(LinkedList** root, int val){

    if(root == NULL)
        return;
    if(*root == NULL)
        return;

    LinkedList* cur;
    LinkedList* del;

    if((*root)->val == val){
        del = *root;
        *root = (*root)->next;
        free(del);
        return;
    }

    cur = *root;
    while(cur->next!=NULL){
        if(cur->next->val == val){
            del = cur->next;
            break;
        }
        cur = cur->next;
    }

    if(del->next == NULL){
        cur->next = NULL;
        free(del);
        return;
    }

    cur->next = del->next;
    free(del);
    return;
}

static LinkedList *initLinkedList(int length){
    if(length <= 0)
        return NULL;

    LinkedList *listArray[length];

    for(int i = 0; i < length; i++){
        listArray[i] = malloc(sizeof(LinkedList));
        listArray[i]->val = i;
    }
    for(int i = 0; i < length-1; i++){
        listArray[i]->next = listArray[i+1];
    }
    listArray[length-1]->next = NULL;

    return listArray[0];
}

static int printLinkedList(LinkedList *root){
    if(root == NULL)
        return 0;

    int count;
    while(root != NULL){
        printf("%d %s ", root->val, (root->next == NULL)?"end":"->");
        count++;
        root = root->next;
    }
    printf("\n");
    return count;

}

/*
 * testcase:
 *
 * // 开始链表为空, 测试添加与删除
 * // 开始链表为一个元素, 测试删除两个元素以及添加
 * // 开始链表为三个元素, 分别测试删除三个元素, 以及添加元素
 */

int test1(){
    LinkedList *root = NULL;
    printLinkedList(root);
    deleteNode(&root, 0);
    printLinkedList(root);
    addNode(&root, 0);
    printLinkedList(root);
}

int test2(){
    LinkedList *root = initLinkedList(1);
    printLinkedList(root);
    deleteNode(&root, 0);
    printLinkedList(root);
    deleteNode(&root, 0);
    printLinkedList(root);
    addNode(&root, 1);
    printLinkedList(root);
}

int test3(){
    LinkedList *root = initLinkedList(3);
    printLinkedList(root);
    addNode(&root, 4);
    printLinkedList(root);
    deleteNode(&root, 4);
    printLinkedList(root);
    deleteNode(&root, 0);
    printLinkedList(root);
    addNode(&root, 5);
    printLinkedList(root);
    addNode(&root, 6);
    printLinkedList(root);
    deleteNode(&root, 2);
    printLinkedList(root);

}
int main(){
    test3();
}