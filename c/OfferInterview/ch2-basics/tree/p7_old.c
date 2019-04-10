//
// Created by zhenguo on 19-4-10.
//

/*
 * Description: Given two array of preorder transversal and inorder transversal.
 * Rebuild the tree.
 *
 */

/*
 * Thinking:
 *
 * doing it manually to see how to build the tree.
 *
 * Using Recursive Method:
 *
 * 1. Find the root node.
 *
 * 2. Find the subtree nodes with its preorder and inorder transversal.
 *
 * 3. Recursion to subtrees.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m_nValue;
    struct BinaryTreeNode *m_pleft;
    struct BinaryTreeNode *m_pright;
} BinaryTreeNode;

/*
 * preorder: preorder transversal
 * inorder: inorder transversal
 * length: size of the tree
 * return the BinaryTreeNode
 */
BinaryTreeNode *rebuildTree(int *preorder, int *inorder, int length){
    if(length <= 0 || preorder == NULL || inorder == NULL)
        return NULL;
    BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    root->m_nValue = preorder[0];
    /*
     * Attention: malloc dont't initialize the data
     */
    root->m_pleft = root->m_pright = NULL;

    //find the root node in the inorder transversal
    int rootPosition = -1;
    for(int i = 0; i < length; i++){
        if(inorder[i] == root->m_nValue){
            rootPosition = i;
            break;
        }
    }

    //left subtree search
    int leftLen = rootPosition;
    int *leftPreorder = &preorder[1];
    int *leftInorder = inorder;
    root->m_pleft = rebuildTree(leftPreorder, leftInorder, leftLen);

    //right subtree search
    int rightLen = length - rootPosition -1;
    int *rightPreorder = &preorder[leftLen + 1];
    int *rightInorder = &inorder[rootPosition + 1];
    root->m_pright = rebuildTree(rightPreorder, rightInorder, rightLen);

    return root;
}
/*
 * root: binary tree
 * return length of the tree
 */
int printTree(BinaryTreeNode *root){
    if(root == NULL)
        return -1;
    printf("%d ", root->m_nValue);
    printTree(root->m_pleft);
    printTree(root->m_pright);
    return 0;
}

/*
 * TestCases:
 * test1: normal example
 * test2: null
 * test3: left side tree
 * test4: right side tree
 * test5: one node tree
 */

int test1();
int test2();
int test3();
int test4();
int test5();

int testPrint();

int main(int argc, char **argv){
    test5();
    //testPrint();
}

int testPrint(){
    BinaryTreeNode *root = malloc(sizeof(BinaryTreeNode));
    BinaryTreeNode *x0 = malloc(sizeof(BinaryTreeNode));
    BinaryTreeNode *x1 = malloc(sizeof(BinaryTreeNode));
    BinaryTreeNode *x2 = malloc(sizeof(BinaryTreeNode));
    BinaryTreeNode *x3 = malloc(sizeof(BinaryTreeNode));
    BinaryTreeNode *x4 = malloc(sizeof(BinaryTreeNode));
    BinaryTreeNode *x5 = malloc(sizeof(BinaryTreeNode));
    BinaryTreeNode *x6 = malloc(sizeof(BinaryTreeNode));

    root->m_nValue = 1;
    root->m_pleft = x0;
    x0->m_nValue = 2;
    x0->m_pleft = x1;
    x1->m_nValue = 4;
    x1->m_pleft = x2;
    x2->m_nValue = 7;

    root->m_pright = x3;
    x3->m_nValue = 3;
    x3->m_pleft = x4;
    x4->m_nValue = 5;
    x3->m_pright = x5;
    x5->m_nValue = 6;
    x5->m_pright = x6;
    x6->m_nValue = 8;

    printTree(root);

}

int test1(){
    int LEN = 8;
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};

    BinaryTreeNode *root = rebuildTree(preorder, inorder, LEN);
    printTree(root);
}

int test2(){
    int LEN = 0;
    int preorder[] = {};
    int inorder[] = {};

    BinaryTreeNode *root = rebuildTree(preorder, inorder, LEN);
    printTree(root);
}

int test3(){
    int LEN = 4;
    int preorder[] = {1, 2, 3, 4};
    int inorder[] = {4, 3, 2, 1};

    BinaryTreeNode *root = rebuildTree(preorder, inorder, LEN);
    printTree(root);
}

int test4(){
    int LEN = 4;
    int preorder[] = {1, 2, 3, 4};
    int inorder[] = {1, 2, 3, 4};

    BinaryTreeNode *root = rebuildTree(preorder, inorder, LEN);
    printTree(root);
}

int test5(){
    int LEN = 1;
    int preorder[] = {1};
    int inorder[] = {1};

    BinaryTreeNode *root = rebuildTree(preorder, inorder, LEN);
    printTree(root);
}