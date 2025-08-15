// Leetcode problem 342 -> Power of four
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
    // Way 01
    /*
    for(long long i=1;i<=n;i*=4){
            if(i==n){
                return true;
            }
        }
        return false;
    */

    // Way 02
    double x = log10(n) / log10(4);
    return fabs(x - round(x)) < 1e-10;
}

int main()
{
    int n = 16;
    cout << "Is: " << isPowerOfFour(n) << endl;
    return 0;
}

/*
TC: O(1)
SC: O(1)
*/