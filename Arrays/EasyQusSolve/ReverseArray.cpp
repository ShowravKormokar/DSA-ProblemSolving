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

    int start = 0, end = n - 1;

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}