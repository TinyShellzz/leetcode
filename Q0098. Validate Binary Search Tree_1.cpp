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
            solve(root);
        } catch (int const ax) {
            return false;
        }

        return true;
    }

    pair<long, long> solve(TreeNode* root) {
        if(!root) {
            return {INT64_MAX, INT64_MIN};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);
        if(!(left.second < root->val && right.first > root->val)) throw 0;

        return {root->left ? left.first : root->val, root->right ? right.second : root->val};
    }
};

int main() {
    Solution so;
    TreeNode root;

    root = {2,1,3};
    cout << so.isValidBST(&root) << endl;

    return 0;
}