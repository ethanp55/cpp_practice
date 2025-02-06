#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Used to make type specification easier/simpler
typedef unordered_map<string, vector<string> > word_map;

/** 
 * Helper function to read in words from the user-specified text file.  The 
 * function will read words one at a time.  A "prev" string is used to build 
 * the map.  prev is initialized to the empty string.  Each time a new word 
 * is read, it is added to prev's vector of strings; prev is then updated to be 
 * the new word (for the next iteration)
 * 
 * Input:
 * - istream object used to read from the input text file
 * 
 * Output:
 * - The unordered map of string to vector<string>
 * **/
word_map read_words(istream &is) {
    word_map words;
    string str;
    string prev = "";

    while (is >> str) {
        words[prev].push_back(str);
        prev = str;
    }

    return words;
} 

/** 
 * Helper function to randomly print n_words from the map.
 * 
 * Input:
 * - ostream object used to print the words
 * - word_map object that is the map of words used to print
 * - string representing the first key to choose words from 
 * - int representing the number of words to print
 * 
 * Output:
 * - The unordered map of string to vector<string>
 * **/
void generate_text(ostream &os, word_map& words, string prev, const int n_words) {
    os << prev << " ";

    for (int i = 0; i < n_words; i++) {
        const vector<string> possible_words = words.at(prev);
        const string random_word = possible_words.at(rand() % possible_words.size());
        os << random_word << " ";
        prev = random_word;
    }
    os << endl;
}

/** 
 * Uses an ordered map of string to vector<string> to randomly generate text.  An input 
 * text file must be passed to the program call in the second argument; the program will 
 * build the map based on this text.  The third argument must be the number of random 
 * words to generate.  Example usage: "./text_generation 1_nephi.txt 100"
 * 
 * Input:
 * - text file name used to build the map
 * - number of words to randomly generate
 * 
 * Output:
 * - A code of 1 if the input file is not given
 * - A code of 2 if the input file cannot be opened
 * - A code of 3 if the input file is given and can be opened, but the word count is not 
 *   given
 * - A code of 0 if everything works properly; also prints n random words, where n is the 
 *   third argument to the program call
 * **/
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Missing file name and count" << endl;
        return 1;
    }
    
    ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        cerr << "Could not open " << argv[1] << endl;
        return 2;
    }

    if (argc < 3) {
        cerr << "Missing word count" << endl;
        return 3;
    }
    int n_words = atoi(argv[2]);

    word_map words = read_words(input_file);
    input_file.close();
    generate_text(cout, words, "", n_words);

    return 0;
}
