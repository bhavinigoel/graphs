#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int* generate_input(int k)
{
    int* arr = new int[k];
    for (int j = 0; j < k; j++)
    {
        arr[j] = rand();
    }
    return arr;
}

int sum(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    return (sum(arr, n - 1) + arr[n - 1]);
}

int main()
{
    for (int i = 1000; i <= 100000; i = i * 3)
    {
        int* arr = generate_input(i);

        auto start = high_resolution_clock::now();
        for (int m = 1; m <= 10; m++)
        {
            int s = sum(arr, i);
            cout << s << endl;
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "inputs \t" << i << "\t Time taken: " << duration.count() << " nanoseconds" << endl;

        delete[] arr; // Deallocate the dynamically allocated array
    }

    return 0;
}
