#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void PG(int arr[], int s, int n)
{
    if (s == n)
    {
        for (int i = 0; i < n; i++)
        {
        }

        return;
    }
    else
    {
        for (int i = s; i < n; i++)
        {
            swap(arr[i], arr[s]);
            PG(arr, s + 1, n);
            swap(arr[i], arr[s]);
        }
    }
}

void generateGraph(vector<pair<int, int>> &graph)
{
    for (int i = 1; i <= 10; i++)
    {
        int *arr = new int[i];
        for (int j = 0; j < i; j++)
        {
            arr[j] = j + 1; // Initialize array with values 1 to i
        }

        auto start = high_resolution_clock::now();
        PG(arr, 0, i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        int timeTaken = duration.count();
        graph.push_back({i, timeTaken});

        delete[] arr;
    }
}

int main()
{
    vector<pair<int, int>> graph;
    generateGraph(graph);

    // Output the graph
    for (auto i : graph)
    {
        cout << "Array Size: " << i.first << "\tTime: " << i.second << " microseconds" << endl;
    }

    return 0;
}