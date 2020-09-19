// https://www.hackerrank.com/challenges/sock-merchant/problem
#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int sockMerchant(int n, vector<int> ar) {
    map<int, int> colorRepCount;

    for(int i=0; i<ar.size(); i++){
        if( colorRepCount.find(ar[i]) == colorRepCount.end() ){//not present
            colorRepCount[ar[i]] = 1;
            // cout<<"0\n";
        }else{
            // cout<<"1\n";
            colorRepCount[ar[i]] += 1;
        }
    }

            // cout<<"2\n";
    for(auto &ele: colorRepCount){
            // cout<<"3\n";
        cout<<ele.first<<" "<<ele.second <<endl;
    }
    return 1;
}

int main(){
    vector<int> colors = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    cout<<sockMerchant(colors.size(), colors);
}

