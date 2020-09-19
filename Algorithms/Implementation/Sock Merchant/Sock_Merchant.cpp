// https://www.hackerrank.com/challenges/sock-merchant/problem
// Reference for hashmap: https://www.geeksforgeeks.org/check-key-present-cpp-map-unordered_map/
#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int sockMerchant(int n, vector<int> ar) {
    map<int, int> colorRepCount;

    for(int i=0; i<ar.size(); i++){
        if( colorRepCount.find(ar[i]) == colorRepCount.end() ){//not present
            colorRepCount[ar[i]] = 1;
        }else{
            colorRepCount[ar[i]] += 1;
        }
    }

    int matchingPairCount = 0;
    for(auto &ele: colorRepCount){
        matchingPairCount += floor((ele.second)/2);
        // cout<<ele.first<<" "<<ele.second <<endl;
    }
    return matchingPairCount;
}

int main(){
    vector<int> colors = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    cout<<sockMerchant(colors.size(), colors);
}

