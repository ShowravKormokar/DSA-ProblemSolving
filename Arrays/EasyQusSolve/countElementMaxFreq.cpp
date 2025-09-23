// Leetcode problem 3005 -> Count element with maximum frequency.
#include <bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int> &nums)
{
    constexpr int kMax = 100;
    vector<int> count(kMax + 1);

    // Count frequency of each number
    for (int num : nums)
        ++count[num];

    // Find maximum frequency
    int maxFreq = *max_element(count.begin(), count.end());

    // Count how many numbers have this max frequency
    int freqCount = count_if(count.begin(), count.end(),
                             [&](int x)
                             { return x == maxFreq; });

    return freqCount * maxFreq;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    cout << "Max freq. element: " << maxFrequencyElements(nums) << endl; //Output: 4
    return 0;
}

/*
TC: O()
SC: O()
*/