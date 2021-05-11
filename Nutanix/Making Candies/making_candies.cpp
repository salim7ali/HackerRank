#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumPasses' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER m
 *  2. LONG_INTEGER w
 *  3. LONG_INTEGER p
 *  4. LONG_INTEGER n
 */

long minimumPasses(long m, long w, long p, long n) {
    int passCount =0;
    int savedCandies = 0;
    while(1){
        int candies = m*w; 
        if(p>savedCandies+candies){//can't invest. We thus save
            savedCandies += candies;
        }else{  // invest
            savedCandies += candies;
            int totalInvestment = m+w+savedCandies;
            m = floor((totalInvestment)/2);
            w = totalInvestment-m;

            savedCandies = 0;
        }
        passCount += 1;
        if(savedCandies+m+n >=n)
            return passCount;
    }
}

int main(){
    minimumPasses(3, 1, 2, 12);    
}