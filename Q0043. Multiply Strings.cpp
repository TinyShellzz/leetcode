#include "utils/headers.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        string ret = "0";
        for(int i = 1; i <= len1; i++) {
            string cur = my_multiply(num1[len1-i]-'0', num2);
            if(cur != "0") cur.append(i-1, '0');
            ret = ret.size()<cur.size() ? plus(ret, cur) : plus(cur, ret);
        }

        return ret;
    }

    string plus(string& a, string& b) {
        int len1 = a.size(), len2 = b.size();
        int carry = 0;
        string ret = string(len2+1, '0');

        int i = 1;
        for(; i <= len1; i++) {
            int sum = carry+a[len1-i]+b[len2-i]-2*'0';
            ret[len2+1-i] = sum%10+'0';
            if(sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        for(; i <= len2; i++) {
            int sum = carry+b[len2-i]-'0';
            ret[len2+1-i] = sum%10+'0';
            if(sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        ret[0] = carry+'0';
        int j = 0;
        while(j < len2 && ret[j] == '0') j++;
        string ret_ = ret.substr(j, len2+1-j);
        return ret_;
    }

    string my_multiply(int a, string num) {
        int len = num.size();
        int i = 1;
        string ret = "0";
        for(; i <= len; i++) {
            string cur = to_string(a*(num[len-i]-'0'));
            if(cur != "0") cur.append(i-1, '0');
            ret = ret.size()<cur.size() ? plus(ret, cur) : plus(cur, ret);
        }

        return ret;
    }
};

int main() {
    Solution so;
    string s1, s2;

    // cout << so.plus(s1 = "123", s2 = "45678") << endl;
    // cout << so.mlutiply(3, s1 = "456");
    cout << so.multiply(s1 = "17039", s2 = "7218") << endl;
}