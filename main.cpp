#include <iostream>
#include <fstream>

using namespace std;

const string INPUT = "usernames.txt";

int main() {
    int lines_read = 0;
    int total_len = 0;
    string shortest = "";
    string longest = "";

    ifstream usernames;
    usernames.open(INPUT);

    if (!usernames) {
        return -1;
    }

    string current;
    while (getline(usernames, current)) {

        if (lines_read == 0) {
            shortest = current;
            longest = current;
        }
        
        int current_len = current.length();
        
        if (current_len < shortest.length()) {
            shortest = current;
        }
        
        if (current_len > longest.length()) {
            longest = current;
        }

        lines_read += 1;
        total_len += current_len;
    }

    usernames.close();

    float average_len = total_len / (float) lines_read;

    cout << "Total usernames read: " << lines_read << endl;
    cout << "Shortest username: " << shortest << ", length = " << shortest.length() << endl;
    cout << "Longest username: " << longest << ", length = " << longest.length() << endl;
    cout << "Average length of all usernames: " << average_len << endl;

    return 0;
}