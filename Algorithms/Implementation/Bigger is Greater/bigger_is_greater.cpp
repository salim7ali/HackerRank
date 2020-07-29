// https://www.hackerrank.com/challenges/bigger-is-greater/problem

#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    vector<int> lexic;
    int leastClosest;
    
    for(int m=0; m<w.length(); m++){
        lexic.push_back((int)w[m]);
    }
    
    unsigned int i;
    for(i = lexic.size()-2; i>=0; i--){
        if(lexic[i]<lexic[i+1]){
            for(unsigned int j=i+1; j<lexic.size(); j++){
                leastClosest = i+1;
                if(lexic[j]>lexic[i] && lexic[j]<lexic[leastClosest]){
                    leastClosest = j;
                }
            }
            swap(lexic[i], lexic[leastClosest]);
            break;
        }
    }

    int minInd;
    for(unsigned int k=i+1; k<lexic.size(); k++){
        // finding min from k to end of vector
        minInd = k;
        for(unsigned int l=k+1; l<lexic.size(); l++){
            if(lexic[l] < lexic[minInd])
                minInd = l;
        }

        swap(lexic[k], lexic[minInd]);
    }

    string result;
    for(unsigned int k=0; k<lexic.size(); k++){
        result += (char)lexic[k];
    }

    return result;
}

int main()
{
    cout<<biggerIsGreater("dhck");
}