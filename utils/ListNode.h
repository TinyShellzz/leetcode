#pragma once
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(initializer_list<int> list): next(nullptr) { *this = list; }
    ListNode& operator=(vector<int>& v){
        this->clear();
        int len = v.size();
        if(len == 0) { return *this; }
        this->val = v[0];
        this->next = NULL;

        ListNode *cur = this;
        for(int i = 1; i < len; i++) {
            cur->next = new ListNode(v[i]);
            cur = cur->next;
            cur->next = NULL;
        }

        return *this;
    }

    ListNode& operator=(string& str) {
        this->clear();
        int len = str.size();
        int L = 0, R = 0;
        vector<int> res = {};

        while(true) {
            while(L < len && (str[L] < '0' || str[L] > '9')) L++;   // skip that is not digit
            if(L == len) break;
            R = L;

            while(R < len && (str[R] >= '0' && str[R] <= '9')) R++; // skip that is digit
            string val = str.substr(L, R-L);
            res.push_back(atoi(val.c_str()));
            L = R;
        }

        *this = res;
        return *this;
    }

    ListNode& operator=(initializer_list<int> list){
        vector<int> v = list;
        *this = v;
        return *this;
    }

    string toString(){
        if(!this) return "[]";
        string str = "[";

        ListNode *cur = this;
        while(cur->next) {
            str.append(to_string(cur->val));
            str.append(", ");
            cur = cur->next;
        }

        str.append(to_string(cur->val));
        str.push_back(']');

        return str;
    }

    // make this LinkList empty
    void clear(){
        ListNode *cur = this->next;
        ListNode *tmp = cur;
        while(cur) {
            tmp = cur->next;
            free(cur);
            cur = tmp;
        }

        this->next = NULL;
    }

    ~ListNode() {
    }
};