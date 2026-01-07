// Leetcode problem 1339. Maximum Product of Splitted Binary Tree
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
    int maxProduct(TreeNode *root)
    {
        constexpr int kMod = 1'000'000'007;
        long ans = 0;
        vector<int> allSums;
        const long totalSum = treeSum(root, allSums);

        for (const long sum : allSums)
            ans = max(ans, sum * (totalSum - sum));

        return ans % kMod;
    }

private:
    int treeSum(TreeNode *root, vector<int> &allSums)
    {
        if (root == nullptr)
            return 0;

        const int leftSum = treeSum(root->left, allSums);
        const int rightSum = treeSum(root->right, allSums);
        const int sum = root->val + leftSum + rightSum;
        allSums.push_back(sum);
        return sum;
    }
};

int main()
{
    /*
        Example Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Total sum = 21
        Best split -> subtree sum = 11 and 10
        Product = 110
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    Solution sol;
    cout << "Maximum Product: " << sol.maxProduct(root) << endl;

    return 0;
}

/*
TC: O(N) where N is the number of nodes in the binary tree. We traverse each node once to compute the total sum and again to find the maximum product.
SC: O(N) for storing the sums of all subtrees in the allSums vector
*/