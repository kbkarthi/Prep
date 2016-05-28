#include <iostream>
using namespace std;

struct mypair {
  int a,b;
};

class ChainOfPairs {
  public:
    struct mypair *pairs;
    int length;
    int getChainOfPairs();
    int* entrireChain;
    ChainOfPairs(struct mypair *pairs, int length, int* entrireChain) {
      this->pairs = pairs;
      this->length = length;
      this->entrireChain = entrireChain;
    }
};

int ChainOfPairs::getChainOfPairs()
{
  entrireChain = (int *)malloc((length + 1) * sizeof(int));
  
  
  for (int i = 1; i<length; i++)
  {
    entrireChain[i] = 0;
  }
  
  int max = 0;
  entrireChain[0] = 1;
  for (int i=1; i<length; i++)
  {
    for (int j=i-1; j >= 0; j--)
    {
      if (pairs[i].a > pairs[j].b && entrireChain[j] >= entrireChain[i])
      {
        entrireChain[i] = entrireChain[j] + 1;
        if (max < entrireChain[i])
        {
          max = entrireChain[i];
        }
      }
    }
  }
  
  return max;
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  struct mypair pairs[5] ;
  pairs[0].a = 5;
  pairs[1].a = 15;
  pairs[2].a = 27;
  pairs[3].a = 39;
  pairs[4].a = 50;
  pairs[0].b = 24;
  pairs[1].b = 28;
  pairs[2].b = 40;
  pairs[3].b = 60;
  pairs[4].b = 90;
  
  int* output;
  ChainOfPairs* ch = new ChainOfPairs(pairs, 5, output);
  
  cout << ch->getChainOfPairs() << endl;
  
  for (int i = 0; i < 6; i ++)
  {
    cout << ch->entrireChain[i] << " ";
  }
  
  return 0;
}
