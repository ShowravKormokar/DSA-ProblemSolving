// Leetcode problem 3721 -> Longest Balanced Subarray II

#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

// Unsolved problem, segment tree implementation is correct but the logic to find the longest balanced subarray is not working as expected. Need to debug and fix the logic.Need more knowledge about segment tree and how to use it to solve this problem.🚨❌💀😥

struct Node
{
    int mn, mx, lazy;
    Node() : mn(1e9), mx(-1e9), lazy(0) {}
    Node(int mn, int mx, int lazy) : mn(mn), mx(mx), lazy(lazy) {}
};

class SegmentTree
{
public:
    vector<Node> tree;
    int size;

    SegmentTree(const vector<int> &v)
    {
        size = v.size();
        tree.assign(4 * size, Node());
        build(0, 0, size - 1, v);
    }

    void build(int i, int l, int r, const vector<int> &v)
    {
        if (l == r)
        {
            tree[i] = Node(v[l], v[l], 0);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, v);
        build(2 * i + 2, mid + 1, r, v);
        tree[i].mn = min(tree[2 * i + 1].mn, tree[2 * i + 2].mn);
        tree[i].mx = max(tree[2 * i + 1].mx, tree[2 * i + 2].mx);
    }

    void push(int i, int l, int r)
    {
        if (tree[i].lazy != 0)
        {
            tree[i].mn += tree[i].lazy;
            tree[i].mx += tree[i].lazy;
            if (l != r)
            {
                tree[2 * i + 1].lazy += tree[i].lazy;
                tree[2 * i + 2].lazy += tree[i].lazy;
            }
            tree[i].lazy = 0;
        }
    }

    void update(int start, int end, int val, int i, int l, int r)
    {
        push(i, l, r);
        if (l > end || r < start)
            return;
        if (l >= start && r <= end)
        {
            tree[i].lazy += val;
            push(i, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(start, end, val, 2 * i + 1, l, mid);
        update(start, end, val, 2 * i + 2, mid + 1, r);
        tree[i].mn = min(tree[2 * i + 1].mn, tree[2 * i + 2].mn);
        tree[i].mx = max(tree[2 * i + 1].mx, tree[2 * i + 2].mx);
    }

    int findRightmostZero(int i, int l, int r)
    {
        push(i, l, r);
        if (tree[i].mn > 0 || tree[i].mx < 0)
            return -1;
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        int res = findRightmostZero(2 * i + 2, mid + 1, r);
        if (res == -1)
            res = findRightmostZero(2 * i + 1, l, mid);
        return res;
    }
};

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> last;
        vector<int> nextPos(n, n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (last.count(nums[i]))
                nextPos[i] = last[nums[i]];
            last[nums[i]] = i;
        }

        vector<int> prefix(n, 0);
        unordered_set<int> seen;
        int current = 0;
        for (int i = 0; i < n; i++)
        {
            if (seen.find(nums[i]) == seen.end())
            {
                current += (nums[i] % 2 == 0 ? -1 : 1);
                seen.insert(nums[i]);
            }
            prefix[i] = current;
        }

        SegmentTree st(prefix);
        int ans = 0;
        int rZero = st.findRightmostZero(0, 0, n - 1);
        if (rZero != -1)
            ans = rZero + 1;

        for (int i = 1; i < n; i++)
        {
            int val = (nums[i - 1] % 2 == 0 ? 1 : -1);
            st.update(i, nextPos[i - 1] - 1, val, 0, 0, n - 1);
            int idx = st.findRightmostZero(0, 0, n - 1);
            if (idx >= i)
                ans = max(ans, idx - i + 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 2, 1, 4, 3, 4};
    int result = sol.longestBalanced(nums);
    return 0;
}

/*
TC: O(N log N)
SC: O(N)
*/