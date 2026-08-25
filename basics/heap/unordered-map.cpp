#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string, int> marks;

    // Insert
    marks["Gopal"] = 85;
    marks["Rahul"] = 72;
    marks["Aman"] = 91;

    // Access
    cout << "Gopal marks: "
         << marks["Gopal"]
         << endl;

    // Update
    marks["Gopal"] = 90;

    cout << "Updated Gopal marks: "
         << marks["Gopal"]
         << endl;

    // Search
    if (marks.find("Rahul") != marks.end()) {

        cout << "Rahul found"
             << endl;
    }

    // Delete
    marks.erase("Aman");

    cout << "Size: "
         << marks.size()
         << endl;

    return 0;
}
