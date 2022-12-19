#include "calculatorapp.h"

#include <iostream>

Calc::CalculatorApp::CalculatorApp()
{

}

void Calc::CalculatorApp::run()
{

}

template<typename T> T Calc::CalculatorApp::add(const T number1, const T number2, T &result)
{
    result = number1 + number2;
    return result;
}

template<typename T> T Calc::CalculatorApp::subtract(const T number1, const T number2, T &result)
{
    result = number1 - number2;
    return result;
}

template<typename T> T Calc::CalculatorApp::multiply(const T number1, const T number2, T &result)
{
    result = number1 * number2;
    return result;
}

template<typename T> T Calc::CalculatorApp::divide(const T number1, const T number2, T &result)
{
    result = number1 / number2;
    return result;
}
