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
    int M=m,W=w; 
    int passCount =0;
    int savedCandies = 0;
    int workersOrMachinesBought;
    while(1){
        int candies = M*W; 
        if(p>savedCandies+candies){//can't invest. We thus save
            savedCandies += candies;
        }else{  // invest
            savedCandies += candies;
            workersOrMachinesBought=floor(savedCandies/p);
            int spendCandies=(floor(savedCandies/p))*p;
            savedCandies -= spendCandies;

            int totalInvestment = M+W+workersOrMachinesBought;
            M = floor((totalInvestment)/2);
            W = totalInvestment-M;

        }
        passCount += 1;
        if(workersOrMachinesBought+M+W >=n)
            return passCount;
    }
}

int main(){
    cout<<minimumPasses(3, 1, 2, 12)<<"\n";    
}