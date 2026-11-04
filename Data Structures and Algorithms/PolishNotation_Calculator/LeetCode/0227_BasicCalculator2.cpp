#include <iostream>
#include <stack>
#include <string>

class Solution
{
public:
    long long calc(const char op, long long num1, long long num2)
    {
        if (op == '+')
            return num1 + num2;
        else if (op == '-')
            return num2 - num1;
        else if (op == '*')
            return num1 * num2;
        else
            return num2 / num1;
    }

    int priority(const char op)
    {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '^')
            return 3;
        else
            return 0;
    }

    long long calculate(std::string &s)
    {
        std::stack<long long> numbers;
        std::stack<char> operators;
        int length = s.length();
        bool expectUnary = true;

        for (int i = 0; i < length; i++)
        {
            if (std::isspace(s[i]))
            {
                continue;
            }

            if (std::isdigit(s[i]))
            {
                long long num = 0;
                while (i < s.length() && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numbers.push(num);
                i--;
                expectUnary = false;
            }
            else if (s[i] == '(')
            {
                operators.push(s[i]);
                expectUnary = true;
            }
            else if (s[i] == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    long long num1 = numbers.top();
                    numbers.pop();
                    long long num2 = numbers.top();
                    numbers.pop();
                    const char op = operators.top();
                    operators.pop();

                    numbers.push(calc(op, num1, num2));
                }

                if (!operators.empty())
                {
                    operators.pop();
                }

                expectUnary = false;
            }
            else
            {
                if (s[i] == '-' && expectUnary)
                {
                    numbers.push(0); // Превръщаме "-X" в "0 - X"
                }
                else
                {
                    while (!operators.empty() && priority(operators.top()) >= priority(s[i]))
                    {
                        long long num1 = numbers.top();
                        numbers.pop();
                        long long num2 = numbers.top();
                        numbers.pop();
                        const char op = operators.top();
                        operators.pop();

                        numbers.push(calc(op, num1, num2));
                    }
                }
                operators.push(s[i]);
                expectUnary = true;
            }
        }

        while (!operators.empty())
        {
            long long num1 = numbers.top();
            numbers.pop();
            long long num2 = numbers.top();
            numbers.pop();
            const char op = operators.top();
            operators.pop();

            numbers.push(calc(op, num1, num2));
        }

        return numbers.top();
    }
};

int main()
{
    std::string str = " 2-1 + 2 ";

    Solution solution;
    long long result = solution.calculate(str);

    std::cout << result << std::endl;

    return 0;
}