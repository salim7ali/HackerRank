// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int lilysHomework(vector<int> arr) {
    vector<int> sortedArr;
    vector<bool> visited(arr.size(), false);
    sortedArr.assign(arr.begin(), arr.end());
    sort(sortedArr.begin(), sortedArr.end(), greater<int>());

    unordered_map<int, vector<int>> sortToUnsort;
    for(int i=0; i<arr.size(); i++)
        sortToUnsort[sortedArr[i]] = arr[i];
    
    for(auto ele: sortToUnsort)
        cout<<ele.first<<" "<<ele.second<<"\n";
    // int sortedEle, arrEle;
    int element;
    int index;

    int swapCount = 0;

    for(int i=0; i<arr.size(); i++){
        if(visited[i] == false){
            // visited[i] = true;
            int element = sortedArr[i];
            while(visited[element] != true){
                visited[element] = true;
                element = sortToUnsort[element];
                index = 
            }
        }
    }
}

int main(){
    vector<int> nums = {3, 4, 2, 5, 1};
    cout<< lilysHomework(nums);
}