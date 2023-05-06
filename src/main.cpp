#include "header.h"



int main()
{
    void sayHello();
    int numoftries;
    cout<<"How many times would you like to calculate?:";
    cin>>numoftries;
    for (int i = 0; i < numoftries; i++)
    {
        if (i = numoftries - 1)
        {
            cout<<"This is your last one!\n";
        }
        else
        {
            continue;
        }
        cout<<"Enter the first number:";
        cin >> num1;
        cout<<"Enter the second number:";
        cin>>num2;
        cout<<"Enter the operator sign:";
        cin>>opSign;
        calculatorThing();   
    }
    return 0;
}