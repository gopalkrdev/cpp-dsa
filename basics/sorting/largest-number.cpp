#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string largestNumber(vector<int>& arr) {
    vector<string> nums;

    for (int x : arr) {
        nums.push_back(to_string(x));
    }

    sort(nums.begin(), nums.end(), compare);

    if (nums[0] == "0")
        return "0";

    string result = "";

    for (string x : nums) {
        result += x;
    }

    return result;
}

int main() {
    vector<int> arr = {3, 30, 34, 5, 9};

    cout << "Largest number: "
         << largestNumber(arr)
         << endl;

    return 0;
}
