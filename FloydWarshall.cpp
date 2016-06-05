#include <iostream>

#define INF 99999

using namespace std;

void FloydWarshall(int input[4][4], int n)
{
    int output[n][n];
    
    for (int i=0; i < n; i++)
    {
        for (int j=0; j <n; j++)
        {
            output[i][j] = input[i][j];
        }
    }
    
    for (int k =0; k<n; k++)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j <n;j++)
            {
                if (output[i][k] + output[k][j] < output[i][j])
                {
                    output[i][j] = output[i][k] + output[k][j];
                }
            }
        }
    }
    
    for (int i = 0; i <n; i++)
    {
        for (int j=0; j <n;j++)
        {
            if (output[i][j] == INF)
            {
                cout << "INF" << "\t";    
            }
            else
            {
                cout << output[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main()
{
   cout << "Hello World" << endl; 
   int graph[4][4] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
   FloydWarshall(graph, 4);
   return 0;
}

