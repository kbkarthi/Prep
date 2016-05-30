#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int GETMAX (int a, int b)
{
  return (a > b) ? a : b; 
}

int LongestCommonSubSeq(char a[], char b[], int aLength, int bLength, char outputStr[])
{
  int output[aLength + 1][bLength + 1];
  //int maxSize = GETMAX(aLength, bLength);
  //outputStr = (char *)malloc(maxSize * sizeof(char));
  
  for (int i = 0; i <= aLength; i++)
  {
    for (int j = 0; j <= bLength; j ++)
    {
      output[i][j] = 0;
    }
  }
  
  for (int i = 1; i <= aLength; i++)
  {
    for (int j = 1; j <= bLength; j ++)
    {
      if (a[i-1] == b[j-1])
      {
        output[i][j] = output[i-1][j-1] + 1;
      }
      else
      {
        output[i][j] = GETMAX(output[i-1][j], output[i][j-1]);
      }
    }
  }
  
  int max = output[aLength][bLength] - 1;
  outputStr[max + 1] = '\0';
  
  for (int i = aLength; i >= 1; i--)
  {
    for (int j = bLength; j >= 1; j--)
    {
      if (output[i][j] - 1 == output[i-1][j-1])
      {
        outputStr[max] = a[i-1];
        i--;
        j--;
        max --;
      }
    }
  }
  
  return output[aLength][bLength];
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  char OutputStr[7];
  
  int m = strlen(X);
  int n = strlen(Y);
 
  cout << "Length of LCS is " << LongestCommonSubSeq(X,Y,m,n,OutputStr) << endl;
  
  for(int i = 0; i < 7; i++)
  {
    cout << OutputStr[i];
  }
  
  return 0;
}
