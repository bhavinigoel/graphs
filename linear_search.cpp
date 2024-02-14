#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Linear search function
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Element found
        }
    }
    return -1; // Element not found
}

// Function to generate random inputs with larger range
void generateRandomInputs(vector<int>& arr, int n) {
    for (int i = 10; i < 10000; i*5) {
        arr.push_back(rand() % 1000000); // Generating random numbers between 0 and 999999
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    vector<int> inputSizes = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    vector<pair<int, int>> inputData;

    for (int size : inputSizes) {
        vector<int> arr;
        generateRandomInputs(arr, size);

        auto start = high_resolution_clock::now();
        // Assuming the target to be searched is the first element
        int result = linearSearch(arr, arr[0]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        inputData.push_back({size, duration.count()});
    }

    // Print the results
    cout << "Input Size\tTime Taken (microseconds)\n";
    for (auto data : inputData) {
        cout << data.first << "\t\t" << data.second << endl;
    }

    // You can use this data to plot a graph of input size vs time taken.

    return 0;
}