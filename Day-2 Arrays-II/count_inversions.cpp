#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int low, int mid, int high)
{
    vector<long long> temp;
    long long cnt = 0;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] > arr[right])
        {
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
        else
        {
            temp.push_back(arr[left]);
            left++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt;
}

long long mergeSort(long long *arr, int low, int high)
{
    long long cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (high + low) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}