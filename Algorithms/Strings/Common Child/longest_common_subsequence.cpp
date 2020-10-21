#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int commonChild(string first, string second) {
    first.insert(0, "_");
    second.insert(0, "_");
    vector<vector<int>> countMatrix(first.length(), vector<int> (second.length(), 0)); 
    
    for(int i=1; i<countMatrix.size(); i++){
        for(int j=1; j<countMatrix.size(); j++){
            if(first[i] != second[j]){
                countMatrix[i][j] = max(countMatrix[i-1][j], countMatrix[i][j-1]);
            }else{//Match!!!
                countMatrix[i][j] = countMatrix[i-1][j-1] + 1;
            }
        }
    }
    return countMatrix[countMatrix.size()-1][countMatrix[0].size()-1];
}

int main(){
    // string first="SHINCHAN";
    // string second="NOHARAAA";
    string first="ABCDEF";
    string second="FBDAMN";

    cout<<"Longest common child length = "<<commonChild(first, second);
}