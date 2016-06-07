#include <iostream>

using namespace std;

int getMin (int a, int b, int c)
{
    int m = a;
  if (m > b) 
    m = b;
  if (m > c) 
    m = c;
  return m;
}

int MaximumSquareSize(bool input[6][5], int row, int column)
{
    int output[row + 1][column + 1];
    
    for (int i =0; i<= row; i++)
    {
        output[i][0] = 0;
    }
    
    for (int i =0; i<= column; i++)
    {
        output[0][i] = 0;
    }
    
    int max = 0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            if (input[i-1][j-1] == 0)
            {
                output[i][j] = 0;
            }
            else 
            {
                output[i][j] = 1 + getMin(output[i-1][j], output[i][j-1], output[i-1][j-1]);
                
                if (max < output[i][j])
                {
                    max = output[i][j];
                }
            }
        }
    }
    
    return max;
}

int main()
{
   cout << "Hello World" << endl; 
   bool M[6][5] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
                   
   cout << MaximumSquareSize(M, 6, 5) << endl;
   return 0;
}

