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

    sort(arr, arr + n);

    cout << "Enter number of students: ";
    int m;
    cin >> m;

    int min = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min)
            min = diff;
    }

    cout << "Minimum difference is " << min << endl;
}