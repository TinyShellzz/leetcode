#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/TreeNode.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        vector<TreeNode *> *pre_nodes, *nodes;
        pre_nodes = new vector<TreeNode *>;
        nodes = new vector<TreeNode *>;
        pre_nodes->push_back(root);

        vector<int> vals;
        while(pre_nodes->size()) {
            bool empty = true;
            for(TreeNode *n: *pre_nodes) {
                if(n) {
                    empty = false;
                    break;
                }
            }
            if(empty) break;

            for(TreeNode *n: *pre_nodes) {
                if(n) {
                    vals.push_back(n->val);
                    nodes->push_back(n->left);
                    nodes->push_back(n->right);
                } else {
                    vals.push_back(INT32_MIN);
                }
            }

            pre_nodes->clear();
            auto tmp = pre_nodes;
            pre_nodes = nodes;
            nodes = tmp;
        }

        int len = vals.size();
        while(len > 0 && vals[len-1] == INT32_MIN) len--;
        
        string ret = "[";
        int i;
        for(i = 0; i < len - 1; i++) {
            if(vals[i] != INT32_MIN) {
                ret.append(to_string(vals[i]));
                ret.append(", ");
            } else ret.append("null, ");
        }
        if(i < len) ret.append(to_string(vals[i]));
        ret.push_back(']');

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        vector<int> v;

        int L = 0, R = 0;
        while(true) {
            while(L < str.length() && str[L] != '+' && str[L] != '-' && (str[L] < '0' || str[L] == '[' || str[L] == ']')) L++;      // skip spaces
            if(L >= str.length()) break;
            R = L;
            while(R < str.length() && str[R] >= '0' && str[R] != '[' && str[R] != ']' || str[R] == '-' || str[R] == '+') R++;     // skip digits and English charactors
            string val = str.substr(L, R-L);
            if(val[0] > '9') v.push_back(INT32_MIN);   // TreeNode.val = null
            else v.push_back(atoi(val.c_str()));

            L = R;
        }

        if(v.size()) {
            TreeNode *ret = new TreeNode();
            assign(ret, v);
            return ret;
        } else {
            return NULL;
        }
    }

    TreeNode *assign(TreeNode *tree,vector<int>& v) {
        int len = v.size();
        if(!len) return NULL;
        tree->val = v[0];

        vector<TreeNode *> *pre_nodes, *nodes;
        pre_nodes = new vector<TreeNode *>;
        nodes = new vector<TreeNode *>;
        pre_nodes->push_back(tree);  // previos layer nodes
        int pre_start = 0;  // previous layer start index
        int pre_num = 1;    // previous layer node amount
        int start = 1;  // current layer start index
        int num;    // current layer node amount

        bool finished = false;
        while(!finished) {
            num = 0;
            for(int i = 0; i < pre_num; i++) {
                if((*pre_nodes)[i]) num += 2;
            }

            for(int i = 0; i < num; i++) {
                if(i+start == len) {
                    finished = true;
                    break;
                }
                if(v[start+i] != INT32_MIN) nodes->push_back(new TreeNode(v[start+i]));
                else nodes->push_back(NULL);
            }
            start = start + num;

            for(int i = 0, j = 0; i < pre_num && j < nodes->size(); i++) {
                if((*pre_nodes)[i]) {
                    (*pre_nodes)[i]->left = (*nodes)[j];
                    if(j+1 < nodes->size()) (*pre_nodes)[i]->right = (*nodes)[j+1];
                    j += 2;
                }
            }

            pre_nodes->clear();
            auto tmp = pre_nodes;
            pre_nodes = nodes;
            nodes = tmp;
            pre_num = num;
        }

        delete pre_nodes;
        delete nodes;
        return tree;
    }
};

int main() {
    Codec c;
    TreeNode tree;

    tree = "4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2";
    cout << c.deserialize("[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]")->toString() << endl;
    cout << c.serialize(&tree) << endl;
}