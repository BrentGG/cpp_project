#include "calculatorapp.h"

#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QString>

using namespace std;

Calc::CalculatorApp::CalculatorApp()
{
}

void Calc::CalculatorApp::run(string saveFileLocation)
{
    QFile saveFile(QString::fromStdString(saveFileLocation));
    try {
        if (!saveFile.open(QIODevice::WriteOnly))
            throw saveFileLocation;
    } catch(string location) {
        cout << "Could not open " << location << "\n";
        exit(-1);
    }
    QTextStream saveFileStream(&saveFile);

    cout << "Welcome to the Calculator\n";
    cout << "-------------------------\n\n";
    while(1) {
        cout << "What do you wish to do today?\n(1) Add\n(2) Subtract\n(3) Multiply\n(4) Divide\n(5) Exit\n";
        string command;
        while (1) {
            cin >> command;
            if (!(command[0] == '1' || command[0] == '2' || command[0] == '3' || command[0] == '4' || command[0] == '5'))
                cout << "Please provide a valid option.\n";
            else
                break;
        }
        if (command[0] == '5')
            break;

        string number1Str;
        float number1;
        while (1) {
            cout << "First number: ";
            cin >> number1Str;
            try {
                number1 = stof(number1Str);
            } catch(invalid_argument const&) {
                cout << "Please provide a valid number.\n";
                continue;
            }
            break;
        }

        string number2Str;
        float number2;
        while (1) {
            cout << "Second number: ";
            cin >> number2Str;
            try {
                number2 = stof(number2Str);
            } catch(invalid_argument const&) {
                cout << "Please provide a valid number.\n";
                continue;
            }
            break;
        }

        float result = 0;
        char op = '+';
        if (command[0] == '1')
            add(number1, number2, result);
        else if (command[0] == '2') {
            subtract(number1, number2, result);
            op = '-';
        }
        else if (command[0] == '3') {
            multiply(number1, number2, result);
            op = '*';
        }
        else if (command[0] == '4') {
            divide(number1, number2, result);
            op = '/';
        }
        cout << number1 << " " << op << " " << number2 << " = " << result << "\n\n";
        saveFileStream << number1 << " " << op << " " << number2 << " = " << result << "\n";
    }
    cout << "\nCome back soon!\n";
    saveFile.close();
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
