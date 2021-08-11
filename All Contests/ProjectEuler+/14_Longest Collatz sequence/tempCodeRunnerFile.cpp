// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int generateCollatzSequenceStepCount(int num, map<int, int> &sequenceLen){
    // int currNum = num;
    // int currNumSteps = 0;
    
    if(sequenceLen.find(num) == sequenceLen.end()){
        if(num%2==0){
            sequenceLen[num] = 1+generateCollatzSequenceStepCount(num/2, sequenceLen);
        }else{
            sequenceLen[num] = 1+generateCollatzSequenceStepCount((num*3)+1, sequenceLen);
        }
    }else{
        return sequenceLen[num];
    }
}

int main() {
    map<int, int> sequenceLen;
    sequenceLen[1] = 0;

    // memoize the sequence
    for(int i=13; i>=2; i--){
        generateCollatzSequenceStepCount(i, sequenceLen);   
        cout<<i<<" "<<sequenceLen[i]<<"\n";
    }

    // auto it = sequenceLen.upper_bound(13);
    // it--;
    // cout<<it->first<<it->second<<"\n"; 
    return 0;
}
