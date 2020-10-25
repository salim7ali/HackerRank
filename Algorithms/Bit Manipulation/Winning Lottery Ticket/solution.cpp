#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

long winningLotteryTicket(vector<string> tickets) {
    vector<bitset<10>> digitExists(tickets.size());
    bitset<10> allBits(1023);
    vector<int> freqOfNumPat(1024, 0);
    // cout<<freqOfNumPat.size()<<"\n\n";

    int digit;
    bitset<10> revForUlongFunc;
    for(int i=0; i<tickets.size(); i++){
        for(int j=0; j<tickets[i].length(); j++){//each digit in ticket chosen
            digit = ((int)(tickets[i][j]) - 48);
            if(digitExists[i][digit] == false){
                digitExists[i][digit] = true;
            }
            if(digitExists[i] == allBits)
                break;
        }
        for(int ind=0; ind<digitExists[i].size(); ind++)
            revForUlongFunc[9-ind] = digitExists[i][ind];
        
        cout<<revForUlongFunc<<" -  "<<digitExists[i]<<"  ["<<revForUlongFunc.to_ulong()<<"]\n";
        freqOfNumPat[revForUlongFunc.to_ulong()] += 1;
    }

    long noOfPairs = 0;
    bitset<10> first;
    bitset<10> second;
    for(int i=0; i<=freqOfNumPat.size()-2; i++){
        first = i;
        for(int j=i+1; j<=freqOfNumPat.size()-1; j++){
            second = j;
            if((first | second) == allBits)
                noOfPairs += ((freqOfNumPat[i])*(freqOfNumPat[j]));
        }
    }

    if(freqOfNumPat[1023] >1){
            int n=freqOfNumPat[1023];
            noOfPairs += ((n*(n-1))/2);
    }

    // cout<<noOfPairs;
    return noOfPairs;
}

int main(){
    //                       1009         183           1016        31        511
    vector<string> tickets={"129300455", "5559948277", "012334556", "56789", "123456879"};
    cout<<winningLotteryTicket(tickets);

}