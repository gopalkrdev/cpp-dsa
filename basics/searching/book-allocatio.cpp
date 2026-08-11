#include <iostream>
#include <algorithm>
using namespace std;

bool canAllocate(int books[], int n, int students, int maxPages) {
    int studentCount = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {

        if (books[i] > maxPages) {
            return false;
        }

        if (pages + books[i] <= maxPages) {
            pages += books[i];
        }
        else {
            studentCount++;
            pages = books[i];
        }
    }

    return studentCount <= students;
}

int allocateBooks(int books[], int n, int students) {

    if (students > n) {
        return -1;
    }

    int low = *max_element(books, books + n);
    int high = 0;

    for (int i = 0; i < n; i++) {
        high += books[i];
    }

    int answer = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (canAllocate(books, n, students, mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {

    int books[] = {12, 34, 67, 90};
    int n = 4;
    int students = 2;

    int result = allocateBooks(books, n, students);

    cout << "Minimum maximum pages: " << result << endl;

    return 0;
}
