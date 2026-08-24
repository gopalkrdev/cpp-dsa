#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int wordLadder(
    string beginWord,
    string endWord,
    vector<string>& wordList
) {
    unordered_set<string> words(
        wordList.begin(),
        wordList.end()
    );

    // End word dictionary me nahi hai
    if (words.find(endWord) == words.end()) {
        return 0;
    }

    queue<pair<string, int>> q;

    q.push({beginWord, 1});

    while (!q.empty()) {

        string word = q.front().first;
        int steps = q.front().second;

        q.pop();

        // Destination reached
        if (word == endWord) {
            return steps;
        }

        for (int i = 0; i < word.length(); i++) {

            char original = word[i];

            // Try a-z
            for (char ch = 'a'; ch <= 'z'; ch++) {

                word[i] = ch;

                if (words.find(word) != words.end()) {

                    q.push({
                        word,
                        steps + 1
                    });

                    // Mark visited
                    words.erase(word);
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main() {

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    int result =
        wordLadder(
            beginWord,
            endWord,
            wordList
        );

    cout << "Minimum transformations: "
         << result << endl;

    return 0;
}
