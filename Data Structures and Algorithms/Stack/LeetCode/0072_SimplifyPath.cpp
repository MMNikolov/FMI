#include <iostream>
#include <stack>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<char> str;
        
        for (char c : path)
        {
               
        }
        

        return path;
    }
};

int main()
{
    std::string str = "/.../a/../b/c/../d/./";

    Solution solution;
    std::string newStr = solution.simplifyPath(str); 

    std::cout << newStr << std::endl;

    return 0;
}