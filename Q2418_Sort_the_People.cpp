#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include "utils/to_string.h"

class Solution {
    vector<string> *names;
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        this->names = &names;
        sort(heights, 0, heights.size()-1);

        return names;
    }

    void sort(vector<int>& heights, int start, int stop) {
        if(start >= stop) return;
        int pivot = heights[start];

        int L = start, R = stop;
        while(true) {
            while(R > L && heights[R] <= pivot) R--;
            if(R == L) break;
            swap(heights[L], heights[R]);
            swap((*names)[L], (*names)[R]);
            L++;

            while(R > L && heights[L] > pivot) L++;
            if(R == L) break;
            swap(heights[L], heights[R]);
            swap((*names)[L], (*names)[R]);
            R--;
        }

        sort(heights, start, L - 1);
        sort(heights, L+1, stop);
    }

    template <typename T>
    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
};

int main() {
    Solution so;
    vector<string> names;
    vector<int> heights;

    cout << to_string(so.sortPeople(names = {"Mary","John","Emma"}, heights = {180,165,170})) << endl;
    cout << to_string(so.sortPeople(names = {"Alice","Bob","Bob"}, heights = {155,185,150})) << endl;
}