//
// Created by zhenguo on 19-4-28.
//

/*
 * Description:
 *
 * Find the kth node in the reverse order of an list.
 *
 * The list begins at node one.
 *
 */


/*
 * Thinking:
 *
 * The best algorihtm is in O(1).
 *
 * Two pointer(their distance is keeping in k)
 * When the second pointer is at the last, the first pointer is the kth node of the reverse order.
 *
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;


ListNode *findKnode(ListNode *list, int k){
    if(list == NULL || k < 1)
        return NULL;

    ListNode *nodeK;
    ListNode *end;

    nodeK = list;
    end = list;
    for(int i = 1; i < k; i++){
        if(!end->next){
            return NULL;
        }
        end = end->next;
    }

    while(end->next){
        end = end->next;
        nodeK = nodeK->next;
    }

    return nodeK;
}


/*
 * testcases:
 *
 * 1. functional test
 *
 *      [three nodes] [2]
 *
 *
 * 2. boundary test
 *
 *      [one node] [1]
 *      [three nodes] [1]
 *      [three nodes] [3]
 *
 * 3. negative test
 *
 *      [null] [1]
 *      [one node] [0]
 *      [one node] [-1]
 *      [one node] [2]
 */

void printList(ListNode *root){
    while(root){
        printf("%d%s",root->val, (root->next)?"->":"\n");
        root = root->next;
    }
}

void test1(){
    printf("test1:\n");
    ListNode *node1 = malloc(sizeof(ListNode));
    ListNode *node2 = malloc(sizeof(ListNode));
    ListNode *node3 = malloc(sizeof(ListNode));

    node1->val = 1;
    node2->val = 2;
    node3->val = 3;

    node1->next = node2;
    node2->next = node3;

    printList(node1);

    int k = 2;
    ListNode *res = findKnode(node1,k);

    printf("%dth ele is: %d\n",k, res->val);

}

void test2(){
    printf("test2:\n");
    ListNode *node1 = malloc(sizeof(ListNode));

    node1->val = 1;

    printList(node1);

    int k = 1;
    ListNode *res = findKnode(node1,k);

    printf("%dth ele is: %d\n",k, res->val);

}

void test3(){
    printf("test3:\n");
    ListNode *node1 = malloc(sizeof(ListNode));
    ListNode *node2 = malloc(sizeof(ListNode));
    ListNode *node3 = malloc(sizeof(ListNode));

    node1->val = 1;
    node2->val = 2;
    node3->val = 3;

    node1->next = node2;
    node2->next = node3;

    printList(node1);

    int k = 1;
    ListNode *res = findKnode(node1,k);

    printf("%dth ele is: %d\n",k, res->val);

}

void test4(){
    printf("test4:\n");
    ListNode *node1 = malloc(sizeof(ListNode));
    ListNode *node2 = malloc(sizeof(ListNode));
    ListNode *node3 = malloc(sizeof(ListNode));

    node1->val = 1;
    node2->val = 2;
    node3->val = 3;

    node1->next = node2;
    node2->next = node3;

    printList(node1);

    int k = 3;
    ListNode *res = findKnode(node1,k);

    printf("%dth ele is: %d\n",k, res->val);

}

void test5(){
    printf("test5:\n");
    ListNode *node1 = NULL;

    printList(node1);

    int k = 1;
    ListNode *res = findKnode(node1,k);

    if(res){
        printf("%dth ele is: %d\n",k, res->val);
    }else{
        printf("NULL\n");
    }



}

void test6(){
    printf("test6:\n");
    ListNode *node1 = malloc(sizeof(ListNode));

    node1->val = 1;

    printList(node1);

    int k = 0;
    ListNode *res = findKnode(node1,k);

    if(res){
        printf("%dth ele is: %d\n",k, res->val);
    }else{
        printf("NULL\n");
    }

}

void test7(){
    printf("test7:\n");
    ListNode *node1 = malloc(sizeof(ListNode));

    node1->val = 1;

    printList(node1);

    int k = -1;
    ListNode *res = findKnode(node1,k);

    if(res){
        printf("%dth ele is: %d\n",k, res->val);
    }else{
        printf("NULL\n");
    }

}

void test8(){
    printf("test8:\n");
    ListNode *node1 = malloc(sizeof(ListNode));

    node1->val = 1;

    printList(node1);

    int k = 2;
    ListNode *res = findKnode(node1,k);

    if(res){
        printf("%dth ele is: %d\n",k, res->val);
    }else{
        printf("NULL\n");
    }

}

int main(){
    test1();
    printf("\n");
    test2();
    printf("\n");
    test3();
    printf("\n");
    test4();
    printf("\n");
    test5();
    printf("\n");
    test6();
    printf("\n");
    test7();
    printf("\n");
    test8();
    printf("\n");
    return 0;
}