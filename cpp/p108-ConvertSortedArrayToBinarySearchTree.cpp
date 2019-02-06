//
// Created by zy234 on 1/10/19.
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
#include <vector>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

//my solution: 12ms 99.58%
class Solution {
private:
    void createMidNode(vector<int> &nums, int start, int end, TreeNode *parentNode, bool isLeft){
        //cout<<"start: "<<start<<"end: "<<end<<endl;

        if(end < start)
            return;
        int mid = (start + end)/2;
        //cout<<"mid: "<<mid<<endl;
        TreeNode *childNode = new TreeNode(nums[mid]);
        //cout<<"new node"<<childNode<<":  "<<childNode->val<<endl;
        if(isLeft){
            parentNode->left = childNode;
        }else{
            parentNode->right = childNode;
        }
        createMidNode(nums, start, mid-1, childNode, true);
        createMidNode(nums, mid+1, end, childNode, false);
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty())
            return NULL;
        TreeNode *rootNode = new TreeNode(nums[nums.size()/2]);
        //cout<<"new node "<<rootNode<<":  "<<rootNode->val<<endl;
        createMidNode(nums, 0, nums.size()/2 -1, rootNode, true);
        createMidNode(nums, nums.size()/2+1, nums.size()-1, rootNode, false);
        return rootNode;
    }
};

void printTree(TreeNode *tree){
    queue<TreeNode *> st;
    st.push(tree);
    queue<int> test;
    while(!st.empty()){
        TreeNode *printNode = st.front();
        st.pop();
        cout<<printNode->val<<endl;
        if(printNode->left!=NULL)
            st.push(printNode->left);
        if(printNode->right != NULL)
            st.push(printNode->right);
    }
}

int main(){
    vector<int> testArray = {-10,-3,0,5,9, 11};
    Solution test;
    TreeNode *res = test.sortedArrayToBST(testArray);
    printTree(res);
    return 0;
}
