#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int d, Node *n = nullptr) : data(d), next(n) {}
};

// Iterative: O(n) time, O(1) extra space
// Input: head of a list (may be nullptr)
// Output: head of the reversed list
Node *reverseIterative(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Recursive: O(n) time, O(n) space on the call stack
// Same input and output as the iterative version
Node *reverseRecursive(Node *node)
{
    if (node == nullptr || node->next == nullptr)
    {
        return node;
    }
    Node *newHead = reverseRecursive(node->next);
    node->next->next = node;
    node->next = nullptr;
    return newHead;
}

void print(const Node *head)
{
    for (const Node *it = head; it != nullptr; it = it->next)
    {
        std::cout << it->data << " -> ";
    }
    std::cout << "null\n";
}

void freeList(Node *head)
{
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }
}

int main()
{
    // Build 1 -> 2 -> 3 -> 4
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4))));

    std::cout << "Original:          ";
    print(head);

    head = reverseIterative(head);
    std::cout << "After iterative:   ";
    print(head);

    // head = reverseRecursive(head);
    // std::cout << "After recursive:   ";
    // print(head);

    freeList(head);

    // Edge case: empty list
    Node *empty = nullptr;
    empty = reverseIterative(empty);
    std::cout << "Empty list:        ";
    print(empty);

    // Edge case: single element
    // Node *single = new Node(42);
    // single = reverseIterative(single);
    // std::cout << "Single element:    ";
    // print(single);
    // freeList(single);

    return 0;
}