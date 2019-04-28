//
// Created by zhenguo on 19-4-28.
//

/*
 * Description:
 *
 * Delete node of a list in O(1)
 *
 *
 */


/*
 * Thinking:
 *
 * It is a singly-linked list.
 *
 * If we want delete the node in O(1), then we can not find its parent node.
 *
 * We need to replace the deleted node with its next node.
 *
 */

/*
 * Learning:
 *
 * Need to free if you delete one node in a list.
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    int m_nValue;
    struct ListNode *m_pNext;
} ListNode;

void DeleteNode(ListNode** pListHead, ListNode *pToBeDeleted){
    if(pListHead == NULL || pToBeDeleted == NULL || *pListHead == NULL)
        return;


    ListNode *cur;
    ListNode *prev;

    //head
    if(pToBeDeleted == *pListHead){
        *pListHead = (*pListHead)->m_pNext;
        free(pToBeDeleted);
        return;
    }

    //tail
    if(pToBeDeleted->m_pNext == NULL){
        cur = *pListHead;
        prev = *pListHead;
        while(cur){
            if(cur == pToBeDeleted){
                prev->m_pNext = NULL;
                break;
            }
            prev = cur;
            cur = cur->m_pNext;
        }
        free(pToBeDeleted);
        return;
    }

    //normal
    pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
    pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
    free(pToBeDeleted->m_pNext);
    return;




}

/*
 * Testcases:
 *
 * 1. functional test:   [three nodes]delete second node
 *
 * 2. boundary test:    [one node] delete one node
 *
 *                      [two nodes] delete the head
 *
 *                      [three nodes] delete the tail
 *
 * 3. negative test:    [null pointer]  delete null pointer
 */

void printList(ListNode *root){
    while(root){
        printf("%d%s",root->m_nValue, (root->m_pNext)?"->":"\n");
        root = root->m_pNext;
    }
}
void test1(){
    ListNode *root = malloc(sizeof(ListNode));
    ListNode *node1 = malloc(sizeof(ListNode));
    ListNode *node2 = malloc(sizeof(ListNode));

    root->m_nValue = 0;
    node1->m_nValue = 1;
    node2->m_nValue = 2;

    root->m_pNext = node1;
    node1->m_pNext = node2;

    printList(root);
    DeleteNode(&root,node1);
    printList(root);
}

void test2(){
    ListNode *root = malloc(sizeof(ListNode));

    root->m_nValue = 0;

    printList(root);
    DeleteNode(&root,root);
    printList(root);
}

void test3(){
    ListNode *root = malloc(sizeof(ListNode));
    ListNode *node1 = malloc(sizeof(ListNode));

    root->m_nValue = 0;
    node1->m_nValue = 1;

    root->m_pNext = node1;

    printList(root);
    DeleteNode(&root,root);
    printList(root);
}

void test4(){
    ListNode *root = malloc(sizeof(ListNode));
    ListNode *node1 = malloc(sizeof(ListNode));
    ListNode *node2 = malloc(sizeof(ListNode));

    root->m_nValue = 0;
    node1->m_nValue = 1;
    node2->m_nValue = 2;

    root->m_pNext = node1;
    node1->m_pNext = node2;

    printList(root);
    DeleteNode(&root,node2);
    printList(root);
}

void test5(){
    ListNode *root = NULL;
    printf(root);
    DeleteNode(&root, NULL);
    printf(root);
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
    printf("test5:\n");
    test5();
    return 0;
}