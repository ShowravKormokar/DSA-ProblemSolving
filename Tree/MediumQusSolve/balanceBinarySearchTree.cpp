// leetcode problem 1382 -> Balance a Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    vector<int> arr;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    TreeNode *build(int l, int r)
    {
        if (l > r)
            return nullptr;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);
        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        inorder(root);
        return build(0, arr.size() - 1);
    }
};

// Function to insert into BST
TreeNode *insertBST(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Print inorder traversal
void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    // Create an unbalanced BST
    TreeNode *root = nullptr;
    vector<int> values = {2, 1, 3};

    for (int v : values)
        root = insertBST(root, v);

    cout << "Inorder of Original BST: ";
    printInorder(root);
    cout << endl;

    Solution sol;
    TreeNode *balancedRoot = sol.balanceBST(root);

    cout << "Inorder of Balanced BST: ";
    printInorder(balancedRoot);
    cout << endl;

    return 0;
}

/*
TC: O(N) where N is the number of nodes in the BST. We perform an inorder traversal to store the nodes in a sorted array, which takes O(N) time. Then, we build a balanced BST from the sorted array, which also takes O(N) time.
SC: O(N) for storing the values of the nodes in the array during the inorder traversal
*/