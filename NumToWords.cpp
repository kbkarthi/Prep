#include <iostream>
#include <stack>
#include <string>

using namespace std;

string getInWords(int num)
{
    stack<string> mystack;
    string output("");
    int itr = 0;
    
    while (num != 0)
    {
        int remainder = num % 1000;
        
        int one = remainder / 100;
        int two = remainder % 100;
        
        if (itr == 1)
        {
            mystack.push("thousand");
        }
        else if (itr == 2)
        {
            mystack.push("million");
        }
        else if (itr == 3)
        {
            mystack.push("billion");
        }
        
        if (two > 0)
        {
            mystack.push(to_string(two));
        }
        
        if (one > 0)
        {
            mystack.push("hundred");
            mystack.push(to_string(one));
        }
        
        ++itr; 
        num = num / 1000;
    }
    
    while (!mystack.empty())
    {
        output += mystack.top();
        mystack.pop();
    }
    
    return output;
}


int main()
{
   cout << "Hello World" << endl; 
   cout << getInWords(1011999) << endl;
   return 0;
}

