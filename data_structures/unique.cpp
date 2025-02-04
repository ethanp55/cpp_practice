#include <fstream>
#include <iostream>
#include <set>
using namespace std;

/** 
 * Helper function used to print the unique lines of an istream object.  
 * For this program, an input file stream (ifstream) or cin are used.
 * 
 * Input:
 * - istream object reference
 * 
 * Output:
 * - Prints the unique lines from the istream object
 * **/
void print_unique_lines(istream& is) {
    string line;
    set<string> lines;

    while (getline(is, line)) {
        if (lines.find(line) == lines.end()) {
            cout << line << endl;
            lines.insert(line);
        }
    }
}

/** 
 * Prints the unique lines, in the order in which they are read, of a 
 * specified input file or cin.  If a file is not specified, cin is used.
 * 
 * Input:
 * - file name to read lines from (optional)
 * 
 * Output:
 * - Prints the unique lines from the specified file or cin (if a file is 
 *   not given)
 * **/
int main(int argc, char* argv[]) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        if (input_file.is_open()) {
            print_unique_lines(input_file);
            input_file.close();
        } else {
            cerr << "ERROR: can't open " << argv[1] << endl;
            return 1;
        }
    } else {
        print_unique_lines(cin);
    }
    return 0;
}
