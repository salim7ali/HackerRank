// https://www.hackerrank.com/challenges/utopian-tree/problem
#include <bits/stdc++.h>
#include <iostream>
#include<vector>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {
    int height = 1;
    if(n == 0)
        return 1;
    for(int i=1; i<=n; i++){
        if(i%2 == 0)// even
            height += 1;
        else// i%2 == 1 odd
            height *= 2;
    }
    return height;
}

int main(){
    int cycles = 4;
    cout<<utopianTree(cycles);
}