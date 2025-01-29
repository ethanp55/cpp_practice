#include <iostream>
using namespace std;


/** 
 * This function takes two numeric inputs (supports integers and doubles) and prints their product.  
 * If not enough inputs are provided, the function prints an error message and returns a code of 1
 * 
 * Input:
 * - Two numbers (integers and doubles are supported)
 * 
 * Output:
 * - Prints the product of the inputs
 * - Returns 0 when successful
 * - Returns 1 when not enough numbers are given
 * **/
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "product requires 3 arguments" << endl;

        return 1;
    }

    double num1 = stod(argv[1]);
    double num2 = stod(argv[2]);

    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;

    return 0;
}
