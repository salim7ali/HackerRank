// #include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int maxSum = INT_MIN;
    int curSum;
    for(int i=0; i<=(arr.size()-3); i++){
        for(int j=0; j<=(arr[0].size()-3); j++){
            curSum = (arr[i][j] + arr[i][j+1] + arr[i][j+2]) + arr[i+1][j+1] + (arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]);
            if(curSum > maxSum)
                maxSum = curSum; 
        }
    }
    return maxSum;
}

int main(){
    vector<vector<int>> arr = { {1, 1, 1, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {1, 1, 1, 0, 0, 0},
                                {0, 0, 2, 4, 4, 0},
                                {0, 0, 0, 2, 0, 0},
                                {0, 0, 1, 2, 4, 0}};
    cout<<hourglassSum(arr);
}
