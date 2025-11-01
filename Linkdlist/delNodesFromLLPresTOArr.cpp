// Leetcode problem 3217 -> Delete nodes from linked list present in the array
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        // Step 1: Create an unordered_set from nums for quick lookup
        unordered_set<int> numsSet(nums.begin(), nums.end());

        // Step 2: Create a dummy node that points to head
        ListNode dummy(0, head);

        // Step 3: Use pointer to traverse and delete matching nodes
        ListNode *curr = &dummy;
        while (curr->next != nullptr)
        {
            if (numsSet.count(curr->next->val))
            {
                // Delete this node (skip it)
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next; // move to next
            }
        }

        // Step 4: Return the new head (dummy.next)
        return dummy.next;
    }
};

// Helper function to print linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
ListNode *createList(vector<int> values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *curr = head;
    for (int i = 1; i < values.size(); i++)
    {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> nums = {2, 4}; // nodes to delete

    ListNode *head = createList(arr);

    cout << "Original list: ";
    printList(head);

    Solution s;
    head = s.modifiedList(nums, head);

    cout << "Modified list: ";
    printList(head); // Output: 1 3 5

    return 0;
}

/*
TC: O(nums + head)
SC: O(nums)
*/