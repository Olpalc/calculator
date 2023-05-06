#include "header.h"


int main()
{
    void sayHello();
    int numoftries;
    cout<<"How many times would you like to calculate? :";
    cin>> numoftries;
    int i = 0;
    while (i < numoftries)
    {
         cout<<"Enter the first number:";
         cin >> num1;
         cout<<"Enter the second number:";
         cin>>num2;
         cout<<"Enter the operator sign:";
         cin>>opSign;
         calculatorThing(); 
         i++;
         if (i = numoftries - 1)
         {
            cout<<"This is your last one!";
         }
         else
         {
            continue;
         }
            
    }
    return 0;
}