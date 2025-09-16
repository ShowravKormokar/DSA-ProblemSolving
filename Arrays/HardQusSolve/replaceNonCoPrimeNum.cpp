// Leetcode problem 2197 -> Replace Non-Coprime Numbers in Array
#include <bits/stdc++.h>
using namespace std;

vector<int> replaceNonCoprimes(vector<int> &nums)
{
    vector<int> ans;

    for (int num : nums)
    {
        while (!ans.empty() && std::gcd(ans.back(), num) > 1)
            num = std::lcm(ans.back(), num), ans.pop_back();
        ans.push_back(num);
    }

    return ans;
}

int main()
{
    vector<int> nums = {6, 4, 3, 2, 7, 6, 2};

    for (auto res : replaceNonCoprimes(nums))
    {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}

/*
TC: O(nlog10^8)
SC: O(n)
*/