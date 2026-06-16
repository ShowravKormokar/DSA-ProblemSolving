// Leetcode problem 2 -> Add Two Numbers
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry > 0)
        {
            if (l1 != nullptr)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(carry % 10);
            carry /= 10;
            curr = curr->next;
        }

        return dummy.next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}

/*
TC: O(max(m, n)) where m and n are the lengths of the two linked lists.
SC: O(max(m, n)) for the output linked list.
*/