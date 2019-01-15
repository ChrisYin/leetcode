//
// Created by zy234 on 1/15/19.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;

#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

//my solution: only calculate the number of univalue nodes;
//wront solution
class MySolution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = 0;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            TreeNode *newNode = nodeQueue.front();
            nodeQueue.pop();
            int length = 0;
            queue<TreeNode *> tempQueue;
            if(newNode->left != NULL)
            tempQueue.push(newNode->left);
            if(newNode->right != NULL)
            tempQueue.push(newNode->right);
            while(!tempQueue.empty()){
                TreeNode *nextNode = tempQueue.front();
                tempQueue.pop();
                if(nextNode->val == newNode->val){
                    length++;
                    if(nextNode->left != NULL)
                    tempQueue.push(nextNode->left);
                    if(nextNode->right != NULL)
                    tempQueue.push(nextNode->right);
                }else{
                    nodeQueue.push(nextNode);
                }
            }
            if(length > res)
                res = length;
            //cout<<"node: "<<newNode->val<<" length: "<<length<<endl;

        }
        return res;
    }
};

//64ms 74%: dynamic programming with dfs
class Solution {
private:
    int dfs(TreeNode* node, int &len){
        if(node == NULL)
            return 0;
        int leftNodeLen = (node->left)?dfs(node->left, len):0;
        int rightNodeLen = (node->right)?dfs(node->right, len):0;
        int leftLength = (node->left && node->left->val == node->val)?leftNodeLen+1:0;
        int rightLength = (node->right && node->right->val == node->val)?rightNodeLen+1:0;
        len = max(len, leftLength+rightLength);
        return max(leftLength, rightLength);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};

int main(){
    TreeNode *root = new TreeNode(4);
    TreeNode *node1 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = NULL;
    node2->right = node5;
    Solution test;
    int res = test.longestUnivaluePath(root);
    cout<<"result is : "<<res<<endl;
}