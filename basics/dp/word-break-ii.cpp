#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void solve(
    string &s,
    int start,
    unordered_set<string> &dict,
    vector<string> &answer,
    string current
) {
    // Entire string processed
    if (start == s.length()) {
        answer.push_back(current);
        return;
    }

    string word = "";

    for (int end = start; end < s.length(); end++) {

        word += s[end];

        if (dict.count(word)) {

            string nextSentence = current;

            if (!nextSentence.empty()) {
                nextSentence += " ";
            }

            nextSentence += word;

            solve(
                s,
                end + 1,
                dict,
                answer,
                nextSentence
            );
        }
    }
}

int main() {

    string s = "catsanddog";

    vector<string> wordDict = {
        "cat",
        "cats",
        "and",
        "sand",
        "dog"
    };

    unordered_set<string> dict(
        wordDict.begin(),
        wordDict.end()
    );

    vector<string> answer;

    solve(
        s,
        0,
        dict,
        answer,
        ""
    );

    cout << "Possible sentences:" << endl;

    for (string sentence : answer) {
        cout << sentence << endl;
    }

    return 0;
}
