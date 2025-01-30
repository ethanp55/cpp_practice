#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


/** 
 * Reads lines from a file and prints the line with the most words
 * 
 * Input:
 * - The path to the input file
 * 
 * Output:
 * - Prints the line with the most words
 * **/
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " [input_file]" << endl;
        return 1;
    }

    ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        cerr << "ERROR: couldn't open " << argv[1] << endl;
        return 1;
    }

    string line;
    int longest_length = 0;
    string longest_line;
    while (getline(input_file, line)) {
        string word;
        stringstream line_ss(line);
        int length = 0;

        while (line_ss >> word) {
            length += 1;
        }

        if (length > longest_length) {
            longest_length = length;
            longest_line = line;
        }
    }

    input_file.close();

    cout << longest_line << endl;

    return 0;
}