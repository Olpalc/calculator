#pragma once 

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