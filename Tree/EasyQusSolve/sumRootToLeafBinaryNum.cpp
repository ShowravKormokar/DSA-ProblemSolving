// Leetcode problem 1022 -> Sum of Root To Leaf Binary Numbers
#include <bits/stdc++.h>
using namespace std;

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
    int sumRootToLeaf(TreeNode *root)
    {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int val, int &ans)
    {
        if (root == nullptr)
            return;
        val = val * 2 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            ans += val;
        dfs(root->left, val, ans);
        dfs(root->right, val, ans);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution sol;
    cout << sol.sumRootToLeaf(root) << endl; // Output: 22

    return 0;
}

/*
TC: O(N) where N is the number of nodes in the tree, as we visit each node once.
SC: O(H) where H is the height of the tree, due to the recursive call stack. In the worst case (skewed tree), H can be equal to N, leading to O(N) space complexity. In a balanced tree, H would be log(N), resulting in O(log(N)) space complexity.
*/