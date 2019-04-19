//
// Created by zhenguo on 19-4-19.
//

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct intListEntry{
    TAILQ_ENTRY(intListEntry) next;
    int data;
}intListEntry;

TAILQ_HEAD(intList, intListEntry);

int tailqueueTest(){
    struct intList intListTest;

    TAILQ_INIT(&intListTest);
    printf("list1 is empty? %s.\n",TAILQ_EMPTY(&intListTest)? "YES":"NO");

    intListEntry *elm1 = malloc(sizeof(intListEntry));
    elm1->data = 0;
    TAILQ_INSERT_HEAD(&intListTest, elm1, next);

    intListEntry *elm2 = malloc(sizeof(intListEntry));
    elm2->data = 1;
    TAILQ_INSERT_HEAD(&intListTest, elm2, next);

    intListEntry *elm3 = malloc(sizeof(intListEntry));
    elm3->data = 2;
    TAILQ_INSERT_HEAD(&intListTest, elm3, next);

    printf("forward transversal:\n");
    intListEntry *var = NULL;
    TAILQ_FOREACH(var, &intListTest, next){
        printf("foreach: %d\n", var->data);
    }
    printf("backward transversal:\n");
    TAILQ_FOREACH_REVERSE(var, &intListTest, intList, next){
        printf("foreach: %d\n", var->data);
    }

    return 0;


}
int main(){
    tailqueueTest();
    return 0;
}