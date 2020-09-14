// https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
// cases 0 to 7 represent different adjacent locations being checked for DFS
// -|-|-|-|-
// -|0|1|2|-
// -|7|Q|3|-
// -|6|5|4|-
// -|-|-|-|-
// #include<bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;

bool isValid(vector<vector<int>> &matrix, int i, int j){
    if(0<=i && i<matrix.size() && 0<=j && j<matrix[0].size())
        return true;
    return false;
}

void modifiedDFS(vector<vector<int>> &matrix, int i, int j, int &currConnCount){
    matrix[i][j] = 2; // assigning value 2 if visited 
    currConnCount += 1;

    // cases 0 to 2
    if(isValid(matrix, i-1, j-1) && matrix[i-1][j-1] == 1)//valid and unvisited
        modifiedDFS(matrix, i-1, j-1, currConnCount);
    if(isValid(matrix, i-1, j) && matrix[i-1][j] == 1)
        modifiedDFS(matrix, i-1, j, currConnCount);
    if(isValid(matrix, i-1, j+1) && matrix[i-1][j+1] == 1)
        modifiedDFS(matrix, i-1, j+1, currConnCount);
        
    // case 3
    if(isValid(matrix, i, j+1) && matrix[i][j+1] == 1)
        modifiedDFS(matrix, i, j+1, currConnCount);

    // cases 4 to 6
    if(isValid(matrix, i+1, j+1) && matrix[i+1][j+1] == 1)
        modifiedDFS(matrix, i+1, j+1, currConnCount);
    if(isValid(matrix, i+1, j) && matrix[i+1][j] == 1)
        modifiedDFS(matrix, i+1, j, currConnCount);
    if(isValid(matrix, i+1, j-1) && matrix[i+1][j-1] == 1)
        modifiedDFS(matrix, i+1, j-1, currConnCount);

    // case 7
    if(isValid(matrix, i, j-1) && matrix[i][j-1] == 1)
        modifiedDFS(matrix, i, j-1, currConnCount);
}

int connectedCell(vector<vector<int>> matrix) {
    int currConnCount =0;
    int maxConnCount=0;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[i][j] == 1){
                modifiedDFS(matrix, i, j, currConnCount);
                if(maxConnCount<currConnCount)
                    maxConnCount = currConnCount;
                currConnCount = 0;
            }
        }
    }
    return maxConnCount;
}

int main(){
    vector<vector<int>> grid = {{1, 1, 0, 0},
                                {0, 1, 1, 0},
                                {0, 0, 1, 0},
                                {1, 0, 0, 0}};
    cout<<connectedCell(grid);
}