#include <iostream>
using namespace std;

void findIntersection(int arr1[], int n1, int arr2[], int n2) {
    int i = 0;
    int j = 0;

    cout << "Intersection: ";

    while (i < n1 && j < n2) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 6};
    int arr2[] = {2, 3, 5, 6, 8};

    int n1 = 5;
    int n2 = 5;

    findIntersection(arr1, n1, arr2, n2);

    return 0;
}
