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

int HR(int arr[],int m,int n,int x)
{
  if(m==n)
  {
      return arr[m];
  }
  return (HR(arr,m,n+1,x))*x + arr[n];
}

int main()
{
    int *arr = new int(100000);
    for(int i=1000;i<=10000;i=i*1.2)
    {
    arr = generate_input(arr,i);
    auto start = high_resolution_clock::now();
    for(int m =1;m<=12;m++)
    {
        int expression = HR(arr,i,0,10000);
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout<< i    << " "<< duration.count()<< endl ;
    }

    return 0;
}