//
// Created by zhenguo on 19-4-10.
//

/*
 * Description:
 *
 * Given a binary search tree and one node, find its next node according to inorder transversal.
 *
 */

#include <stdlib.h>
#include <stdio.h>

/*
 * Thinking:
 *
 * 1. If it has right subtree, the next node is the leftest node of the right subtree.
 *
 * 2. If it is the left subtree of its parent node, the next node is its parent node.
 *
 * 3. Go through is parent node recursively, to find a node which is the left subtree of its parent node.
 *
 */


typedef struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    struct BinaryTreeNode *parent;
} BinaryTreeNode;


//find the leftest node of the tree root
BinaryTreeNode *findLeftestNode(BinaryTreeNode *root){
    if(root == NULL)
        return NULL;


}
/*
 * Interface:
 * root: binary tree
 * return the next node
 */
BinaryTreeNode *findNextNode(BinaryTreeNode *testNode){
    if(testNode == NULL)
        return NULL;

    //Does its right node exit?
    if(testNode->right != NULL){
        BinaryTreeNode *leftestNode = testNode->right;
        while(leftestNode->left !=  NULL){
            leftestNode = leftestNode->left;
        }
        return leftestNode;
    }


    //Loop to the parent node
    BinaryTreeNode *parentNode = testNode;
    while(parentNode != NULL){
        //Is is the left subtree of its parent node?
        if(parentNode->parent != NULL && parentNode->parent->left == parentNode){
            return parentNode->parent;
        }else{
            parentNode = parentNode->parent;
        }
    }

    return NULL;
}


/*
 * Init test binary tree: full binary tree
 */
int initBinaryTree(int valArray[], BinaryTreeNode *nodeArray[], int length){
    for(int i = 0; i < length; i++){
        nodeArray[i] = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        nodeArray[i]->val = valArray[i];
        //printf("%d: %d\n", i, valArray[i]);
    }

    int num = 0;
    for(int i = 0; i < length; i++){
        num = 2*i + 1;
        if(num >= 0 && num < length)
            nodeArray[i]->left = nodeArray[num];
        else
            nodeArray[i]->left = NULL;

        num = 2*i + 2;
        if(num >= 0 && num < length)
            nodeArray[i]->right = nodeArray[num];
        else
            nodeArray[i]->right = NULL;

        num =(i+1)/2 - 1;
        if(num >= 0 && num < length)
            nodeArray[i]->parent = nodeArray[num];
        else
            nodeArray[i]->parent = NULL;

        printf("node: %d %8x left: %8x right: %8x parent: %8x\n", i, nodeArray[i], nodeArray[i]->left, nodeArray[i]->right, nodeArray[i]->parent);
    }
}

/*
 * root: binary tree
 * return length of the tree
 */
int printTree(BinaryTreeNode *root){
    if(root == NULL)
        return -1;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
    return 0;
}

/*
 * testcases:
 *
 * test1: null
 * test2: rightest tree
 * test3: leftest tree
 * test4: one node tree
 * test5: Complete binary tree
 * test6: Incomplete binary tree
 */
int testprint();
int test1();
int test2();
/*
 * waiting for complete!
 */

int main(){
    test1();
    return 0;
}

int testprint(){
    int length = 5;
    int testArray[] = {6, 1, 2, 3, 4};
    BinaryTreeNode **nodeArray = malloc(sizeof(BinaryTreeNode *) * length);
    initBinaryTree(testArray, nodeArray, length);
    printTree(nodeArray[0]);
    return 0;
}

int test1(){
    BinaryTreeNode *testNode = NULL;
    BinaryTreeNode *nextNode = findNextNode(testNode);
    printf("test node val: %d\n", (testNode == NULL)?-1:testNode->val);
    printf("next node val: %d\n", (nextNode == NULL)?-1:nextNode->val);

    return 0;
}

int test2(){
    int length = 7;
    int valArray[] = {0, 1, 2, 3, 4, 5, 6};
    BinaryTreeNode **nodeArray = malloc(sizeof(BinaryTreeNode *)*length);
    initBinaryTree(valArray, nodeArray, length);
    printTree(nodeArray[0]);
    printf("\n");

    BinaryTreeNode *testNode = nodeArray[6];
    BinaryTreeNode *nextNode = findNextNode(testNode);
    printf("test node val: %d\n", (testNode == NULL)?-1:testNode->val);
    printf("next node val: %d\n", (nextNode == NULL)?-1:nextNode->val);

    return 0;
}