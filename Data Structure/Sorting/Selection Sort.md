```cpp
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int j, min_idx;

    for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for(auto a:arr)
    	cout<<a<<'\t';
    cout<<endl;

    return 0;
}

```
