// Leetcode problem 61 -> Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        ListNode *tail;
        int length = 1;
        for (tail = head; tail->next; tail = tail->next)
            ++length;
        tail->next = head; // Circle the list.

        const int t = length - k % length;
        for (int i = 0; i < t; ++i)
            tail = tail->next;
        ListNode *newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode *newHead = sol.rotateRight(head, k);

    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}

/*
TC: O(n) - We traverse the list to find its length and then again to find the new tail.
SC: O(1) - We perform the operations in-place without using any additional data structures
*/