#include <iostream>
#include <stack>

struct MoveState
{
    int n;
    char source;
    char target;
    char aux;
};

void hanoi_iterative_stack(int n, char source, char target, char aux)
{
    std::stack<MoveState> stack;

    // Добавяме първоначалното състояние
    stack.push({n, source, target, aux});

    while (!stack.empty())
    {
        MoveState current = stack.top();
        stack.pop();

        if (current.n == 1)
        {
            // Базов случай
            std::cout << "Преместване на диск от " << current.source
                      << " към " << current.target << "\n";
        }
        else
        {
            // Добавяме в стека в обратен ред на изпълнението (LIFO)

            // Стъпка 3: преместване на n-1 от помощната към целевата
            stack.push({current.n - 1, current.aux, current.target, current.source});

            // Стъпка 2: преместване на 1 диск от началната към целевата
            stack.push({1, current.source, current.target, current.aux});

            // Стъпка 1: преместване на n-1 от началната към помощната
            stack.push({current.n - 1, current.source, current.aux, current.target});
        }
    }
}

int main()
{
    // Тест с 3 диска
    hanoi_iterative_stack(3, 'A', 'C', 'B');
    return 0;
}