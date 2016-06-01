#include <iostream>
using namespace std;

int BinomialCoefficient(int n, int k)
{
	int array[n+1][k+1];
	
	for (int i = 0; i<= n; i++)
	{
		array[i][0] = 1;
	}
	
	for (int i = 0; i<=k;i++)
	{
		array[i][i] = 1;
	}
	
	for (int i = 2; i <= n; i ++)
	{
		for (int j = 1; j < i && j <= k; j++)
		{
			array[i][j] = array[i-1][j] + array[i-1][j-1];	
		}
	}
	
	return array[n][k];
}

int main() {
	// your code goes here
	int n = 12, k = 5;
	cout << endl << BinomialCoefficient(n,k) << endl;
	
	return 0;
}
