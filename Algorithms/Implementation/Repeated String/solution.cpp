// https://www.hackerrank.com/challenges/repeated-string/problem?h_r=profile

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long a_in_s =0, result =0;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'a')
            a_in_s++;
    }
    
    long q = floor(n/s.length());
    
    result = q*a_in_s;
    cout<<q<<" "<<result<<"\n";
    if(s.length()*q == n)
        return result;
    long left_len = n - (s.length()*q);
    
    for(int i=0; i<left_len; i++)
        if(s[i] == 'a')
            result ++;
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
