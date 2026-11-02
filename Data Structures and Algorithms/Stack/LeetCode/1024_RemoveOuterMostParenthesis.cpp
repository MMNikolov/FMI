#include <iostream>
#include <stack>
#include <cstring>

class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::stack<char> stack;
        std::string newStr;

        for (char c : s)
        {
            if (c == '(')
            {
                if (!stack.empty())
                {
                    stack.push(c);
                    newStr.push_back(c);
                }
                else
                {
                    stack.push(c);
                }
            }
            else
            {
                stack.pop();

                if (stack.empty())
                {
                    continue;
                }
                else
                {
                    newStr.push_back(c);
                }
            }
        }
        
        return newStr;
    }
};

int main()
{
    std::string s = "(()())(())(()(()))";

    Solution solution;
    std::string newStr = solution.removeOuterParentheses(s);

    std::cout << newStr;

    return 0;
}