// https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    vector<vector<int>> result(a.size()+1, vector<int> (b.size()+1));
    vector<int> subsequence;

    // adding element at beginning of vectors a and b to make reference to result vector easier
    a.insert(a.begin(), INT_MIN);
    b.insert(b.begin(), INT_MIN);

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            if(i==0 || j==0)
                result[i][j] = 0;
            else if(a[i] != b[j])
                result[i][j] = max(result[i][j-1], result[i-1][j]);
            else //a[i] == b[j]
                result[i][j] = result[i-1][j-1] + 1;
        }
    }
    
    int row = result.size()-1, col = result[0].size()-1;
    while(result[row][col] != 0){
        if(a[row] != b[col]){
            if(result[row][col] == result[row-1][col])
                row -= 1;
            else
                col -= 1;
        }else {// a[row] == b[col]
            subsequence.push_back(a[row]);
            row -= 1;
            col -= 1;
        }
    }
    reverse(subsequence.begin(), subsequence.end());
    return subsequence;
    // cout<<result[result.size()-1][result[0].size()-1]; 

}

void displayResult(vector<int> first, vector<int> second, vector<int> result){
    cout<<"First:\n";
    for(int i=0; i<first.size(); i++){
        cout<<first[i]<<" ";
    }cout<<"\n";
    cout<<"Second:\n";
    for(int i=0; i<second.size(); i++){
        cout<<second[i]<<" ";
    }cout<<"\n";
    cout<<"Result:\n";
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

}

int main(){
    vector<int> first = {1, 2, 3, 4, 1};
    vector<int> second = {3, 4, 1, 2, 1, 3};

    vector<int> result = longestCommonSubsequence(first, second);
    displayResult(first, second, result);
}