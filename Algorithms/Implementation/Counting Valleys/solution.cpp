// https://www.hackerrank.com/challenges/counting-valleys/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int curLevel=0;
    int transitionCount = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'U'){
            curLevel += 1;
            if(curLevel-1 == -1)
                transitionCount += 1;
        }
        else{ //s[i] == 'D'
            curLevel -= 1;
            if(curLevel+1 == 0){
                transitionCount += 1;
            }
                
        }
    }
    return floor(transitionCount/2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
