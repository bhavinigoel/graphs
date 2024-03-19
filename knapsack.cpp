#include <iostream>

using namespace std;

int partition_merge(int a[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = low;
    while (i < j)
    {
        while (a[i] < a[pivot])
        {
            i++;
        }
        while (a[j] > a[pivot])
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[j], a[pivot]);
    return j;
}
int *qs(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition_merge(a, low, high);
        qs(a, low, j - 1);
        qs(a, j + 1, high);
    }
    return a;
}

float fractionalKnapsack(int W, int profit_weight_ratio[][3], int N)
{
    int profit[N];
    for (int i = 0; i < N; i++)
    {
        profit[i] = profit_weight_ratio[i][2];
    }
    qs(profit, 0, N - 1); 

    float finalvalue = 0.0;

    for (int i = 0; i < N; i++)
    {

        if (profit_weight_ratio[i][1] <= W)
        {
            W -= profit_weight_ratio[i][1];
            finalvalue += profit_weight_ratio[i][0];
        }

        else
        {
            finalvalue += profit_weight_ratio[i][0] * ((double)W / (double)profit_weight_ratio[i][1]);
            break;
        }
    }

    return finalvalue;
}

int main()
{
    int W = 50;
    int profit_weight_ratio[][3] = {{60, 10, 0}, {100, 20, 0}, {120, 30, 0}};
    int N = sizeof(profit_weight_ratio) / sizeof(profit_weight_ratio[0]);

    for (int i = 0; i < N; i++)
    {
        profit_weight_ratio[i][2] = (double)profit_weight_ratio[i][0] / (double)profit_weight_ratio[i][1];
    }

    cout << fractionalKnapsack(W, profit_weight_ratio, N);
    return 0;
}