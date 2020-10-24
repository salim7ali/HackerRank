#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

long winningLotteryTicket(vector<string> tickets) {
    vector<vector<bool>> digitExists(tickets.size(), vector<bool> (10, 0));

    int digit;
    int digitsPresentInTicket = 0;
    for(int i=0; i<tickets.size(); i++){
        for(int j=0; j<tickets[i].length(); j++){//digits in each ticket
            digit = ((int)(tickets[i][j]) - 48);
            if(digitExists[i][digit] == false){
                digitExists[i][digit] = true;
                digitsPresentInTicket += 1;
            }
            if(digitsPresentInTicket == 10)
                break;
        }
        digitsPresentInTicket = 0;//reset
    }
    
    // for(int i=0; i<digitExists.size(); i++){
    //     for(int j=0; j<digitExists[0].size(); j++){
    //         cout<<digitExists[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    long noOfPairs = 0;
    int countOfUniqueDigits = 0;
    for(int i=0; i<tickets.size(); i++){
        for(int j=i+1; j<tickets.size(); j++){
            // cout<<tickets[i]<<" "<<tickets[j]<<"\n";    
            for(int k=0; k<10; k++){
                if((digitExists[i][k] == true) || (digitExists[j][k] == true))
                    countOfUniqueDigits += 1;
            }
            if(countOfUniqueDigits == 10)
                noOfPairs += 1;
            countOfUniqueDigits = 0;//reset count
        }
    }
    return noOfPairs;
}

int main(){
    vector<string> tickets={"129300455", "5559948277", "012334556", "56789", "123456879"};
    cout<<winningLotteryTicket(tickets);

}