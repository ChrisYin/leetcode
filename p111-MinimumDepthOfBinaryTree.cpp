//
// Created by zhenguo on 1/31/19.
//
/*
 * Thinking: Uising recursive method to find the length of each leaf node
 *
 * Dynamic programming: if length > minLength, end recursive
 *
 * search order: root node -> left node -> right node
 *
 *
 * if cur_node is leaf node? update minLength
 *
 * check left node ?
 * check right node ?
 *
 * recursive to left.
 *
 */
using namespace std;

#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//my solution: 4ms 100%
class Solution {
private:
    bool isLeafNode(TreeNode *node){
        return (node->left == NULL && node->right == NULL);
    }
public:
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        if(isLeafNode(root))
            return 1;
        if(root->left != NULL && isLeafNode(root->left))
            return 2;
        if(root->right != NULL && isLeafNode(root->right))
            return 2;
        int depthLeft = numeric_limits<int>::max();
        int depthRight = numeric_limits<int>::max();
        if(root->left!=NULL)
        depthLeft = minDepth(root->left);
        if(root->right!=NULL)
        depthRight = minDepth(root->right);
        return min(depthLeft, depthRight) + 1;
    }
};

int main(){
    TreeNode *x0 = new TreeNode(1);
    TreeNode *x1 = new TreeNode(2);
    x0->left = x1;;
    Solution test;
    int res = test.minDepth(x0);
    cout<<"res: "<<res<<endl;
}
