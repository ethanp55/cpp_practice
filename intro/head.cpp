#include <fstream>
#include <iostream>
using namespace std;


/** 
 * Helper function to read n lines from an input stream is
 * 
 * Input:
 * - is, the input stream to read from (a file or cin)
 * - n, the number of lines to read from is
 * 
 * Output:
 * - Prints up to n lines from is; if there are fewer than n lines, 
 *   every line is printed.
 * **/
void print_head(istream &is, const int &n) {
    int n_read = 0;
    string line;

    while (getline(is, line) && n_read < n) {
        cout << line << endl;
        n_read++;
    }
}


/** 
 * Prints the head of an input.  The number of lines to be 
 * printed can be modified by passing -n as the first argument 
 * (ex: ./head -5).  A file to read from can be passed, with or 
 * without the -n argument (ex: ./head -5 foo.txt OR ./head foo.txt).  
 * If no file is given to read from, the program reads from cin.  If 
 * the number of lines to read is not specified, the default is set 
 * to 10.
 * 
 * Input:
 * - -n (optional)
 * - file name to read lines from (optional)
 * 
 * Output:
 * - Prints the head of an input (a file or cin)
 * **/
int main(int argc, char* argv[]) {
    int n = 10;
    int file_argv_idx = 1;

    if (argc > 1 && argv[1][0] == '-') {
        n = atoi(&argv[1][1]);
        file_argv_idx = 2;
    }

    if (argc > file_argv_idx) {
        ifstream input_file(argv[file_argv_idx]);

        if (input_file.is_open()) {
            print_head(input_file, n);
            input_file.close();
        } else {
            cerr << "ERROR: can't open " << argv[file_argv_idx] << endl;
            return 1;
        }
    } else {
        print_head(cin, n);
    }

    return 0;
}
