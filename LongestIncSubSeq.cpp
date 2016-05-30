#include <iostream>
using namespace std;

int LongestSubSeq(int array[], int n)
{
    int subseq[n];
    
    for (int i = 0; i < n; i++)
    {
        subseq[i] = 0;
    }
    
    subseq[0] = 1;
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >=0; j--)
        {
            if (array[i] > array[j] && subseq[i] < subseq[j] + 1)
            {
                subseq[i] = subseq[j] + 1;
                if (max < subseq[i]) max = subseq[i];
            }
        }
    }
    
    // Print longest increasing sub seq 
    int currentMax = max;
    for (int i = n-1; i >= 0; i--)
    {
        if (currentMax == subseq[i])
        {
            cout << array[i] << " ";
            --currentMax;
        }
    }
    
    
    cout << endl;
    
    // return length of the longest increasing sub seq
    return max;
}


int main() {
    cout<<"Hello" << endl;
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 } ;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout << LongestSubSeq (arr,n) << endl;
    return 0;
}
