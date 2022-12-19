#ifndef CALCULATORAPP_H
#define CALCULATORAPP_H

#include <string>
#include <fstream>

namespace Calc {

class CalculatorApp
{
public:
    CalculatorApp();

    void run(std::string saveFileLocation = "log.txt");

    template <typename T> T add(const T number1, const T number2, T &result);
    template <typename T> T subtract(const T number1, const T number2, T &result);
    template <typename T> T multiply(const T number1, const T number2, T &result);
    template <typename T> T divide(const T number1, const T number2, T &result);
};

}

#endif // CALCULATORAPP_H
