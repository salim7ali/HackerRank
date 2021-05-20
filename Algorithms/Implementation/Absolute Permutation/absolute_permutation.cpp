// https://www.hackerrank.com/challenges/absolute-permutation/problem
#include<bits/stdc++.h>
using namespace std;

vector<int> absolutePermutation(int n, int k) {
    vector<int> result(n);

    bool i_plus_k = true;
    int run =0;
    int result_sum = 0;
    for(int i=0; i<result.size(); i++){
        // i+k or i-k

        if(i_plus_k)
            result[i] = (i+1)+k;
        else
            result[i] = (i+1)-k;
        run += 1;
        
        if(run ==k){
            i_plus_k = !i_plus_k;
            run =0;
        }
        result_sum += result[i];
    }
    int sum_N = (n*(n+1))/2;
    if(sum_N != result_sum)
        result = {-1};

    return result;
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

    result = absolutePermutation(100, 2);
    disp_result(result);

}