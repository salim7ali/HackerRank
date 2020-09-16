// #include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int divSumPairCount =0;

    for(int i=0; i<ar.size(); i++){
        for(int j=i+1; j<ar.size(); j++){
            if( ((ar[i]+ar[j])%k) == 0 )
                divSumPairCount += 1;
        }
    }
    return divSumPairCount;
}

int main(){
    vector<int> numbers = {1, 3, 2, 6, 1, 2};
    cout<<divisibleSumPairs(6, 3, numbers);
}