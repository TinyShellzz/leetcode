#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;
#include <unordered_map>
#include <vector>
#include <algorithm>

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> *data;

public:
    TimeMap() {
        data = new unordered_map<string, vector<pair<int, string>>>();
    }
    
    void set(string key, string value, int timestamp) {
        (*data)[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto const& f = data->find(key);
        if(f == data->end()) return "";
        auto& vec = f->second;
        if(timestamp < vec.front().first) return "";

        auto low = lower_bound(vec.begin(), vec.end(), pair<int, string>(timestamp, ""));
        if(low == vec.end()) return vec.back().second;
        if(low->first == timestamp) return low->second;

        return (--low)->second;
    }
};

int main() {
    TimeMap timeMap = TimeMap();
    timeMap.set("love","high",10);
    timeMap.set("love","low",20);
    cout << timeMap.get("love",15) << endl;         // return "bar"

    vector<int> arr = {10, 20};
    cout << *lower_bound(arr.begin(), arr.end(), 14) << endl;
 
}