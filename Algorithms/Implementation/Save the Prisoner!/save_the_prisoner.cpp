#include<iostream>
using namespace std;

int saveThePrisoner(int n, int m, int s) {
    return ((m+s-2)%n)+1;
}

int main(){
    cout<<saveThePrisoner(4, 6, 2)<<"\n";
    cout<<saveThePrisoner(7, 19, 2)<<"\n";
    cout<<saveThePrisoner(3, 7, 1)<<"\n";
    cout<<saveThePrisoner(368127406, 680428368, 105517295)<<"\n";
}