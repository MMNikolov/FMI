#include <iostream>
#include <stack>
#include <vector>
#include <queue>

class Solution
{
public:
    int countStudents(std::vector<int> &students, std::vector<int> &sandwiches)
    {
        std::queue<int> queue;
        std::stack<int> stack;

        int count = students.size();
        for (int i = 0; i < count; i++)
        {
            queue.push(students[i]);
        }

        for (int i = count - 1; i >= 0; i--)
        {
            stack.push(sandwiches[i]);
        }

        int counter = 0;
        while (!stack.empty())
        {
            if ((queue.front() == stack.top()))
            {
                queue.pop();
                stack.pop();
                counter = 0;
            }
            else
            {
                int item = queue.front();
                queue.pop();
                queue.push(item);
                counter++;
            }

            if (counter >= count)
            {
                break;
            }
        }

        return queue.size();
    }
};

int main()
{
    std::vector<int> students{1, 1, 1, 0, 0, 1};
    std::vector<int> sandwiches{1, 0, 0, 0, 1, 1};

    Solution solution;
    int studentsCount = solution.countStudents(students, sandwiches);

    std::cout << studentsCount;

    return 0;
}