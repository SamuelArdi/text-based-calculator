#include <iostream>
#include <list>
#include <typeinfo>

using std::cout;
using std::string;

double calculator(char op, double num1, double num2) {
    double result;
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        
        case '-':
            result = num1 - num2;
            break;
        
        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;

        default:
            break;
    }
    
    return result;
}

int main() {
    cout << "--------------- * Avterion Calculator * ---------------\n";
    cout << "Currently available operators:\n";
    cout << "Addition (+)\n";
    cout << "Subtraction (-)\n";
    cout << "Multiplication (*)\n";
    cout << "Division (/)\n";
    
    bool active = true;
    while (active == true) {
        string input;
        cout << "> ";
        getline(std::cin, input);

        if (input == "exit") {
            cout << "Exiting...";
            break;
        }

        // Extracting the numbers and the operator
        string op;
        string ops[] = {"+", "-", "*", "/"}; // the available operators
        bool op_found = false;
        for (int i = 0; i < std::end(ops) - std::begin(ops); i++) {
            string token;
            token = ops[i];
            if (input.find(token) != string::npos) {
                op = token;
                op_found = true;
                break;
            }
        }

        double num1;
        double num2;
        try {
            string num1_str = input.substr(0, input.find_first_of(op));
            num1 = std::stod(num1_str);

            string num2_str = input.substr(input.find_last_of(op) + 1);
            num2 = std::stod(num2_str);
            
            if (op_found == true) {
                char op_c = static_cast<char>(op[0]);
                double result = calculator(op_c, num1, num2);
                cout << "Result: " << result << std::endl;
            }
            else {
                cout << "Requested operator is not available\n";
            }
        }
        catch (const std::exception& e) {
            cout << "Please input a number\n";
        }
    }

    return 0;
}