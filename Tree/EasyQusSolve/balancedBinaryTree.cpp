// Leetcode problem 110 -> Balanced Binary Tree
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }

private:
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = height(root->left);
        if (left == -1)
            return -1;

        int right = height(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;

    if (sol.isBalanced(root))
        cout << "Tree is Balanced." << endl;
    else
        cout << "Tree is NOT Balanced." << endl;

    return 0;
}

/*
      Example Tree:
            1
           / \
          2   3
         /
        4
      This tree is balanced.
  */

/*
TC: O(N) - We visit each node once to calculate the height and check balance.
SC: O(H) - The space complexity is O(H) due to the recursive call stack, where H is the height of the tree. In the worst case (skewed tree), H can be O(N).
*/
