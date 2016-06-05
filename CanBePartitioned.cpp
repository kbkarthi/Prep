#include <iostream>

using namespace std;

bool CanBePartitioned(int array[], int n)
{
    int sum =0;
    
    for (int i = 0; i < n; i++)
    {
        sum+=array[i];
    }
    
    if (sum %2 != 0)
        return false;
    
    bool partition[sum/2 + 1][n+1];
    
    for (int i=1; i <= sum/2; i++)
    {
        partition[i][0]=false;
    }
    
    for(int i=0;i<=n;i++)
    {
        partition[0][i]=true;
    }
    
    for (int i=1; i<=sum/2; i++)
    {
        for (int j=1; j<=n; j++)
        {
            partition[i][j] = partition[i][j-1];
            if (i >= array[j-1])
            {
                partition[i][j] |= partition[i-array[j-1]][j-1];
            }
        }
    }
    
    return partition[sum/2][n];
}

int main()
{
   cout << "Hello World" << endl; 
   int arr[] = {3, 1, 5, 9, 12};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << CanBePartitioned(arr, n) << endl;
   return 0;
}

