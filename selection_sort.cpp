#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int * generate_input(int arr[],int k)
{
    for(int j=1;j<=k;j++)
    {
        arr[j]=rand();
    }
    return arr;
}

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        for(int k=i+1;k<=n;k++)
        {
            if(arr[k]<arr[j])
            {
                j=k;
            }
        }
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int *arr = new int(100000);
    for(int i=1000;i<=100000 ;i=i+800)
    {
    arr = generate_input(arr,i);

    auto start = high_resolution_clock::now();
    for(int m =1;m<=12;m++)
    {
        selection_sort(arr,i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout << "inputs \t" << i    << "\t Time taken to complete selection sorting: " << duration.count() << " ns" << endl ;
    }

    return 0;
}