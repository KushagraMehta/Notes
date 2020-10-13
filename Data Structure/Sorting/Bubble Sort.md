```cpp
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)

    for (int j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for(auto a:arr)
    	cout<<a<<'\t';
    cout<<endl;

    return 0;
}

```
