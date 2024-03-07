#include <iostream>
#include <climits>
using namespace std;

struct Result
{
    int path[4];
    int length;
};
 void number_stages( int cost[4][4]){
    int stage=0;
    for(int i=1 ; i<5 ; i++){
        for( int j=1; j<5;j++){
        if(cost[i][j] !=0){
            stage ++;
            break;
        }
        }

    }
    cout<<"stages are:"<<stage;

 }
 int calculateNumStages(int cost[4][4], int number_vertices)
{
    int maxStage = 0;
    for (int i = 0; i < number_vertices; ++i)
    {
        for (int j = 0; j < number_vertices; ++j)
        {
            if (cost[i][j] != 0 && cost[i][j] != INT_MAX && j > maxStage)
            {
                maxStage = j;
            }
        }
    }
    return maxStage + 1; 
}

Result fcost(int cost[4][4], int number_vertice, int k)
{
    int fcost[number_vertice];
    fcost[number_vertice - 1] = 0;
    int d[number_vertice];
    int path[k];
    int r;

    for (int j = number_vertice - 2; j >= 0; j--)
    {
        int min = INT_MAX;
        for (int h = j + 1; h < number_vertice; h++)
        {
            if (cost[j][h] != 0 && cost[j][h] != INT_MAX)
            {
                if (cost[j][h] + fcost[h] < min)
                {
                    r = h;
                    min = cost[j][h] + fcost[h];
                }
            }
        }

        fcost[j] = cost[j][r] + fcost[r];
        d[j] = r;
    }

    Result result;
    result.length = fcost[0];
    result.path[0] = 1;
    result.path[k - 1] = number_vertice;

    for (int z = 1; z < k - 1; z++)
    {
        result.path[z] = d[result.path[z - 1] - 1] + 1;
    }

    return result;
}

int main()
{
   
    int cost[4][4] = {
        {0, 1, 2, INT_MAX},
        {INT_MAX, 0,INT_MAX , 2},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}};

    int number_vertices = 4;
    int stages = 3;

    Result result = fcost(cost, number_vertices, stages);

   cout << "Minimum cost path length: " << result.length << endl;
  cout << "Path: ";
    for (int i = 0; i < stages; i++)
    {
       cout << result.path[i] << " ";
    }
   

    return 0;
}
