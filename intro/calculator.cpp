#include <iostream>
using namespace std;


/** 
 * Basic calculator that runs in the terminal
 * 
 * Input:
 * - N.A.
 * 
 * Output:
 * - Prompts the user for an operation, left operand, and right operand.  
 *   Prints the results of the operation on the operands, then repeats.
 * 
 * Supports integer operands.  Supports addition, subtraction, multiplication, 
 * division, and modulo division
 * **/
int main(int argc, char* argv[]) {
    string operation;
    while (true) {
        cout << "Operation: ";
        getline(cin, operation);

        if (operation.empty()) {
            break;
        }

        if (operation != "add" && operation != "subtract" && operation != "multiply" 
            && operation != "divide" && operation != "mod") {
            cout << operation << " isn't a valid operation" << endl;
            continue;
        }

        string left;
        cout << "Left operand: ";
        getline(cin, left);
        int left_operand = stoi(left);

        string right;
        cout << "Right operand: ";
        getline(cin, right);
        int right_operand = stoi(right);

        if (operation == "add") {
            cout << left_operand + right_operand << endl;
        } else if (operation == "subtract") {
            cout << left_operand - right_operand << endl;
        } else if (operation == "multiply") {
            cout << left_operand * right_operand << endl;
        } else if (operation == "divide") {
            cout << left_operand / right_operand << endl;
        } else if (operation == "mod") {
            cout << left_operand % right_operand << endl;
        }
    }

    return 0;
}
