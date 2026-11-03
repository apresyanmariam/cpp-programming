#include <iostream>
#include <vector>
using namespace std;


vector<int>& rotLeft(vector<int>& a, int d) {
    int size_a = a.size();
    int count = 0;
    while (count<d){
        int num = a[0];
        for(int i=1; i<size_a; i++){
            a[i-1] = a[i];
        }
        a[size_a-1] = num;
        count++;
    }
    return a;
}



int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    rotLeft(arr, 3);
    for(int i =0; i<arr.size(); i++) cout << arr[i] << " ";

    return 0;
}