#pragma once
#include <vector>
using namespace std;

// return the first element that element < target is false.
int lower_bound(vector<int>& arr, int target) {
    int len = arr.size();

    int left = 0, right = len-1;
    while(left < right) {
        int mid = (left+right)/2;

        if(target <= arr[mid]) {   // target is in the left part of arr
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

// return the first element that element <= target is false.
int upper_bound(vector<int>& arr, int target) {
    int len = arr.size();

    int left = 0, right = len-1;
    while(left < right) {
        int mid = (left+right)/2;

        if(target < arr[mid]) {    // difference of lower_bound and upper_bound function
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

void quick_sort(vector<int>& arr, int start, int stop) {
    if(start >= stop) return;

    auto swap = [](int& a, int& b){ int tmp = a; a = b; b = tmp; };
    int pivot = arr[start];
    int left = start, right = stop;
    while(true) {
        while(left < right && pivot < arr[right]) right--;  // move element that greater than pivot to the right
        if(left == right) break;
        swap(arr[left], arr[right]);

        while(left < right && pivot >= arr[left]) left++;   // move element that less or equal to pivot to the left
        if(left == right) break;
        swap(arr[left], arr[right]);
    }

    quick_sort(arr, start, left-1);     // sort left part recursively
    quick_sort(arr, left+1, stop);      // sort right part recursively
}