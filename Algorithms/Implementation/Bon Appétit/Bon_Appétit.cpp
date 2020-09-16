// https://www.hackerrank.com/challenges/bon-appetit/problem
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void bonAppetit(vector<int> bill, int notEatenInd, int b) {
    int totalCost = accumulate(bill.begin(), bill.end(), 0);
    totalCost -= bill[notEatenInd];
    int halfCost = totalCost/2;
    if(b == halfCost)
        cout<<"Bon Appetit";
    else
        cout<<(b-halfCost);
}

int main(){
    vector<int> bill ={3, 10, 2, 9};
    bonAppetit(bill, 1, 12);

    // bonAppetit(bill, 1, 7);


}