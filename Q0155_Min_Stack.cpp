#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class MinStack {
private:
  vector<int> *stack;
  vector<int> *min_stack;
  
public:
    MinStack() {
        stack = new vector<int>();
        min_stack = new vector<int>();
    }
    
    void push(int val) {
        stack->push_back(val);
        int cur_min = val;
        if(min_stack->size()) {
          cur_min = min(cur_min, (*min_stack)[min_stack->size()-1]);
        }
        min_stack->push_back(cur_min);
    }
    
    void pop() {
        stack->pop_back();
        min_stack->pop_back();
    }
    
    int top() {
        return (*stack)[stack->size()-1];
    }
    
    int getMin() {
        return (*min_stack)[stack->size()-1];
    }
};


int main() {
    MinStack minStack = MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
}