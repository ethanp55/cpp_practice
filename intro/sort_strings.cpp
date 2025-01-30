#include <iostream>
using namespace std;


/** 
 * Function to sort 3 strings (in place)
 * 
 * Input:
 * - 3 string references
 * 
 * Output:
 * - Modifies the strings in place so that a <= b <= c
 * **/
void sort(string& a, string& b, string& c) {
    string tmp;

    // Not the cleanest way to do this, but it works
    if (a > c) {
        tmp = c;
        c = a;
        a = tmp;

        if (a > b) {
            tmp = b;
            b = a;
            a = tmp; 
        } else if (b > c) {
            tmp = c;
            c = b;
            b = tmp;
        }
    } else if (a > b) {
        tmp = b;
        b = a;
        a = tmp;
    } else if (b > c) {
        tmp = c;
        c = b;
        b = tmp;
    }
}

/** 
 * Reads 3 strings from the command line and sorts them alphabetically - prints the
 * sorting results
 * 
 * Input:
 * - 3 strings to sort
 * 
 * Output:
 * - Prints the sorted strings in alphabetical order
 * **/
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " [string a] [string b] [string c]" << endl;
        return 1;
    }

    string a = argv[1];
    string b = argv[2];
    string c = argv[3];

    sort(a, b, c);

    cout << a << " " << b << " " << c << endl;

    return 0;
}
