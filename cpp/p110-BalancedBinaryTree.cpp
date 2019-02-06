//
// Created by zy234 on 1/17/19.
//

using namespace std;

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//my solution: 136ms 0.41%
class MySolution {
private:
    int heightDFS(TreeNode *node, bool &isBalanced){
        if(!isBalanced)
            return -1;
        int leftHeight = 0;
        int rightHeight = 0;
        if(node->left != NULL)
            leftHeight = heightDFS(node->left, isBalanced);
        if(!isBalanced)
            return -1;
        if(node->right != NULL)
            rightHeight = heightDFS(node->right, isBalanced);
        if(!isBalanced)
            return -1;
        if(abs(leftHeight - rightHeight) > 1)
            isBalanced = false;
        return max(leftHeight, rightHeight)+1;
    }

public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
            return true;
        bool res = true;
        heightDFS(root,res);
        return res;
    }
};

//clear solution
class Solution {
private:
    int heightDFS(TreeNode *node){
        if(node == NULL)
            return 0;
        int leftHeight = heightDFS(node->left);
        int rightHeight = heightDFS(node->right);
        if(leftHeight == -1 || rightHeight == -1)
            return -1;
        if(abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight, rightHeight)+1;
    }

public:
    bool isBalanced(TreeNode *root) {
        bool res = true;
        if(heightDFS(root) == -1){
            res = false;
        }
        return res;
    }
};

int main(){
    TreeNode *x0 = new TreeNode(1);
    TreeNode *x1 = new TreeNode(2);
    TreeNode *x2 = new TreeNode(3);
    TreeNode *x3 = new TreeNode(4);
    TreeNode *x4 = new TreeNode(5);
    TreeNode *x5 = new TreeNode(6);
    TreeNode *x6 = new TreeNode(7);
    x0->left = x1;
    x0->right = x2;
    x1->left = x3;
    x1->right = x4;
    x3->left = x5;
    x3->right = x6;
    Solution test;
    int res = test.isBalanced(x0);
    cout<<"res: "<<res<<endl;
}