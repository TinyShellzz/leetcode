#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        
        for(string str: tokens) {
          if(isOperator(str)) {
            int l = stack.size();
            int operant1 = stack[l-2];
            int operant2 = stack[l-1];
            int res = excute(str, operant1, operant2);
            stack.pop_back(); stack.pop_back();
            stack.push_back(res);
          } else {
            stack.push_back(atoi(str.c_str()));
          }
        }
        
        return stack[0];
    }

    bool isOperator(string str) {
        if(str == "+" || str == "-" || str == "*" || str == "/") return true;
        return false;
    }

    int excute(string op, int operant1, int operant2){
        if(op == "+") return operant1+operant2;
        if(op == "-") return operant1-operant2;
        if(op == "*") return operant1*operant2;
        return operant1/operant2;
    }
};

int main() {
    Solution so;
    vector<string> input;

    cout << so.evalRPN(input = {"2","1","+","3","*"}) << endl;
    cout << so.evalRPN(input = {"4","13","5","/","+"}) << endl;
    cout << so.evalRPN(input = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}) << endl;
}