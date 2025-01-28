#include <iostream>
using namespace std;


/** 
 * This function takes three integers as input: start, end, divisor.
 * The function prints all integers from start to end, inclusive, that 
 * are divisible by divisor.  If start > end, it prints in decreasing order.
 * 
 * Input:
 * - Three integers: start, end, divisor
 * 
 * Output:
 * - Prints all integers from start to end, inclusive, that are divisible by 
 *   divisor
 * - Returns 0 when successful
 * **/
int main(int argc, char* argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

    if (start < end) {
        for (int num = start; num <= end; num++) {
            if (num % divisor == 0) {
                cout << num << endl;
            }
        }
    } else {
        for (int num = start; num <= end; num--) {
            if (num % divisor == 0) {
                cout << num << endl;
            }
        }
    }

    return 0;
}
