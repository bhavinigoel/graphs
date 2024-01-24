#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void TT(int k, int n, int *arr)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        arr[k] = 1;
        TT(k + 1, n, arr);

        arr[k] = 0;
        TT(k + 1, n, arr);
    }
}

int main()
{
    for (int i = 1; i <= 10; i=i*2)
    {
        int *arr = new int[i];
        auto start = high_resolution_clock::now();
        for (int m = 1; m <= 10; m++)
        {
            TT(0, i, arr);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10; // Corrected calculation
        cout << "inputs \t" << i << "\t Time taken: " << duration.count() << " nanoseconds" << endl;

        delete[] arr; // Deallocate the dynamically allocated array
    }

    return 0;
}
