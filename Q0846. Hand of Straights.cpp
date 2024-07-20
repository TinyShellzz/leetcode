#include "utils/headers.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> coutMap;

        for(int i = 0; i < hand.size(); i++) {
            coutMap[hand[i]]++;
        }

        for(auto it = coutMap.begin(); ;) {
            while(it != coutMap.end() && it->second == 0) it++;
            if(it == coutMap.end()) break;
            auto j = it;
            auto start = j->first;
            for(int i = 0; i < groupSize; i++) {
                if(j == coutMap.end() || j->second == 0) return false;
                if(j->first != i + start) return false;
                j->second--;
                j++;
            }
        }

        return true;
    }
};

int main() {
    Solution so;
    vector<int> hand;

    cout << so.isNStraightHand(hand = {1,2,3,6,2,3,4,7,8}, 3) << endl;
}