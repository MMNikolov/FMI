#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

class Solution
{
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> stack;
        
        stack.push(-1);

        int maxLen = 0;
        int strLength = s.length();
        for (int i = 0; i < strLength; ++i)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else
            {
                stack.pop();

                if (stack.empty())
                {
                    stack.push(i);
                }
                else
                {
                    maxLen = std::max(maxLen, i - stack.top());
                }
            }
        }
        
        return maxLen;
    }
};

int main()
{
    std::string s = "()(()";

    Solution solution;
    int res = solution.longestValidParentheses(s);

    std::cout << res << "\n";

    return 0;
}