/*
 * Calculator.cpp
 *
 *  Date: [06 Sept, 2023]
 *  Author: [Victor Udeh]
 */

#include <iostream>

using namespace std;

int main() {
    int op1, op2;
    char operation;
    char answer = 'Y';  // Fixed declaration

    while (answer == 'y' || answer == 'Y') {  // Checking for both 'y' and 'Y'
        cout << "Enter expression: ";
        cin >> op1 >> operation >> op2;  // Fixed operands' order

        if (operation == '+') {  // Removed semicolon and fixed operation
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
        } else if (operation == '-') {  // Used else-if for efficiency and fixed operation
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        } else if (operation == '*') {
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        } else if (operation == '/') {
            if(op2 == 0) {  // Check for division by zero
                cout << "Error: Division by zero." << endl;
                continue;
            }
            cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
        } else {
            cout << "Invalid operation. Supported operations: +, -, *, /." << endl;
        }

        cout << "Do you wish to evaluate another expression? ";
        cin >> answer;
    }

    cout << "Program Finished." << endl;  // Final message

    return 0;  // Proper return from main
}
