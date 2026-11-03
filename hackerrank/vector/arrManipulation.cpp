#include <iostream>
#include <vector>

using namespace std;


//o(nq)
// long arrayManipulation(int n, vector<vector<int>> queries) {
//     vector<long> arr(n);
//     long max_val = 0;
//     for(int i=0; i<queries.size(); i++){
//         int j = queries[i][0]-1;
//         while(j<=queries[i][1]-1){
//             arr[j] += queries[i][2];
//             max_val = max(max_val, arr[j]);
//             j++;
//         }
//     }
//     return max_val;
// }


//optimized version o(n+q) 
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0);
    long max_val = 0;
    long current = 0;

    for (int i = 0; i < queries.size(); i++) {
        int start = queries[i][0];
        int end = queries[i][1];
        int value = queries[i][2];

        arr[start] += value;
        arr[end + 1] -= value;
    }

    for (int i = 1; i <= n; i++) {
        current += arr[i];
        max_val = max(max_val, current);
    }

    return max_val;
}


int main() {
    int n = 5;

    vector<vector<int>> queries = {
        {1, 2, 100},
        {2, 5, 100},
        {3, 4, 100}
    };

    cout << arrayManipulation(n, queries) << endl;

    return 0;
}