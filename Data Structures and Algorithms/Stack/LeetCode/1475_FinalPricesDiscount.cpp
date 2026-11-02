#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        std::stack<int> stack;

        int count = prices.size();
        int waitingIndex;
        for (int i = 0; i < count; i++)
        {
            while (!stack.empty() && prices[i] <= prices[stack.top()])
            {
                waitingIndex = stack.top();
                stack.pop();

                prices[waitingIndex] -= prices[i];
            }
            
            stack.push(i);
        }
        
        return prices;
    }
};

int main()
{
    std::vector<int> prices {8, 4, 6, 2, 3};

    Solution solution;
    std::vector<int> newArr = solution.finalPrices(prices);

    int count = newArr.size();
    for (unsigned i = 0; i < count; i++)
    {
        std::cout << newArr[i] << ' ';
    }
    
    return 0;
}