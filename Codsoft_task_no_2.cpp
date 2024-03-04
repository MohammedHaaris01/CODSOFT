#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// Function to check if a character is a digit
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to convert a substring to an integer
int stringToInt(const char* str, int start, int end) {
    int result = 0;
    for (int i = start; i <= end; ++i) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

int main() {
    char expression[50];
    int result = 0;
    char choice;

    do {
        cout << "-----------------Simple Calculator-----------------" << endl;
        cout << "Enter the expression: ";
        cin.getline(expression, 50);

        char operation = '+';
        int operand = 0;
        int len = strlen(expression);
        int i = 0;

        
        result = 0;

        while (i < len) {
            if (isDigit(expression[i])) {
                int start = i;
                while (i < len && isDigit(expression[i])) {
                    ++i;
                }
                int end = i - 1;
                int number = stringToInt(expression, start, end);
                switch (operation) {
                    case '+':
                        result += operand;
                        operand = number;
                        break;
                    case '-':
                        result += operand;
                        operand = -number;
                        break;
                    case '*':
                        operand *= number;
                        break;
                    case '/':
                        if (number != 0) {
                            operand /= number;
                        } else {
                            cout << "Error: Division by zero!" << endl;
                            return 1;
                        }
                        break;
                    case '%':
                        operand %= number;
                        break;
                    case '^':
                        operand = pow(operand, number);
                        break;
                }
            } else {
                operation = expression[i];
                ++i;
            }
        }

    
        result += operand;

        cout << "Result: " << result << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
