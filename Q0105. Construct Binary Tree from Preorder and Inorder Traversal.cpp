#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/TreeNode.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        solve(root, preorder, 0, preorder.size(), inorder, 0, inorder.size());

        return root;
    }

    void solve(TreeNode *root, vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
        if(!root) return;

        int i = s2;
        for(; i != e2; i++) {
            if(root->val == inorder[i]) break;
        }

        int left_tree_node_count = i - s2;
        int right_tree_node_count = e2-i-1;
        TreeNode *left = NULL, *right = NULL;
        if(left_tree_node_count) left = new TreeNode(preorder[s1+1]);
        if(right_tree_node_count) right = new TreeNode(preorder[s1+left_tree_node_count+1]);
        root->left = left;
        root->right = right;

        solve(left, preorder, s1+1, s1+left_tree_node_count+1, inorder, s2, i);
        solve(right, preorder, s1+left_tree_node_count+1, e1, inorder, i+1, e2);
    }
};

int main() {
    Solution so;
    vector<int> inorder, preorder;

    cout << so.buildTree(preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7})->toString() << endl;
}