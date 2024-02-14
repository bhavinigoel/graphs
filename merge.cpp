#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int start, int mid, int end) {
    int i = start, j = mid + 1;
    int k = 0;
    int temp[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i <= end - start; i++) {
        arr[start + i] = temp[i];
    }
}

void mergesort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void generateRandomInputs(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100000; // Generating random numbers between 0 and 99999
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    const int numInputs = 10;
    int arraySizes[numInputs];
    long long result[numInputs]; // Using long long for larger time values

    for (int i = 0; i < numInputs; ++i) {
        arraySizes[i] = (i + 1) * 500; // Adjust the sizes as needed
    }

    for (int i = 0; i < numInputs; ++i) {
        int arraySize = arraySizes[i];
        int arr[arraySize];

        generateRandomInputs(arr, arraySize);

        auto start = high_resolution_clock::now();
        mergesort(arr, 0, arraySize - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start);

        result[i] = duration.count();
    }

    cout << "Input Size\tTime Taken (nanoseconds)\n";
    for (int i = 0; i < numInputs; ++i) {
        cout << arraySizes[i] << "\t\t" << result[i] << endl;
    }

    return 0;
}
