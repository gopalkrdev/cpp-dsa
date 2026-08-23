#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestBitonicSubsequence(int arr[], int n) {

    vector<int> lis(n, 1);
    vector<int> lds(n, 1);

    // LIS ending at i
    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (arr[j] < arr[i]) {

                lis[i] = max(
                    lis[i],
                    lis[j] + 1
                );
            }
        }
    }

    // LDS starting from i
    for (int i = n - 2; i >= 0; i--) {

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[i]) {

                lds[i] = max(
                    lds[i],
                    lds[j] + 1
                );
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {

        // i is the peak
        int bitonicLength =
            lis[i] + lds[i] - 1;

        answer = max(
            answer,
            bitonicLength
        );
    }

    return answer;
}

int main() {

    int arr[] = {
        1, 11, 2, 10, 4, 5, 2, 1
    };

    int n = 8;

    cout << "Length of Longest Bitonic Subsequence: "
         << longestBitonicSubsequence(arr, n)
         << endl;

    return 0;
}
