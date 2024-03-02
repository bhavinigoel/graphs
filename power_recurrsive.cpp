#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int power(int n, int k) {
    if (k == 0) {
        return 1;
    } else {
        return (n * power(n, k - 1));
    }
}

void gen(vector<int>& arr, int n) {
    for (int i = 1; i <= n; i++) {
        arr[i - 1] = i;
    }
}

void solve(vector<pair<int, int>>& store) {
    for (int i = 1; i <= 10; i++) {
        vector<int> arr(i);
        gen(arr, i);
        int t = 0;
        int avg = 0;
        for (int m = 0; m < 100000000; m++) {
            auto start = high_resolution_clock::now();
            // Assuming 10 as the default value for the power function
            int x = power(4, i);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t += duration.count();
        }
        avg = t / 100000;
        store.push_back({i, avg});
    }
}

int main() {
    vector<pair<int, int>> store;
    solve(store);
    for (auto i : store) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
