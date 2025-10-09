// Leetcode problem 3494 -> Find the minimum amount of time to brew potion
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = skill.size();
        int m = mana.size();

        long long sumSkill = 0;
        for (int x : skill)
            sumSkill += x;

        // prevWizardDone will represent the finish time of the last wizard
        // after scheduling processed potions so far.
        long long prevWizardDone = sumSkill * 1ll * mana[0];

        for (int j = 1; j < m; ++j)
        {
            // prevPotionDone is a running value used to compute constraints
            long long prevPotionDone = prevWizardDone;

            // iterate wizards backwards (except last wizard)
            for (int i = n - 2; i >= 0; --i)
            {
                // remove the time that wizard i+1 spent on previous potion
                prevPotionDone -= 1ll * skill[i + 1] * mana[j - 1];

                // for wizard i, the earliest finish time after placing potion j
                // must be at least prevPotionDone (constraint from next wizard's chain)
                // and also can't be earlier than current prevWizardDone minus this wizard's time.
                long long candidate = prevWizardDone - 1ll * skill[i] * mana[j];
                prevWizardDone = max(prevPotionDone, candidate);
            }

            // after processing constraints for all wizards, add full pipeline time
            prevWizardDone += sumSkill * 1ll * mana[j];
        }

        return prevWizardDone;
    }
};

int main()
{
    Solution sol;
    vector<int> skill = {1, 5, 2, 4};
    vector<int> mana = {5, 1, 4, 2};
    cout << "Result: " << sol.minTime(skill, mana) << endl;
    return 0;
}