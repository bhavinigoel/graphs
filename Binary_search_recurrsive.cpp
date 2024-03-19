#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Size of array: " << n << endl;

    auto start = high_resolution_clock::now(); // Start the timer
    int result = binarySearch(arr, 0, n - 1, x);
    auto stop = high_resolution_clock::now();                  // Stop the timer
    auto duration = duration_cast<microseconds>(stop - start); // Calculate the duration

    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;

    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
