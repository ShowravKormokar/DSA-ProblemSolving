// Leetcode problem 744 -> Find Smallest Letter Greater Than Target
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        for (char letter : letters)
        {
            if (target < letter)
                return letter;
        }
        return letters[0];
    }
};

int main()
{
    Solution sol;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    cout << sol.nextGreatestLetter(letters, target) << endl; // Output: 'c'
    return 0;
}

/*
TC: O(N) where N is the number of letters in the input array.
SC: O(1) as we are using constant space.
*/