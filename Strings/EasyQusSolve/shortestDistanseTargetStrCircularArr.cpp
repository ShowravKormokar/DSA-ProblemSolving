// Leetcode problem 2515 -> Shortest Distance to Target String in a Circular Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        const int n = words.size();

        for (int i = 0; i < n; i++)
        {
            if (words[(startIndex + i + n) % n] == target)
                return i;
            if (words[(startIndex - i + n) % n] == target)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
    string target = "hello";
    int startIndex = 1;

    cout << sol.closetTarget(words, target, startIndex) << endl; // Output: 1

    return 0;
}

/*
TC: O(n) where n is the number of words in the input array.
SC: O(1) since we are using only a constant amount of extra space.
*/