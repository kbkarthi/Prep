#include <iostream>

using namespace std;

int max (int a, int b)
{
    return a > b ? a : b;
}

int min (int a, int b)
{
    return a < b ? a : b;
}

int EggDrop(int floors, int eggs)
{
    int array[eggs+1][floors+1];
    
    for (int i = 0; i <= eggs; i++)
    {
        array[i][0] = 0;
        array[i][1] = 1;
    }
    
    for (int i = 0; i <= floors; i++)
    {
        array[0][i] = 0;
        array[1][i] = i;
    }
    
    for (int i = 2; i <= eggs; i++)
    {
        for (int j=2; j <= floors; j++)
        {
            array[i][j] = 100;
            
            for (int k = 1; k <= j; k++)
            {
                array[i][j] = min(array[i][j], max(array[i-1][k-1], array[i][j-k]));
            }
            
            ++array[i][j];
        }
    }
    
    return array[eggs][floors];
}


int main()
{
   cout << "Hello World" << endl; 
   int eggs = 2, floors = 36;
   cout << EggDrop(floors, eggs) << endl;
   return 0;
}

