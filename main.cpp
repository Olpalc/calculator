#include <iostream>

void sayHello()
{
    for (int i = 0; i < 1; i++)
    {
        std::cout << "Welcome to the program!\n";
    }
}

class calculator_func :private calculator
{
private:
    calculator;
public:
    void sum()
    {
        std::cout<<num1 + num2;
    }
    void subtract()
    {
        std::cout<< num1 - num2;
    }
    void multiply()
    {
        std::cout<< num1 * num2;
    }
    void divide()
    {
        std::cout<< num1 / num2;
    }
}

class calculator
{
private:
    char opsign
public:
    void get_all_data_correct();
    double calculator_thingy();
};


void calculator::get_all_data_correct()
{
retry:
    std::cout << "How many times would you like to caculate? ";
    std::cin >> num_of_tries;
    if (num_of_tries == 0 || num_of_tries < 0)
    {
        std::cout << "You can`t do that ! Please try again!\n";
        goto retry;
    }
    std::cout << "Enter the first number:";
    std::cin >> num1;
    std::cout << "Enter the second number:";
    std::cin >> num2;
retry1:
    std::cout << "Enter the operator sign:";
    std::cin >> opsign;
    if (opsign != '+' || opsign != '-' || opsign != '*' || opsign != '/')
    {
        std::cout << "Error !  " << opsign << "   isn`t a valid operator! Please try again!\n";
        goto retry1;
    }
}

double calculator::calculator_thingy()
{
    switch (opsign)
    {
    case '+':
        /* code */
        break;
    
    default:
        break;
    }
    return 0;
}

int main()
{
    std::cout<<"ok\n";
    return 0;
}