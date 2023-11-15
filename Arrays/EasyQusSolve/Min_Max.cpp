#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in an array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter [" << i << "] element: ";
        cin >> arr[i];
    }

    int minNumber = arr[0], maxNumber = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minNumber)
            minNumber = arr[i];
        if (arr[i] > maxNumber)
            maxNumber = arr[i];
    }

    cout << "Minimum number is: " << minNumber << "\nMaximum number is: " << maxNumber << endl;
}