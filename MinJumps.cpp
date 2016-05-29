#include <iostream>
using namespace std;

int GetMin(int a, int b)
{
  return (a < b) ? a : b;
}

int minJumps(int a[], int n)
{
  int *jumps = new int[n];
  
  jumps[0] = 0;
  
  for (int i = 1; i< n; i++)
  {
    jumps[i] = 100;
  }
  
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j ++ )
    {
      if (i <= j + a[j])
      {
        jumps[i] = GetMin(jumps[i], jumps[j] + 1);
      }
    }
  }
  
  return jumps[n-1];
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int size = 11;
  cout << endl << minJumps(arr, size) << endl;
  
  return 0;
}
