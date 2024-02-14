#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void partition(int arr[], int low, int high) {
    int i = low + 1;
    int j = high;
    int pivot = low;

    while (i <= j) {
        while (arr[i] < arr[pivot] && i <= high - 1) {
            i++;
        }

        while (arr[j] > arr[pivot] && j >= low + 1) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[pivot], arr[j]);
}

void generateRandomInputs(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; // Generating random numbers between 0 and 999
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    const int numInputs = 10;
    int A[10]; // Maximum size of the array
    int arraySizes[numInputs];

    for (int i = 0; i < numInputs; ++i) {
        arraySizes[i] = (i + 1) * 100; // Adjust the sizes as needed
    }

    for (int i = 0; i < numInputs; ++i) {
        int arraySize = arraySizes[i];
        generateRandomInputs(A, arraySize);

        auto start = high_resolution_clock::now();
        partition(A, 0, arraySize - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Array Size: " << arraySize << "\tTime Taken: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
