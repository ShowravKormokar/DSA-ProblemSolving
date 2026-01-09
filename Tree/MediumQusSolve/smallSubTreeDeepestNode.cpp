// Leetcode problem 865 -> Smallest Subtree with all the Deepest Nodes
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper struct for DFS
struct T
{
    TreeNode *lca;
    int depth;
};

class Solution
{
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return dfs(root).lca;
    }

private:
    T dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {nullptr, 0};

        const T left = dfs(root->left);
        const T right = dfs(root->right);

        if (left.depth > right.depth)
            return {left.lca, left.depth + 1};
        if (left.depth < right.depth)
            return {right.lca, right.depth + 1};
        return {root, left.depth + 1};
    }
};

// Helper function to print tree node
void printNode(TreeNode *node)
{
    if (node)
        cout << "LCA Node Value: " << node->val << endl;
    else
        cout << "Tree is empty or no LCA found." << endl;
}

int main()
{
    // Build a sample tree
    //       3
    //      / \
    //     5   1
    //    / \   \
    //   6   2   8
    //      / \
    //     7   4

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    Solution sol;
    TreeNode *lcaNode = sol.subtreeWithAllDeepest(root);
    printNode(lcaNode); // Should print 2 because nodes 7 and 4 are deepest

    return 0;
}
