#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <queue>
#include <algorithm>

// using monomatic stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        vector<pair<int, double>> cars;    // (posi, time needed to reach target)
        
        for(int i = 0; i < len; i++) {
            cars.push_back({position[i], (double)(target-position[i])/speed[i]});
        }
        sort(cars.begin(), cars.end());

        int ans = 0;
        double pre_time = INT32_MIN;
        for(int i = len-1; i >= 0;) {
            while(i >= 0 && pre_time >= cars[i].second) i--;
            if(i < 0) break;
            pre_time = cars[i].second;
            ans++;
            i--;
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<int> position, speed;

    cout << so.carFleet(12, position = {10,8,0,5,3}, speed = {2,4,1,1,3}) << endl;
}