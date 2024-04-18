#include <iostream>
using namespace std;
#define INFINITY 9999
struct node {
   int from;
} s[4];
int c = 0;
void djikstras(int *a, int b[][4], int *d) {
   int i = 0, j, min, t;
   a[i] = 1;
   d[i] = 0;
   s[i].from = 0;
   for (i = 0; i < 4;i++) {
      if (b[0][i] == 0) {
         continue;
      } else {
         d[i] = b[0][i];
         s[i].from = 0;
      }
   }
   while (c < 4) {
      min = INFINITY;
      for (i = 0; i < 4; i++) {
         if (min <= d[i] || d[i] == 0 || a[i] == 1) {
            continue;
         } else if (min > d[i]) {
            min = d[i];
         }
      }
      for (int k = 0; k < 4; k++) {
         if (min == d[k]) {
            t = k;
            break;
         } else {
            continue;
         }
      }
      a[t] = 1;
      for (j = 0; j < 4; j++) {
         if (a[j] == 1 || b[t][j] == 0) {
            continue;
         } else if (a[j] != 1) {
            if (d[j] > (d[t] + b[t][j])) {
               d[j] = d[t] + b[t][j];
               s[i].from = t;
            }
         }
      }
      c++;
   }
   for (int i = 0; i < 4; i++) {
      cout<<"from node "<<s[i].from<<" cost is:"<<d[i]<<endl;
   }
}
int main() {
   int a[4];
   int d[4];
   for(int k = 0; k < 4; k++) {
      d[k] = INFINITY;
   }
   for (int i = 0; i < 4; i++) {
      a[i] = 0;
   }
   int b[4][4];
   for (int i = 0;i < 4;i++) {
      cout<<"enter values for "<<(i+1)<<" row"<<endl;
      for(int j = 0;j < 4;j++) {
         cin>>b[i][j];
      }
   }
   djikstras(a,b,d);
}