#include <iostream>

using namespace std;

int getMax (int a, int b)
{
    return a > b ? a : b;
}

int MaximumSumSunSeq(int input[], int n)
{
    int output[n], max = 0;
    output[0] = input[0];
    
    for (int i = 1; i < n; i++)
    {
        output[i] = input[i];
        for (int j=i-1; j>=0; j--)
        {
            if (input[i] > input[j])
            {
               output[i] = getMax(output[i], input[i] + output[j]);
               max = getMax(max, output[i]);
            }
        }
    }
    
    return max;
}

int main()
{
   cout << "Hello World" << endl; 
   int arr[] = {1, 101, 2, 3, 100, 4, 5};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout <<  MaximumSumSunSeq(arr, n) << endl;
   return 0;
}

