#include <iostream>
using namespace std;

const double EPSILON = 0.0001;

/** 
 * Estimates the square root of a number via binary search.  Prints 
 * the search results at each step.  Supports doubles.
 * 
 * Input:
 * - A single number to find the square root of
 * 
 * Output:
 * - Prints every step of the binary search until the square root is found.  
 *   Returns a -1 if a negative number is supplied.  Returns 0 if successful.
 * **/
int main(int argc, char* argv[]) {
    double num = stod(argv[1]);

    if (num < 0) {
        cerr << "Input must be greater than 0" << endl;
        return 1;
    }

    double lowerBound = 0;
    double upperBound = num;
    double midPoint = (lowerBound + upperBound) / 2;

    cout << midPoint << " (" << midPoint * midPoint << ")" << endl;

    while (abs(midPoint * midPoint - num) > EPSILON) {
        if (midPoint * midPoint > num) {
            upperBound = midPoint;
        } else {
            lowerBound = midPoint;
        }

        midPoint = (lowerBound + upperBound) / 2;

        cout << midPoint << " (" << midPoint * midPoint << ")" << endl;
    }

    return 0;
}
