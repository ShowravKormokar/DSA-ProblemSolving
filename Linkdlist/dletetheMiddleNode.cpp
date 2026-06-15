// Leetcode problem 2095 -> Delete the Middle Node of a Linked List
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node.
        slow->next = slow->next->next;
        return dummy.next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode *newHead = sol.deleteMiddle(head);

    // Print the modified linked list.
    ListNode *current = newHead;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}

/*
TC: O(n) - We traverse the linked list once to find the middle node and delete it.
SC: O(1) - We use a constant amount of extra space for the dummy node and the two pointers (slow and fast).
*/