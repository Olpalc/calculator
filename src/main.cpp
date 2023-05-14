#include "header.h"

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


int main() {
    say_hello();
    calculator1.get_all_input();
    calculator1.calculator_thingy();
    std::cout << "ok\n";
    return 0;
}