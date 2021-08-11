// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int longestCollatzSequence(int num, map<int, int> &sequenceLen){
    int currNum = num;
    int currNumSteps = 0;
    
    while (1){
        if(sequenceLen.find(currNum) == sequenceLen.end()){
            currNumSteps += 1;
            if(currNum%2==0){
                currNum /=2;
            }else{
                currNum = (3*currNum)+1;
            }
        }else{
            sequenceLen[num] = currNumSteps + sequenceLen[currNum];
            return sequenceLen[num];
        }
    }
    
}

int main() {
    map<int, int> sequenceLen;
    sequenceLen[1] = 0;

    // memoize the sequence
    for(int i=2; i<=5000000; i++){
        longestCollatzSequence(i, sequenceLen);   
        cout<<i<<" "<<sequenceLen[i]<<"\n";
    }

    auto it = sequenceLen.upper_bound(13);
    it--;
    cout<<it->first<<it->second<<"\n"; 
    return 0;
}
