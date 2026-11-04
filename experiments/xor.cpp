#include <iostream>

using namespace std;

void findTwoUnique(int arr[], int n) {

    int xorAll = 0;

    //XOR
    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }

    // Find the different bit
    int bit = xorAll & -xorAll;

    int a = 0;
    int b = 0;

    //make 2 groups
    for (int i = 0; i < n; i++) {

        if (arr[i] & bit)
            a ^= arr[i];
        else
            b ^= arr[i];
    }

    cout << "Unique numbers: " << a << " " << b << endl;
}

int main() {

    int arr[] = {4, 2, 7, 4, 2, 9, 7, 3, 9, 8};

    findTwoUnique(arr, 10);

    return 0;
}