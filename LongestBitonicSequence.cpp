#include <iostream>

using namespace std;

int getMax (int a, int b)
{
    return a > b ? a : b;
}

int LongestBitonicSeq(int input[], int n)
{
    int lis[n], lds[n];
    
    lis[0] = 1;
    lds[0] = 1;
    for(int i = 1;i <n; i++)
    {
        lis[i] = 1;
        lds[i] = 1;
        for (int j = i-1; j >=0; j--)
        {
            if (input[i] > input[j])
            {
                lis[i] = getMax(lis[i], lis[j] + 1);
            }
            else 
            {
                lds[i] = getMax(lds[i], lds[j] + 1);
            }
        }
    }
    
    int max = 0;
    for (int i =0; i<n; i++)
    {
        max = getMax(max, lis[i]+lds[i]-1);
    }
    
    return max;
}

int main()
{
   cout << "Hello World" << endl; 
   int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout <<  LongestBitonicSeq(arr, n) << endl;
   return 0;
}

