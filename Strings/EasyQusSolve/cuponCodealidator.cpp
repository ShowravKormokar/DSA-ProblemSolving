// Leetcode problem 3606 -> Coupon Code Validator
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        // Store indices of valid coupons
        vector<int> validIndices;

        // Define set of valid business lines
        unordered_set<string> validBusinessLines = {
            "electronics",
            "grocery",
            "pharmacy",
            "restaurant"};

        // Iterate through all coupons to find valid ones
        for (int i = 0; i < code.size(); ++i)
        {
            const string &couponCode = code[i];
            const string &business = businessLine[i];
            bool isActiveCoupon = isActive[i];

            if (isActiveCoupon &&
                validBusinessLines.count(business) &&
                isValidCouponFormat(couponCode))
            {
                validIndices.push_back(i);
            }
        }

        // Sort valid coupon indices by business line (primary) and coupon code (secondary)
        sort(validIndices.begin(), validIndices.end(), [&](int indexA, int indexB)
             {
            // First compare by business line
            if (businessLine[indexA] != businessLine[indexB]) {
                return businessLine[indexA] < businessLine[indexB];
            }
            // If business lines are same, compare by coupon code
            return code[indexA] < code[indexB]; });

        // Build result vector with sorted valid coupon codes
        vector<string> result;
        for (int index : validIndices)
        {
            result.push_back(code[index]);
        }

        return result;
    }

    bool isValidCouponFormat(const string &couponCode)
    {
        // Empty strings are invalid
        if (couponCode.empty())
        {
            return false;
        }

        // Check each character is alphanumeric or underscore
        for (char ch : couponCode)
        {
            if (!isalnum(ch) && ch != '_')
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution solution;
    vector<string> codes = {"SAVE10", "GROCERY_20", "PHARMA#30", "RESTAURANT50", "INVALID CODE!"};
    vector<string> businessLines = {"electronics", "grocery", "pharmacy", "restaurant", "grocery"};
    vector<bool> isActive = {true, true, true, false, true};

    vector<string> validCoupons = solution.validateCoupons(codes, businessLines, isActive);

    cout << "Valid Coupons:" << endl;
    for (const string &coupon : validCoupons)
    {
        cout << coupon << endl;
    }

    return 0;
}

/*
TC: O(N log N) - N is the number of coupons. We iterate through the list of coupons once (O(N)) and then sort the valid coupons (O(M log M), where M is the number of valid coupons, and M <= N). Thus, the overall complexity is dominated by the sorting step.
SC: O(M) - M is the number of valid coupons. We store the indices of valid coupons in a separate vector.
*/