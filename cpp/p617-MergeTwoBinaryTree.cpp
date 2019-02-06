//
// Created by zy234 on 1/9/19.
//
using namespace std;
#include <iostream>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
};

//my solution: 48ms
class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;
        t1->val += t2->val;
        t1->right = mergeTrees(t1->right, t2->right);
        t1->left = mergeTrees(t1->left, t2->left);
        return t1;
    }
};

void print_tree(TreeNode *in){
    if(in == NULL)
        return;
    cout<<in->val<<endl;
    cout<<"left: ";
    print_tree(in->left);
    cout<<"right  ";
    print_tree(in->right);

}

int main(){
    vector<int> array0 = {1,3,2,5};
    vector<int> array1 = {2,1,3,NULL,4,NULL,7};
    TreeNode *tree0 = new TreeNode[array0.size()];
    for(int i = 0; i < array0.size(); i++) {
        tree0[i].val = array0[i];
    }
    tree0[0].left  = &tree0[1];
    tree0[0].right = &tree0[2];
    tree0[1].left = &tree0[3];

    TreeNode *tree1 = new TreeNode[array1.size()];
    for(int i = 0; i < array1.size(); i++) {
        tree1[i].val = array1[i];
    }
    tree1[0].left  = &tree1[1];
    tree1[0].right = &tree1[2];
    tree1[1].right = &tree1[4];
    tree1[2].right = &tree1[6];

    //print_tree(tree1);

    Solution test;
    TreeNode *res = test.mergeTrees(tree0, tree1);
    print_tree(res);
}