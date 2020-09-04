// https://www.hackerrank.com/challenges/find-the-median/problem
// #include<bits/stdc++.h>
// applying a modified form of quickSort algorithm
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int pivot(vector<int> &arr, int L, int R){
    int i=L-1; 
    for(int j=L; j<=R-1; j++){
        if(arr[j]<arr[R]){
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[R]);
    return i+1;
}

int modifiedQuickSort(vector<int> &arr, int L, int R, int &index){
    int piv;
    if(L<R){
        piv = pivot(arr, L, R);
        if(piv == index)
            return piv;
        else if(index<piv)
            return modifiedQuickSort(arr, L, piv-1, index);
        else //piv<index
            return modifiedQuickSort(arr, piv+1, R, index);
    }
    return L;//when L==R
}

int findMedian(vector<int> arr) {
    vector<int> arrCopy = arr;
    int index = floor((arr.size())/2);
    int medianIndex = modifiedQuickSort(arrCopy, 0, arrCopy.size()-1, index);
    return arrCopy[medianIndex];
}

int main(){
    vector<int> nums = {4, 5, 0, 3, 6, 1, 2};    
    cout<<"median:"<<findMedian(nums);
}
