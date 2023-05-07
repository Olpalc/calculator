#include <iostream>

using std::cin;
using std::cout;

double num1, num2;
char opSign;

void sayHello()
{
    cout << "Welcome to the program!\n";
}

class calculator
{
public:
    double result;
    double sum()
    {
        result = num1 + num2;
        return result;
    }
    double sub()
    {
        result = num1 - num2;
        return result;
    }
    double div()
    {
        result = num1 / num2;
        return result;
    }
    double mul()
    {
        result = num1 * num2;
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
            cout << "The result is: " << calculator1.sum() << "\n";
            break;
        case '-':
            cout << "The result is: " << calculator1.sub() << "\n";
            break;
        case '*':
            cout << "The result is: " << calculator1.mul() << "\n";
            break;
        case '/':
            cout << "The result is: " << calculator1.div() << "\n";
            break;
        }
    }
    else
    {
        cout << "Error!" << opSign << " isn`t a valid operator sign , please try again!\n";
        cout << "Enter the operator sign:";
        cin >> opSign;
        goto start;
    }
    return 0;
}

int main()
{

    sayHello();
    retry:
    cout<<"How many times would you like to calculate? : ";
    int num_of_tries; 
    cin>> num_of_tries;
    if (num_of_tries == 0 || num_of_tries < 0)
    {
        cout<<"You can`t do that! Please try again!\n";
        goto retry;
    }
    else
    {
        for (int i = 1; i < num_of_tries; i++)
        {
            if (i = num_of_tries - 1)
            {
                cout<<"This is your last one!\n";
            }
                cout << "Enter the first number:";
                cin >> num1;
                cout << "Enter the second number:";
                cin >> num2;
                cout << "Enter the operator sign:";
                cin >> opSign;
                calculatorThing();
        }
    }
        return 0;
}