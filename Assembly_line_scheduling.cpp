#include <iostream>
#include <climits>
using namespace std;

struct Result {
    int path[4];  
    int length;
};

Result fcost(int a1[], int a2[], int t1[], int t2[], int n, int e1, int e2, int x1, int x2) {
    int f1[4];  
    int f2[4]; 
    int l1[4];  

    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    for (int j = 1; j < n; ++j) {
        if (f1[j - 1] + a1[j] < f2[j - 1] + t2[j - 1] + a1[j]) {
            f1[j] = f1[j - 1] + a1[j];
            l1[j] = 1;
        } else {
            f1[j] = f2[j - 1] + t2[j - 1] + a1[j];
            l1[j] = 2;
        }
    }

    Result result;
    result.length = (f1[n - 1] + x1 < f2[n - 1] + x2) ? f1[n - 1] + x1 : f2[n - 1] + x2;
    result.path[n - 1] = (f1[n - 1] + x1 < f2[n - 1] + x2) ? 1 : 2;

    for (int j = n - 2; j >= 0; --j) {
        result.path[j] = l1[j + 1];
    }
 
    return result;
}

int main() {
    int a1[] = {1, 2, 3, 4};
    int a2[] = {2, 3, 4, 5};
    int t1[] = {1, 1, 1, 1};
    int t2[] = {2, 2, 2, 2};
    int n = 4;
    int e1 = 0, e2 = 0;
    int x1 = 2, x2 = 3;

    Result result = fcost(a1, a2, t1, t2, n, e1, e2, x1, x2);

    cout << "Minimum cost path length: " << result.length << endl;
    cout << "Path: ";
    for (int i = 0; i < n; ++i) {
        cout << result.path[i] << " ";
    }
    cout << endl;

    return 0;
}