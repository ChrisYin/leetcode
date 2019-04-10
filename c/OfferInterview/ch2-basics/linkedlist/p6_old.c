//
// Created by zhenguo on 19-4-2.
//
#include <stdio.h>
#include <ch2-basics/linkedlist/stack.h>
#include "linkedlist.h"

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
    deleteNode(&root, 0);
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

static int printRevLinkedList(LinkedList *root){
    if(root == NULL)
        return -1;

    STACK *stack = STACKcreate(100);
    int count = 0;

    while(root != NULL && count < 100){
        STACKpush(stack, (void *)root);
        count++;
        root = root->next;
    }

    while((root = (LinkedList *)STACKpop(stack)) != NULL){
        printf("%d %s ", root->val, "->");
    }

    return count;
    
}


int main(){
    LinkedList *root = initLinkedList(10);
    printLinkedList(root);
    printRevLinkedList(root);
    return 0;
}