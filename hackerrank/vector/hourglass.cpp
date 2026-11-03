#include <iostream>
#include <vector>
using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int arr_size = arr.size();
    int max_sum = INT32_MIN;
    int column = 0;
    int row = 0;
    while(column<arr_size-2 && row<arr_size-2){
        int sum = 0;
        for(int j=column; j<column + 3; j++){
            sum+=arr[row][j];
        }
        for(int j=column; j<column + 3; j++){
            sum+=arr[row+2][j];
        }
        sum+=arr[row+1][column+1];
        row++;
        max_sum = sum>max_sum ? sum : max_sum;
        if(row==arr_size-2){
            row = 0;
            column++;
        }
    }
    
    return max_sum;
        
}


int main() {
    vector<vector<int>> arr = {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 2, 4, 4, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}
    };

    cout << hourglassSum(arr) << endl;

    return 0;
}