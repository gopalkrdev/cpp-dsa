#include <iostream>
using namespace std;

void findUnion(int arr1[], int n1, int arr2[], int n2) {
    int i = 0;
    int j = 0;

    cout << "Union: ";

    while (i < n1 && j < n2) {

        if (arr1[i] < arr2[j]) {
            if (i == 0 || arr1[i] != arr1[i - 1]) {
                cout << arr1[i] << " ";
            }
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            if (j == 0 || arr2[j] != arr2[j - 1]) {
                cout << arr2[j] << " ";
            }
            j++;
        }
        else {
            if (i == 0 || arr1[i] != arr1[i - 1]) {
                cout << arr1[i] << " ";
            }
            i++;
            j++;
        }
    }

    while (i < n1) {
        if (i == 0 || arr1[i] != arr1[i - 1]) {
            cout << arr1[i] << " ";
        }
        i++;
    }

    while (j < n2) {
        if (j == 0 || arr2[j] != arr2[j - 1]) {
            cout << arr2[j] << " ";
        }
        j++;
    }

    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 3, 5, 6};

    int n1 = 5;
    int n2 = 4;

    findUnion(arr1, n1, arr2, n2);

    return 0;
}
