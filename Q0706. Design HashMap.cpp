#include "utils/headers.h"

class MyHashMap {
    int capacity;
    int size;
    vector<map<int, int>> hash_map;
public:
    MyHashMap() {
        size = 0;
        capacity = 8;
        hash_map = vector<map<int, int>>(8, map<int, int>());
    }
    
    void put(int key, int value) {
        if(size == capacity) {
            capacity <<= 1;
            auto new_hash_map = vector<map<int, int>>(capacity, map<int, int>());
            for(auto m: hash_map) {
                for(auto e: m) {
                    int h = hash<int>()(e.first);
                    new_hash_map[h&(capacity-1)].insert(e);
                }
            }
            hash_map = new_hash_map;
        }

        int h = hash<int>()(key);
        auto& m = hash_map[h&(capacity-1)];
        auto f = m.find(key);
        if(f == m.end()) m.insert({key, value});
        else {
            f->second = value;
        }
        size++;
    }
    
    int get(int key) {
        int h = hash<int>()(key);
        auto& m = hash_map[h&(capacity-1)];
        auto f = m.find(key);
        return f==m.end() ? -1 : f->second;
    }
    
    void remove(int key) {
        int h = hash<int>()(key);
        auto& m = hash_map[h&(capacity-1)];
        auto f = m.find(key);
        if(f != m.end()) m.erase(f);
        size--;
    }
};

int main() {
    MyHashMap map;
    map.put(1,1);
    map.put(2,2);
    cout << map.get(1) << endl;
    cout << map.get(3) << endl;
    map.put(2, 1);
    cout << map.get(2) << endl;
    map.remove(2);
    cout << map.get(2) << endl;
}