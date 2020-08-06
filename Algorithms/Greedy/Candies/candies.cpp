// https://www.hackerrank.com/challenges/candies/problem

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    vector<int> rangeVec;
    int minVal = 9999999;
    int resSum = 0;
    int startMaxInd, endMaxInd;
    bool passedStart = false;
    rangeVec.push_back(1);

    for(int i=1; i<n; i++){
        if(arr[i]>arr[i-1]){
            rangeVec.push_back(rangeVec[i-1]+1);
            if(rangeVec[i]<minVal)
                minVal= rangeVec[i];
        }
        else{// < or ==
            rangeVec.push_back(rangeVec[i-1]-1);
            if(rangeVec[i]<minVal)
                minVal= rangeVec[i];
        }
    }

    int SIZE = rangeVec.size();

    //adjusting rangeVec based on minVal
    for(int i=0; i<rangeVec.size(); i++){
        rangeVec[i] = rangeVec[i] - minVal+1;
        // resSum += rangeVec[i];
        if(i>0 && rangeVec[i-1]>rangeVec[i] && passedStart==false){
            startMaxInd = i-1;
            passedStart = true;
        }
        if(i>0 && rangeVec[i-1]<rangeVec[i]){
            endMaxInd = i;
        }
    }

    //setting all valleys to 1
    for(int i=1; i<rangeVec.size()-1; i++){
        if(rangeVec[i-1]>rangeVec[i] && rangeVec[i]<rangeVec[i+1]){
            rangeVec[i] = 1;
        }
    }
    //setting end valley edge case
    if(rangeVec[rangeVec.size()-2]>rangeVec[rangeVec.size()-1]){
        rangeVec[rangeVec.size()-1] = 1;
    }

    bool begin = false;
    //handling left to right angles
    for(int i=1; i<rangeVec.size()-1; i++){
        if(rangeVec[i-1]==1 && rangeVec[i-1]<rangeVec[i] && rangeVec[i]<rangeVec[i+1]){
            begin = true;
            
        }
        if(rangeVec[i]>rangeVec[i+1]){
            begin = false;
        }
        if(begin){
            rangeVec[i] = rangeVec[i-1]+1;
        }
    }

    //handling right to left angles
    begin = false;
    for(int i=rangeVec.size()-2; i>-1; i--){
        if(rangeVec[i+1]==1 && rangeVec[i-1]>rangeVec[i] && rangeVec[i]>rangeVec[i+1]){
            begin = true;
        }
        if(rangeVec[i-1]<rangeVec[i]){
            begin = false;
        }
        if(begin){
            rangeVec[i] = rangeVec[i+1]+1;
        }        
    }

    // //handling starting edge case
    // for(int i=0; i<startMaxInd; i++){
    //     if(i > 0){
    //         rangeVec[i] = rangeVec[i-1]+1;
    //     }else{// i == 0
    //         rangeVec[i] = 1;
    //     }
    // }

    // //handling ending edge case
    // for(int i=rangeVec.size()-1; i>endMaxInd; i--){
    //     if(i < rangeVec.size()-1){
    //         rangeVec[i] = rangeVec[i+1]+1;
    //     }else{// i == rangeVec.size()-1
    //         rangeVec[i] = 1;
    //     }
    // }

    for(int i=0; i<rangeVec.size(); i++){
        resSum += rangeVec[i];
    }
    
    return resSum;
}

int main(){
    vector<int> arr;
    // arr = {2, 4, 2, 6, 1, 7, 8, 9, 2, 1};
    
    int temp;
    fstream testCaseFile("C:\\Users\\salim\\Desktop\\Shared folder on home wifi\\programming area\\HackerRank\\Algorithms\\Greedy\\Candies\\testCase1.txt", ios_base::in);
    while (testCaseFile >> temp)
    {
        arr.push_back(temp);
    }
    
    cout<<candies(arr.size(), arr);
    
    return 0;
}