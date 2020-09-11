#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>

using namespace std;

// Complete the flippingMatrix function below.
int flippingMatrix(vector<vector<int>> matrix) {
    priority_queue<int> maxHeap;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            maxHeap.push(matrix[i][j]);
        }
    }
    return maxHeap.top();
}

int main(){
    vector<vector<int>> numbers = {{112, 42, 83, 119},
                                        {56, 135, 56, 49},
                                        {15, 78, 101, 43},
                                        {62, 98, 114, 108}};
    cout<<flippingMatrix(numbers);

}