#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int power(int x, int n) {
    int m = n;
    int p = 1;
    int z = x;
    while (m > 0) {
        if ((m % 2) == 0) {
            z = z * z;
            m = m / 2;
        } else {
            p = p * z;
            m = m - 1;
        }
    }
    return p;
}

void gen(vector<int>& arr, int n) {
    for (int i = 1; i <= n; i++) {
        arr[i - 1] = i;
    }
}

// Function to perform tests and generate a graph
void generateGraph(vector<pair<int, vector<int>>>& graph) {
    for (int i = 1; i <= 10; i++) {
        vector<int> times;
        for (int j = 0; j < 10; j++) {
            int t = 0;
            for (int k = 0; k < 1000; k++) {
                auto start = high_resolution_clock::now();
                // Assuming 10 as the default value for the power function
                int x = power(4, i);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                t += duration.count();
            }
            int avg = t / 1000; // Average time for 1000 test cases
            times.push_back(avg);
        }
        graph.push_back({i, times});
    }
}

int main() {
    vector<pair<int, vector<int>>> graph;
    generateGraph(graph);

    // Output the graph
    for (auto i : graph) {
        cout << "Power: " << i.first << "\tTimes: ";
        for (auto time : i.second) {
            cout << time << " ";
        }
        cout << endl;
    }

    return 0;
}
