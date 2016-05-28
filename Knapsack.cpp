#include <iostream>
using namespace std;

class Knapsack
{
    public:
        int * Benefit;
        int * Weight;
        int numberOfItems;
        int MAXW;
        int FillKnapsack() ;
    
        Knapsack(int* Benefit, int* Weight, int numberOfItems, int MAXW)
        {
            this->Benefit = Benefit;
            this->Weight = Weight;
            this->numberOfItems = numberOfItems;
            this->MAXW = MAXW;
        }
        
    private: 
        int FindMax (int, int);
};

int Knapsack::FindMax (int a, int b)
{
    return (a > b) ? a : b;    
}

int Knapsack::FillKnapsack()
{
    int sack[numberOfItems+1][MAXW+1];
    
    for (int i = 0; i <= numberOfItems; i++)
    {
        for (int j = 0; j <= MAXW; j++)
        {
            if (i == 0 || j == 0) 
            {
               sack[i][j] = 0;
               continue;
            }
            
            if (Weight[i-1] <= MAXW )
            {
                sack[i][j] = FindMax(Benefit[i-1] + sack[i-1][j-Weight[i-1]], sack[i - 1][j]);
            }
            else
            {
                sack[i][j] = sack[i - 1][j];
            }
        }
    }
    
    return sack[numberOfItems][MAXW];
}

int main() {
    
    int numberOfItems = 3;
    int Benefit[3] = { 60, 100, 120 };
    int Weight[3] = { 10, 20, 30 };
    int MAXW = 50;
    
    cout<<"Hello" << endl ;
    Knapsack* kn = new Knapsack(&Benefit[0], &Weight[0], numberOfItems, MAXW);
    cout << kn->FillKnapsack() << endl;
    
    return 0;
}
