#include <bits/stdc++.h>

using namespace std;


// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    //                          J,  F,  M,  A,  M, J, Jul,  A,  S 
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 31 };
    int day;
    string date ="";
    int sumTilAug = 243;
    bool leap;

    // if(year%400==0 || ((year%4==0) && (year%100 != 0))){
    //     // daysInMonth[1] = 29;
    //     sumTilAug += 1;
    //     cout<<"leap";
    // }
    if(year%400 ==0 )
        leap = true;
    else if(year%100 == 0)
        leap = false;
    else if(year%4 == 0)
        leap = true;
    else
        leap = false;

    if(leap)
        sumTilAug += 1;
    // for(int i=0; i<8; i++){
    //     sumTilAug += daysInMonth[i];
    // }
    day = 256-sumTilAug;

    date += to_string(day);
    date += '.';
    date += "09";
    date += '.';
    date += to_string(year);
    return date;
}

int main(){
    cout<<dayOfProgrammer(1800);
}