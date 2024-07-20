#include "utils/headers.h"

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int len = words.size();
        int left = 0, right = 0;
        int sum;
        vector<string> ans;
        while (true)
        {
            sum = words[right].size();
            right++;
            while (right < len && sum <= maxWidth)
            {
                sum += words[right].size() + 1;
                right++;
            }
            if (right == len)
            {
                if (sum <= maxWidth)
                {
                    string s;
                    for (int i = left; i < right - 1; i++)
                    {
                        s.append(words[i]);
                        s.push_back(' ');
                    }
                    s.append(words[right - 1]);
                    int spaces = maxWidth - s.size();
                    if (spaces)
                        s.append(spaces, ' ');
                    ans.push_back(s);
                    break;
                }
            }

            right--;
            sum -= words[right].size() + 1;
            int spaces = maxWidth - sum;
            int blank = right - left - 1;
            if (blank == 0)
            {
                string s = words[left];
                int spaces = maxWidth - s.size();
                if (spaces)
                    s.append(spaces, ' ');
                ans.push_back(s);
            }
            else
            {
                int u = spaces / blank;
                int v = spaces % blank;
                string s;
                for (int i = left; i < right - 1; i++)
                {
                    s.append(words[i]);
                    if (v != 0)
                    {
                        s.append(u + 2, ' ');
                        v--;
                    }
                    else
                    {
                        s.append(u + 1, ' ');
                    }
                }
                s.append(words[right - 1]);
                ans.push_back(s);
            }

            left = right;
        }

        return ans;
    }
};

int main()
{
    Solution so;
    vector<string> words;

    cout << to_string(so.fullJustify(words = {"This", "is", "an", "example", "of", "text", "justification."}, 16)) << endl;
}