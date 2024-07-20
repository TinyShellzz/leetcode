#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;
#include <unordered_map>

class m_ListNode {
public:
    int key;
    int value;
    m_ListNode *next;
    m_ListNode *prev;
    m_ListNode(int key, int value): key(key), value(value), next(NULL), prev(NULL){}
};

class m_deque {
public:
    m_ListNode *dummy_head;
    m_ListNode *end;
    m_deque(){
        dummy_head = new m_ListNode(0, 0);
        end = new m_ListNode(0, 0);
        dummy_head->next = end;
        end->prev = dummy_head;
    }
    ~m_deque() {
        m_ListNode *cur = dummy_head;
        while(cur) {
            m_ListNode *next = cur->next;
            delete cur;
            cur = next;
        }
    }
    void erase(m_ListNode *n) {
        m_ListNode *prev = n->prev;
        m_ListNode *next = n->next;
        next->prev = prev;
        prev->next = next;
        delete n;
    }
    void pop_front() {
        m_ListNode *first = dummy_head->next;
        if(first == end) return;

        erase(first);
    }
    void push_back(m_ListNode *n) {
        m_ListNode *last = end->prev;
        end->prev = n;
        last->next = n;
        n->prev = last;
        n->next = end;
    }
    m_ListNode* back() {
        return end->prev;
    }
    m_ListNode* front() {
        return dummy_head->next;
    }
};

class LRUCache {
    unordered_map<int, m_ListNode *> umap;    // <key, the Node before>
    m_deque *dq;
    int capacity;
    int size;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        dq = new m_deque();
        size = 0;
    }
    
    int get(int key) {
        auto f = umap.find(key);
        if(f == umap.end()) return -1;

        int value = f->second->value;
        put(key, value);
        return value;
    }
    
    void put(int key, int value) {
        auto f = umap.find(key);
        if(f != umap.end()) {
            dq->erase(f->second);
            dq->push_back(new m_ListNode(key, value));
            umap[key] = dq->back();
        }else if(size == capacity) {
            umap.erase(umap.find(dq->front()->key));
            dq->pop_front();
            
            dq->push_back(new m_ListNode(key, value));
            umap[key] = dq->back();
        } else {
            dq->push_back(new m_ListNode(key, value));
            umap[key] = dq->back();
            size++;
        }
    }
};

int main() {
    LRUCache lRUCache = LRUCache(1);
    lRUCache.put(2, 1);
    cout << lRUCache.get(2) << endl;
    cout << lRUCache.get(3) << endl;
    cout << lRUCache.get(2) << endl;
    cout << lRUCache.get(1) << endl;
    lRUCache.put(5, 5);
    cout << lRUCache.get(1) << endl;
    cout << lRUCache.get(2) << endl;
    cout << lRUCache.get(3) << endl;
    cout << lRUCache.get(4) << endl;
    cout << lRUCache.get(5) << endl;

}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */