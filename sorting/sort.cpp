#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/** 
 * Reads in strings and stores them in a vector.
 * 
 * Input:
 * - @param is: a reference to the input stream (a text file or cin) to 
 *  read the strings from
 * 
 * Output:
 * - A vector of strings
 * **/
vector<string> read_strings(istream &is) {
    vector<string> strings_to_sort;
    string str;

    while (getline(is, str)) {
        strings_to_sort.push_back(str);
    }

    return strings_to_sort;
}

/** 
 * Runs insertion sort.
 * 
 * Input:
 * - @param strings_to_sort: a reference to the vector of strings to be sorted
 * 
 * Output:
 * - N.A., as the function sorts the vector in place
 * **/
void insertion_sort(vector<string> &strings_to_sort) {
    for (int i = 1; i < strings_to_sort.size(); i++) {
        int next_pos = i;
        string next_val = strings_to_sort.at(next_pos);

        while (next_pos > 0 && strings_to_sort.at(next_pos - 1) > next_val) {
            strings_to_sort.at(next_pos) = strings_to_sort.at(next_pos - 1);
            next_pos--;
        }
        strings_to_sort.at(next_pos) = next_val;
    }
}


/** 
 * Runs insertion sort on a vector of strings.  To pass the strings to sort to the 
 * program, provide a text file path in the program call (ex: ./sort strings.txt).  
 * If a file is not provided, standard input (cin) will be used.  Once the strings are 
 * read in, the program will use insertion sort to sort them and print them to the 
 * console (cout).
 * 
 * Input:
 * - text file (optional)
 * 
 * Output:
 * - Prints the provided strings in alphabetical order
 * **/
int main(int argc, char const* argv[]) {
    vector<string> strings_to_sort;

    if (argc > 1) {
        ifstream input_file(argv[1]);

        if (!input_file.is_open()) {
            cerr << "Could not open " << argv[1] << endl;
            return 1;
        }

        strings_to_sort = read_strings(input_file);
        input_file.close();
    } else {
        strings_to_sort = read_strings(cin);
    }

    insertion_sort(strings_to_sort);

    for (const string &str : strings_to_sort) {
        cout << str << endl;
    }

    return 0;
}
