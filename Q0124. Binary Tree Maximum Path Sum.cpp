#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/TreeNode.h"
#include <unordered_map>

class Solution {
    // unordered_map<pair<TreeNode*, TreeNode*>, int> umap;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> mx_path;
    int mx;

public:
    Solution(){}
    int maxPathSum(TreeNode* root) {
        mx = INT32_MIN;
        solve(root);

        return mx;
    }

    void solve(TreeNode* root) {
        if(!root) return;

        int cur_mx = root->val + maxPath(root->left) + maxPath(root->right);
        if(mx < cur_mx) mx = cur_mx;

        solve(root->left);
        solve(root->right);
    }

    int maxPath(TreeNode* root) {
        if(!root) return 0;
        auto f = mx_path.find(root);
        if(f != mx_path.end()) return f->second;

        int left = maxPath(root->left);
        int right = maxPath(root->right);

        int ret  = max(root->val + max(left, right), 0);
        mx_path[root] = ret;
        return ret;
    }

    // void getParents(TreeNode* root) {
    //     if(root->left) {
    //         parent[root->left] = root;
    //         getParents(root->left);
    //     }
    //     if(root->right) {
    //         parent[root->right] = root;
    //         getParents(root->right);
    //     }
    // }

    // int pathFromRoot(TreeNode* root, TreeNode* target) {
    //     auto f = umap.find({root, target});
    //     if(f != umap.end()) return f->second;

    //     int distance;
    //     if(root == target) distance = 0;
    //     else distance = target->val + pathFromRoot(root, parent[target]);
    //     umap[{root, target}] = distance;
    //     return distance;
    // }
};

int main() {
    Solution so;
    TreeNode root;

    root = {-10,9,20,-1,-1,15,7};
    cout << so.maxPathSum(&root) << endl;
}