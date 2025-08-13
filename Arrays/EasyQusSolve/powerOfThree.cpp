//Leetcode problem 326 -> Power of three
#include<bits/stdc++.h>
using namespace std;

bool powerOfThree(int n)
{
    double x = log10(n) / log10(3);
    return fabs(x - round(x)) < 1e-10;
}

int main()
{
    int n=27;
    cout<<"Power of three: "<<powerOfThree(n)<<endl; //Output: 1 [Means true, 3^n]
    return 0;
}

/*
TC: O(1)
SC: O(1)
*/