#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <queue>

struct cmp_less {
    bool operator()(int const a, int const b) const {
        return a > b;
    }
};
class MedianFinder {
    int size;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, cmp_less> pq2;

public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        if(!pq1.size()) {
            pq1.push(num);
            return;
        }

        int top1 = pq1.top();
        if(num < top1) {
            if(pq1.size() < (size+1)/2) {
                pq1.push(num);
            } else {
                pq1.push(num);
                pq2.push(pq1.top());
                pq1.pop();
            }
        } else {
            if(pq2.size() < size/2) {
                pq2.push(num);
            } else {
                pq2.push(num);
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
    }
    
    double findMedian() {
        return size%2 ? pq1.top() : (double)(pq1.top()+pq2.top())/2;
    }
};

int main() {
    MedianFinder medianFinder = MedianFinder();
medianFinder.addNum(40);    // arr = [1]
medianFinder.addNum(12);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(16);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
}
