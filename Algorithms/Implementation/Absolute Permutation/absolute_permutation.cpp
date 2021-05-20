// https://www.hackerrank.com/challenges/absolute-permutation/problem
#include<bits/stdc++.h>
using namespace std;



vector<int> absolutePermutation(int n, int k) {

}

void disp_result(vector<int> nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }cout<<"\n";
}

int main(){
    vector<int> result;
    result = absolutePermutation(4, 2);
    disp_result(result);

    result = absolutePermutation(2, 1);
    disp_result(result);

    result = absolutePermutation(3, 0);
    disp_result(result);

    result = absolutePermutation(3, 2);
    disp_result(result);

}