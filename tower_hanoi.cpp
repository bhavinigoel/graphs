#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void TOH(int n, char from, char using_rod, char to)
{
    if (n >= 1)
    {
        TOH(n - 1, from, to, using_rod);
        cout << "move disk from " << from << " to " << to << endl;
        TOH(n - 1, using_rod, from, to);
    }
}

int main()
{
    for (int i = 15; i <= 20; i++)
    {
        auto start = high_resolution_clock::now();
        for (int m = 1; m <= 10; m++)
        {
            TOH(i, 'f', 'u', 't');
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "inputs \t" << i << "\t Time taken: " << duration.count() << " nanoseconds" << endl;
    }

    return 0;
}
