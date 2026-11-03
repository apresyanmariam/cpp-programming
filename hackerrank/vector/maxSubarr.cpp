#include <iostream>
#include <vector>
#include <climits>


std::vector<int> FindMaxCrossSub(const std::vector<int>& v, int low, int mid, int high){
    int leftSum = INT_MIN;
    int sum = 0;
    int leftIdx = low;
    int rightIdx = high;
    for(int i = mid; i>=low; i--){
        sum += v[i];
        if(sum > leftSum){
            leftSum = sum;
            leftIdx = i;
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for(int i = mid + 1; i<=high; i++){
        sum += v[i];
        if(sum > rightSum){
            rightSum = sum;
            rightIdx = i;
        }
    }
    return {leftIdx, rightIdx, leftSum + rightSum};

}

std::vector<int> FindMaxSub(const std::vector<int>& v, int low, int high){

    if(high == low)return {low, high, v[low]};
    int mid = (high + low) / 2;
    std::vector<int> left = FindMaxSub(v, low, mid);
    std::vector<int> right = FindMaxSub(v, mid + 1, high);
    std::vector<int> crossing = FindMaxCrossSub(v, low, mid, high);
    if(left[2] > right[2] && left[2] > crossing[2]) return left;
    if(right[2] > left[2] && right[2] > crossing[2]) return right;
    return crossing;
}


int main(){
    std::vector<int> v = {3, 5, 0, 2, -7, 1};
    std::vector<int> result = FindMaxSub(v, 0, v.size() - 1);
    std::cout<<result[2];

    return 0;
}