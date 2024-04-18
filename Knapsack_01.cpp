#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n, vector<vector<int>>& items)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
        
                if (val[i - 1] + K[i - 1][w - wt[i - 1]] > K[i - 1][w])
                    items[i][w] = 1;
            } else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);

    vector<vector<int>> items(n + 1, vector<int>(W + 1, 0)); // Matrix to store whether item i is included or not
    int maxProfit = knapSack(W, weight, profit, n, items);

    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Items taken: ";
    for (int i = n, w = W; i > 0 && w > 0; i--) {
        if (items[i][w] == 1) {
            cout << i << " ";
            w -= weight[i - 1]; 
        }
    }

    return 0;
}
