#include <iostream>

using namespace std;

int getMin(int a, int b)
{
    return a < b ? a : b;
}

int MinimumJumpsNeeded(int input[], int n)
{
    int output[n];
    
    output[0] = 0;
    
    for (int i=1; i < n; i++)
    {
        output[i] = 10000;
            
        for (int j=0; j < i; j++)
        {
            if (i <= j + input[j])
            {
                output[i] = getMin(output[i], output[j] + 1);
            }
        }
    }
    
    return output[n-1];
}

int main()
{
   cout << "Hello World" << endl; 
   int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
   int n = sizeof(arr)/sizeof(int);
   cout << MinimumJumpsNeeded(arr, n) << endl;
   return 0;
}
