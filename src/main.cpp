#include <iostream>

class calculator
{
private:
    double num1 , num2;
    char opsign;
    
public:
    int num_of_tries;
    void get_all_input();
    double calculator_thingy();
};

class calculator_func : private calculator
{
public:
    double sum();
    double sub();
    double mul();
    double div();
};

void say_hello()
{
    for (int i = 0; i < 1; i++)
    {
        std::cout << "Welcome to the program!\n";
    }
}

void calculator::get_all_input()
{
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
retry1:
    std::cout << "Enter the operator sign: ";
    std::cin >> opsign;
    if (opsign != '+' && opsign != '-' && opsign != '*' && opsign != '/')
    {
        std::cout << "Error!  " << opsign << "   isn`t a valid operator sign , please try again!\n";
        goto retry1;
    }
}

double calculator::calculator_thingy()
{
    switch (opsign)
    {
    case '+':
        std::cout << "The result is : " << num1 + num2 << " \n";
        break;
    case '-':
        std::cout << "The result is : " << num1 - num2;
        break;
    case '*':
        std::cout << "The result is : " << num1 - num2;
        break;
    case '/':
        std::cout << "The result is : " << num1 - num2;
        break;
        return 0;
    }
}
    calculator calculator1;


int main()
{
    say_hello();
    std::cout<<"How many times would you like to calculate? : ";
    std::cin>>calculator1.num_of_tries;
    for (int times_run = 0; times_run < calculator1.num_of_tries ; times_run++)
    {
        if (times_run == calculator1.num_of_tries -1)
        {
            std::cout<<"This is your last one!\n";
        }
        
        calculator1.get_all_input();
        calculator1.calculator_thingy();
    }
    
    std::cout << "ok\n";
    return 0;
}