// https://www.hackerrank.com/challenges/angry-children/problem
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;

void dispVect(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }cout<<"\n";
}

int maxMin(int k, vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int minUnfairness = INT_MAX;

    for(int i=0; i+k<=arr.size(); i++){
        if(arr[i+k-1] - arr[i] < minUnfairness)
            minUnfairness = arr[i+k-1] - arr[i];
    }
    return minUnfairness;
}


int main(){
    srand(time(0));
    int n = rand()%10;
    vector<int> numbers;
//     vector<int> numbers = {
// 1,
// 2,
// 1,
// 2,
// 1};
    
    for(int i=0; i<n; i++){
        numbers.push_back(rand()%100);
    }
    dispVect(numbers);

    int k = rand()%n;
    // int k = 2;
    cout<<"minUnfairness:"<<maxMin(k, numbers)<<" k:"<<k<<"\n";
    dispVect(numbers);

}