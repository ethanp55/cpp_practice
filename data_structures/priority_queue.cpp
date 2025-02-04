#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;


/** 
 * Stores and grabs elements from a priority queue.  The user can enter either 
 * "add" or "take".  If "add" is used, the user then enters the name and priority 
 * of the item to be added to the queue.  If "take" is used, the top item in the 
 * queue is printed and removed from the queue.  An invalidation operation will not 
 * do anything.  An empty operation will terminate the program.
 * **/
int main(int argc, char* argv[]) {
    priority_queue<string> p_queue;
    string operation;

    while (true) {
        cout << "What do you want to do? ";
        getline(cin, operation);

        if (operation.empty()) {
            break;
        } else if (operation == "add") {
            string name;
            string priority_str;
            int priority;
            stringstream ss;

            cout << "Name: ";
            getline(cin, name);
            cout << "Priority: ";
            getline(cin, priority_str);
            priority = stoi(priority_str);

            ss << setw(2) << setfill('0') << priority;
            ss << " - " << name;
            p_queue.push(ss.str());

        } else if (operation == "take") {
            if (p_queue.empty()) {
                cout << "There are no more people in line" << endl;
            } else {
                cout << p_queue.top() << endl;
                p_queue.pop();
            }
        } else {
            cerr << operation << " isn't a valid operation" << endl;
        }
    }

    return 0;
}
