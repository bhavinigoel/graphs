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

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && arr[i] < pivot) {
            i++;
        }

        while (i <= j && arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int q = partition(arr, low, high);
        quicksort(arr, low, q - 1);
        quicksort(arr, q + 1, high);
    }
}

void generateRandomInputs(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; // Generating random numbers between 0 and 999
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
for(int arraySize=1000 ; arraySize<60000 ; arraySize=arraySize+5000){
    //const arraySize = 1000; // Adjust the size as needed
    int arr[arraySize];

    generateRandomInputs(arr, arraySize);

    auto start = high_resolution_clock::now();
    quicksort(arr, 0, arraySize - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time Taken: " << duration.count() << " microseconds" << endl;}

    return 0;
}
