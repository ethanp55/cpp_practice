#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


/** 
 * Reads data from an input file, reformats the data, and writes it to an output 
 * file.
 * 
 * Input:
 * - The path to the input file
 * - The path to the output file
 * 
 * Output:
 * - Saves the reformatted data to the specified output file
 * **/
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " [input_file] [output_file]" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "ERROR: couldn't open " << argv[1] << endl;
        return 1;
    }

    ofstream outputFile(argv[2]);
    if (!outputFile.is_open()) {
        cerr << "ERROR: couldn't open " << argv[2] << endl;
        return 1; 
    }

    string line;
    string firstName;
    string lastName;
    int points;
    double factor;
    while (getline(inputFile, line)) {
        stringstream lineStringStream(line);
        lineStringStream >> firstName >> lastName >> points >> factor;
        outputFile << lastName << ", " << firstName << ": " << points * factor << endl;
    }
    inputFile.close();
    outputFile.close();

    return 0;
}