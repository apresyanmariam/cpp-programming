#include <iostream>
#include <vector>

using namespace std;


int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    for(int i = 0; i<arr.size(); i++){
        bool right_position = false;
        while(!right_position){
            if(arr[i] == i+1)right_position=true;
            else{
                int value = arr[i];
                arr[i] = arr[value-1];
                arr[value-1] = value;
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {

    vector<int> arr = {1, 3, 5, 2, 4, 6, 7};

    int result = minimumSwaps(arr);

    cout << "Minimum swaps: " << result << endl;

    return 0;
}