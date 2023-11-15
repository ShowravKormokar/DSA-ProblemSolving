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

    cout << "Enter the searching item: ";
    int sch;
    cin >> sch;

    int start = 0, end = n - 1, flag = 0;

    while (start < end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == sch)
        {
            cout << "Found at index " << mid << endl;
            flag = 1;
            break;
        }
        else if (arr[start] < arr[mid]) // Left part sorted
        {
            (sch >= arr[start] && sch < arr[mid]) ? end = mid - 1 : start = mid + 1;
        }
        else // Right part sorted
        {
            (sch <= arr[end] && sch > arr[mid]) ? start = mid + 1 : end = mid - 1;
        }
    }

    if (flag == 0)
        cout << "Not found";
}