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

    //考虑到了输入的规范性
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

    //考虑到输入的规范性
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


    //可以省略
    if(del->next == NULL){
        cur->next = NULL;
        free(del);
        return;
    }

    cur->next = del->next;
    free(del);
    return;
}

LinkedList *initLinkedList(int length){
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

int printLinkedList(LinkedList *root){
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