#include <iostream>
#include <stack>
#include <cstring>
#include <vector>

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        std::stack<char> stack1;

        for (char c : s)
        {
            if (!stack1.empty())
            {
                if (c == '#')
                {
                    stack1.pop();
                }
                else
                {
                    stack1.push(c);
                }
            }
            else if (stack1.empty() && c == '#')
            {
                continue;
            }
            else
            {
                stack1.push(c);
            }
        }
        
        std::stack<char> stack2;

        for (char c : t)
        {
            if (!stack2.empty())
            {
                if (c == '#')
                {
                    stack2.pop();
                }
                else
                {
                    stack2.push(c);
                }
            }
            else if (stack2.empty() && c == '#')
            {
                continue;
            }
            else
            {
                stack2.push(c);
            }
        }

        return stack1 == stack2;
    }
};

int main()
{
    std::string s = "ab#c";
    std::string t = "ad#c";

    Solution solution;
    bool flag = solution.backspaceCompare(s, t);
    
    std::cout << flag;

    return 0;
}