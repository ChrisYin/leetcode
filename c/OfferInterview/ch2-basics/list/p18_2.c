//
// Created by zhenguo on 19-4-28.
//

/*
 * Description:
 *
 * Delete the repeated node in a ordered singly-linked list;
 *
 *
 */

/*
 * Thinking:
 *
 *      using loop: find the next diffetent node.
 *
 */

/*
 * Learning:
 *
 * More testcases: a list with unique nodes
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *deleteRepeatedNode(ListNode *list){
    if(!list)
        return list;

    ListNode *cur;
    ListNode *nextDiffNode;
    ListNode *tmp;

    cur = list;
    nextDiffNode = cur->next;
    while(nextDiffNode){
        cur->next = nextDiffNode;
        if(nextDiffNode->val != cur->val){
            cur = nextDiffNode;
            nextDiffNode = cur->next;
        }else{
            tmp = nextDiffNode;
            nextDiffNode = nextDiffNode->next;
            free(tmp);
        }
    }
    cur->next = NULL;
    return list;
}


/*
 * Testcases:
 *
 * 1. functional test:
 *
 *      [four nodes]: two repeated node in the middle.
 *
 * 2. boundary test
 *
 *      [one node]
 *      [two repeated nodes]
 *      [four nodes]: two in head, two in tail
 *      [no repeated list]
 *
 * 3. negative test:
 *      list is NULL.
 */

void printList(ListNode *root){
    while(root){
        printf("%d%s",root->val, (root->next)?"->":"\n");
        root = root->next;
    }
}

void test1(){
    ListNode *root = malloc(sizeof(ListNode));
    ListNode *node1 = malloc(sizeof(ListNode));
    ListNode *node2 = malloc(sizeof(ListNode));
    ListNode *node3 = malloc(sizeof(ListNode));

    root->val = 0;
    node1->val = 1;
    node2->val = 1;
    node3->val = 2;

    root->next = node1;
    node1->next = node2;
    node2->next = node3;

    printList(root);
    root = deleteRepeatedNode(root);
    printList(root);
}

void test2(){
    ListNode *root = malloc(sizeof(ListNode));
    root->val = 0;
    root->next = NULL;

    printList(root);
    root = deleteRepeatedNode(root);
    printList(root);
}

void test3(){
    ListNode *root = malloc(sizeof(ListNode));
    ListNode *node1 = malloc(sizeof(ListNode));

    root->val = 0;
    node1->val = 0;

    root->next = node1;

    printList(root);
    root = deleteRepeatedNode(root);
    printList(root);
}

void test4(){
    ListNode *root = malloc(sizeof(ListNode));
    ListNode *node1 = malloc(sizeof(ListNode));
    ListNode *node2 = malloc(sizeof(ListNode));
    ListNode *node3 = malloc(sizeof(ListNode));

    root->val = 1;
    node1->val = 1;
    node2->val = 2;
    node3->val = 2;

    root->next = node1;
    node1->next = node2;
    node2->next = node3;

    printList(root);
    root = deleteRepeatedNode(root);
    printList(root);
}

int main(){
    printf("test1:\n");
    test1();
    printf("test2:\n");
    test2();
    printf("test3:\n");
    test3();
    printf("test4:\n");
    test4();
    return 0;
}