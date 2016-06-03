#include <iostream>

using namespace std;

int getMax (int a, int b)
{
    return a > b ? a : b; 
}

int MaxRodCutting(int price[], int n)
{
    int output[n+1];
    
    output[0] = 0;
    for (int i=1; i<=n ;i++)
    {
        int max = 0;
        for (int j=0; j<i;j++)
        {
            max = getMax(max, output[j] + price[i-j-1]);
        }
        
        output[i] = max;
    }
    
    return output[n];
}

int main()
{
   cout << "Hello World" << endl; 
   int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
   int size = sizeof(arr)/sizeof(arr[0]);
   cout << MaxRodCutting(arr, size) << endl;
   return 0;
}

