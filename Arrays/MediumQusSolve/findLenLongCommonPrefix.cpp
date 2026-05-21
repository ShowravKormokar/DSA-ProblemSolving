// Leetcode problem 3043 -> Find the Length of the Longest Common Prefix
#include <bits/stdc++.h>
using namespace std;

// Not understanding the problem statement properly, so using Trie data structure to find the longest common prefix of two arrays of integers. The longest common prefix is the longest sequence of digits that appear at the beginning of both numbers in the two arrays.🚨☠️❌

struct TrieNode
{
    vector<shared_ptr<TrieNode>> children;
    TrieNode() : children(10) {}
};

class Trie
{
public:
    void insert(const string &word)
    {
        shared_ptr<TrieNode> node = root;
        for (const char c : word)
        {
            const int i = c - '0';
            if (node->children[i] == nullptr)
                node->children[i] = make_shared<TrieNode>();
            node = node->children[i];
        }
    }

    int search(const string &word)
    {
        int prefixLength = 0;
        shared_ptr<TrieNode> node = root;
        for (const char c : word)
        {
            const int i = c - '0';
            if (node->children[i] == nullptr)
                break;
            node = node->children[i];
            ++prefixLength;
        }
        return prefixLength;
    }

private:
    shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        int ans = 0;
        Trie trie;

        for (const int num : arr1)
            trie.insert(to_string(num));

        for (const int num : arr2)
            ans = max(ans, trie.search(to_string(num)));

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr1 = {123, 456, 789};
    vector<int> arr2 = {1234, 4567, 7890};
    cout << sol.longestCommonPrefix(arr1, arr2) << endl; // Output: 3
    return 0;
}

/*
TC: O(N * M) where N is the number of elements in arr1 and M is the average number of digits in the numbers.
SC: O(N * M) for the Trie data structure.
*/