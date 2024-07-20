#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/TreeNode.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        try {
            solve(root, INT64_MIN, INT64_MAX);
        } catch (int const ax) {
            return false;
        }

        return true;
    }

    void solve(TreeNode* root, long left_bound, long right_bound) {
        if(!root) {
            return;
        }

        if(!(left_bound < root->val && root->val < right_bound)) throw 0;

        solve(root->left, left_bound, root->val);
        solve(root->right, root->val, right_bound);
    }
};

int main() {
    Solution so;
    TreeNode root;

    root = {2,1,3};
    cout << so.isValidBST(&root) << endl;

    return 0;
}