#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack<int> p1;
    int n,x;
    cout<<"hint for the next time i`ll use this progg: read dimension n, and n numbers:"<<endl;
    cin>>n;
    while(n--)
    {
        cin>>x;
        p1.push(x);
    }
    cout<<"The minim and the maxim from the stack are: ";
    p1.getmaxi(p1);



    return 0;
}
