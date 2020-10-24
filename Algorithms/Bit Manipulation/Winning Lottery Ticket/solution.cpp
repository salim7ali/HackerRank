#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

long winningLotteryTicket(vector<string> tickets) {
    vector<bitset<10>> digitExists(tickets.size());
    bitset<10> allBits(1023);

    int digit;
    for(int i=0; i<tickets.size(); i++){
        for(int j=0; j<tickets[i].length(); j++){//each digit in ticket chosen
            digit = ((int)(tickets[i][j]) - 48);
            if(digitExists[i][digit] == false){
                digitExists[i][digit] = true;
            }
            if(digitExists[i] == allBits)
                break;
        }
    }
    
    for(int i=0; i<digitExists.size(); i++){
        for(int j=0; j<digitExists[0].size(); j++){
            cout<<digitExists[i][j]<<" ";
        }
        cout<<"\n";
    }

    long noOfPairs = 0;
    for(int i=0; i<tickets.size(); i++){
        for(int j=i+1; j<tickets.size(); j++){
            if((digitExists[i] | digitExists[j]) == allBits)
                noOfPairs += 1;
        }
    }

    return noOfPairs;
}

int main(){
    vector<string> tickets={"129300455", "5559948277", "012334556", "56789", "123456879"};
    cout<<winningLotteryTicket(tickets);

}