#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int i = 0, j = 0, flag = 0;
    for (; i < nums.size(); i++)
    {
        // Hint: make different target  and current array value, and find the different value on the array
        int diff = target - nums[i];
        for (; j < nums.size(); j++)
        {
            if (diff == nums[j] && i != j) // Find different value, successfully
            {
                flag = 1;
                goto output;
            }
        }
    }
output:
    if (flag == 1)
        cout << "[" << i << "," << j << "]" << endl;
    else
        cout << "[]" << endl;
    return 0;
}