#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int GETMIN (int a, int b, int c)
{
  return (a<b && a<c) ? a : (b<c) ? b : c;
}

int MinimumCostPath(int input[3][3], int row, int column)
{
  int output[row][column];
  
  output[0][0] = input[0][0];
  
  
  for (int i = 1; i < row; i++)
  {
   output[i][0] = output[i-1][0] + input[i][0];
  }
  
  for (int i = 1; i < column; i++)
  {
   output[0][i] = output[0][i-1] + input[0][i]; 
  }
  
  
  for (int i = 1; i < row; i++)
  {
    for (int j = 1; j < column; j++)
    {
      output[i][j] = GETMIN(output[i-1][j-1], output[i][j-1], output[i - 1][j]) + input[i][j];
    }
  }
  
  return output[row - 1][column - 1];
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
  
  cout << MinimumCostPath(cost, 3, 3) << endl;
  return 0;
}



