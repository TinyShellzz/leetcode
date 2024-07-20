#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <unordered_map>
#include <unordered_set>
#include <vector>


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> umap;        // <origin_node, new_node>
        unordered_set<Node*> visited;
        Node* new_node = new Node(node->val);

        vector<Node*> *v1, *v2;
        v1 = new vector<Node*>();
        v2 = new vector<Node*>();
        v1->push_back(node);
        visited.insert(node);
        umap.insert({node, new_node});
        while(!v1->empty()) {
            while(!v1->empty()) {
                Node* parent = v1->back();
                v1->pop_back();
                Node* new_parent = umap[parent];
                vector<Node*>& neighbors = parent->neighbors;
                for(Node* n: neighbors) {
                    auto f = umap.find(n);
                    Node *new_n;
                    if(f == umap.end()) {
                        new_n = new Node(n->val);
                        umap.insert({n, new_n});
                    } else new_n = f->second;
                    new_parent->neighbors.push_back(new_n);

                    if(visited.find(n) == visited.end()) {
                        v2->push_back(n);   // if not visited
                        visited.insert(n);
                    }
                }
            }

            auto tmp = v1;
            v1 = v2;
            v2 = tmp;
            v2->clear();
        }
        delete v1;
        delete v2;

        return new_node;
    }
};

int main() {
    Solution so;

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};
    so.cloneGraph(n1);
}