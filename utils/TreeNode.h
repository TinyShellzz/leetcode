#pragma once
#include <vector>
#include <string>
#ifndef null_node
    #define null_node INT32_MIN
#endif

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(const char* str) { this->left=NULL; this->right=NULL; string s = string(str); *this = s; }
    TreeNode& operator=(vector<int>& v) {
        int len = v.size();
        if(!len) return *this;
        this->val = v[0];

        vector<TreeNode *> *pre_nodes, *nodes;
        pre_nodes = new vector<TreeNode *>;
        nodes = new vector<TreeNode *>;
        pre_nodes->push_back(this);  // previos layer nodes
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
                if(v[start+i] != null_node) nodes->push_back(new TreeNode(v[start+i]));
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
        return *this;
    }

    TreeNode& operator=(string const& str) {
        vector<int> v;

        int L = 0, R = 0;
        while(true) {
            while(L < str.length() && str[L] != '+' && str[L] != '-' && (str[L] < '0' || str[L] == '[' || str[L] == ']')) L++;      // skip spaces
            if(L >= str.length()) break;
            R = L;
            while(R < str.length() && str[R] >= '0' && str[R] != '[' && str[R] != ']' || str[R] == '-' || str[R] == '+') R++;     // skip digits and English charactors
            string val = str.substr(L, R-L);
            if(val[0] > '9') v.push_back(null_node);   // TreeNode.val = null
            else v.push_back(atoi(val.c_str()));

            L = R;
        }

        *this = v;
        return *this;
    }

    TreeNode& operator=(initializer_list<int> list) {
        vector<int> v = list;
        *this = v;
        return *this;
    }

    string toString(){
        if(!this) return "[]";
        vector<TreeNode *> *pre_nodes, *nodes;
        pre_nodes = new vector<TreeNode *>;
        nodes = new vector<TreeNode *>;
        pre_nodes->push_back(this);

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
                    vals.push_back(null_node);
                }
            }

            pre_nodes->clear();
            auto tmp = pre_nodes;
            pre_nodes = nodes;
            nodes = tmp;
        }

        int len = vals.size();
        while(len > 0 && vals[len-1] == null_node) len--;
        
        string ret = "[";
        int i;
        for(i = 0; i < len - 1; i++) {
            if(vals[i] != null_node) {
                ret.append(to_string(vals[i]));
                ret.append(", ");
            } else ret.append("null, ");
        }
        if(i < len) ret.append(to_string(vals[i]));
        ret.push_back(']');

        return ret;
    }
};