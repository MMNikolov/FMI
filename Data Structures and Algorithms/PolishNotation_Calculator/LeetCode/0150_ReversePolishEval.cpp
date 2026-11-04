#include <iostream>
#include <stack>
#include <vector>

class Solution
{
public:
    int calc(std::string &op, int num1, int num2)
    {
        if (op == "+")
            return num1 + num2;
        else if (op == "-")
            return num2 - num1;
        else if (op == "*")
            return num1 * num2;
        else
            return num2 / num1;
    }

    int priority(std::string &op)
    {
        if (op == "+" || op == "-")
            return 1;
        if (op == "*" || op == "/")
            return 2;

        return 0;
    }

    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> numbers;
        std::stack<std::string> operators;

        for (std::string &el : tokens)
        {
            if (el == "+" || el == "-" || el == "*" || el == "/")
            {
                while (!operators.empty() && (priority(operators.top()) >= priority(el)))
                {
                    int num1 = numbers.top();
                    numbers.pop();
                    int num2 = numbers.top();
                    numbers.pop();
                    std::string op = operators.top(); operators.pop();

                    numbers.push(calc(op, num1, num2));
                }

                operators.push(el);
            }
            else
            {
                numbers.push(std::stoi(el));
            }
        }

        while (!operators.empty())
        {
            int num1 = numbers.top();
            numbers.pop();
            int num2 = numbers.top();
            numbers.pop();
            std::string op = operators.top(); operators.pop();

            numbers.push(calc(op, num1, num2));
        }

        return numbers.top();
    }
};

int main()
{
    std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    Solution solution;
    int result = solution.evalRPN(tokens);

    std::cout << result << std::endl;

    return 0;
}