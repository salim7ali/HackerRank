#include <bits/stdc++.h>
#include <iostream>

using namespace std;


// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    vector<int> result(2);
    int subarrayStart = 0, subarraySum = 0, currSum = 0;
    int subsequenceSum = 0;
    bool hasPositiveNum = false;
    int leastNegativeNum = arr[0];
    for(int i=0; i<arr.size(); i++){
        // max subarray sum using Kadane's Algorithm
        currSum += arr[i];
        if(currSum < 0)
            currSum = 0;
        if(currSum > subarraySum)
            subarraySum = currSum;

        // max subsequence sum
        if(arr[i] >= 0){
            subsequenceSum += arr[i];
            hasPositiveNum = true;
        }

        //only used if //vector is made up of only -ve nos
        if(arr[i]>leastNegativeNum)
            leastNegativeNum = arr[i];
    }
    result[0] = subarraySum;
    result[1] = subsequenceSum;

    if(hasPositiveNum == false){//vector is made up of only -ve nos
        result[0] = leastNegativeNum;
        result[1] = leastNegativeNum;

    }
    
    // cout<<result[0]<<" "<<result[1]<<"\n";
    return result;
}


int main(){
    vector<int> maxSubarraySubsequence;
    // vector<int> arr = {2, -1, 2, 3, 4, -5};
    // vector<int> arr = {1, 2, 3, 4};
    // vector<int> arr = {-1, 2, 3, -4, 5, 10};
    vector<int> arr = {-2, -3, -2 , -4, -3, -3};
    // vector<int> arr = {-2, -3, -1, -4, -6};
    maxSubarraySubsequence = maxSubarray(arr);
    cout<<maxSubarraySubsequence[0]<<" "<<maxSubarraySubsequence[1]<<"\n";
}