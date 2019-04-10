//
// Created by zhenguo on 19-4-2.
//

#ifndef FOROFFER_LINKEDLIST_H
#define FOROFFER_LINKEDLIST_H

typedef struct LinkedList{
    int val;
    struct LinkedList* next;
} LinkedList;

/*
 * Interface:
 * 
 * addNode: add a node of val at the tail of the linked list
 * 
 * deleteNode: delete the node with val when first appears in the linked list
 * 
 */
LinkedList* addNode(LinkedList** root, int val);
void deleteNode(LinkedList** root, int val);
LinkedList *initLinkedList(int length);
int printLinkedList(LinkedList *root);

#endif //FOROFFER_LINKEDLIST_H
