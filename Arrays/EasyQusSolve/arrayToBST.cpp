// Leetcode problem 108 -> Convert sorted array into Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

TreeNode *buildBST(vector<int> &nums, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> nums)
{
    return buildBST(nums, 0, nums.size() - 1);
}

void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode *root = sortedArrayToBST(nums);

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root); // Output: -10, -3, 0, 5, 9
    cout << endl;

    return 0;
}

/*
        0
      /   \
   -10     5
   / \    /  \
null -3 null  9
*/