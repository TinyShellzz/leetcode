#include "utils/headers.h"

class RandomizedSet {
    unordered_map<int, int> umap;   // <val, index>
    vector<int> data;
    int seed = 0;   // rand seed

public:
    bool insert(int val) {
        if(umap.find(val) != umap.end()) return false;

        data.push_back(val);
        umap[val] = data.size()-1;
        return true;
    }

    bool remove(int val) {
        auto f = umap.find(val);
        if(f == umap.end()) return false;

        if(val != data.back()) {
            swap(data[f->second], data[data.size()-1]);
            umap[data[f->second]] = f->second;
        }
        data.pop_back();
        umap.erase(f);
        
        return true;
    }

    int getRandom(){
        srand(seed++);
        int i = rand()%data.size();
        return data[i];
    }
};

int main() {
    RandomizedSet randomizedSet = RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
}