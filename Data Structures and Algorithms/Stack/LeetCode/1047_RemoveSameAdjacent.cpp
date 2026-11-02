#include <iostream>
#include <stack>
#include <algorithm> 
#include <string>

class Solution
{
public:
    std::string removeDuplicates(std::string s)
    {
        std::stack<char> stack;
        std::string newStr;

        for (char c : s)
        {
            if (!stack.empty() && stack.top() == c)
            {
                stack.pop();
            }
            else
            {
                stack.push(c);
            }
        }

        while (!stack.empty())
        {
            newStr += stack.top();
            stack.pop();
        }

        std::reverse(newStr.begin(), newStr.end());

        return newStr;
    }
};

int main()
{
    std::string str = "azxxzy";

    Solution solution;
    std::string newStr = solution.removeDuplicates(str);

    std::cout << newStr << "\n"; // Output: "ay"

    return 0;
}