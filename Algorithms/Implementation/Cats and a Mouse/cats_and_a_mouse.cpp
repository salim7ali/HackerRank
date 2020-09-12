// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

string catAndMouse(int x, int y, int z) {
    int firstCatDist = abs(z-x); 
    int secondCatDist = abs(z-y);

    if(firstCatDist == secondCatDist)
        return "Mouse C"; 
    else if(firstCatDist > secondCatDist)
        return "Cat B"; 
    else // firstCatDist < secondCatDist
        return "Cat A"; 
}

int main(){
    cout<<catAndMouse(2, 5, 4)<<"\n";
    cout<<catAndMouse(1, 2, 3)<<"\n";
    cout<<catAndMouse(1, 3, 2)<<"\n";
}