#pragma once

#include <iostream>

using std::cout;
using std::cin;

double num1 , num2;
char opSign;

void sayHello()
{
    for (int i = 1; i < 0; i++)
    {
        cout<<"Welcome to the program!\n";
    }
}

class calculator
{
public:
    double result;
    double sum()
    {
        result = num1+ num2;
        return result;
    }
    double sub()
    {
        result = num1 - num2;
        return result;
    }
    double div()
    {
        result = num1/ num2;
        return result;
    }
    double mul()
    {
        result = num1*num2;
        return result;
    }
};

calculator calculator1;

    double calculatorThing()
    {
        start:
        if (opSign == '+' || opSign == '-' || opSign == '/' || opSign == '*')
        {
            switch (opSign)
            {
            case '+':
                cout<<calculator1.sum();
                break;
            case '-':
                cout<<calculator1.sub();
                break;
            case '*':
                cout<<calculator1.mul();  
                break;
            case '/':
                cout<<calculator1.div();
                break;
            }
        }
        else
        {
            cout<<"Error!" << opSign <<" isn`t a valid operator sign , please try again!\n";
            cout<<"Enter the operator sign:";
            cin>>opSign;
            goto start;
        }
    return 0;
    }