#include <iostream>
using namespace std;


/** 
 * Prints the Collatz sequence of a given number (passed via the command line).  
 * The Collatz conjecture works by dividing a number by 2 if it is even or multiplying 
 * it by 3 and adding 1 if it is odd.  These operations are performed until the number 
 * equals 1.
 * 
 * Input:
 * - A single integer used as the start of the Collatz sequence
 * 
 * Output:
 * - Prints all integers in the Collatz sequence
 * - Returns 0 when successful
 * **/
int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);

    cout << num << endl;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num *= 3;
            num += 1;
        }

        cout << num << endl;
    }

    return 0;
}
