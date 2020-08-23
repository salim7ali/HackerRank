// https://www.hackerrank.com/challenges/the-time-in-words/problem

#include <bits/stdc++.h>

using namespace std;

string num_to_word(int num){

    vector<string> allNumbers = {
        "zero", 
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "thirty",
        "forty",
        "fifty"};

    string converted = "";
    if(0<=num && num<=19)
        return allNumbers[num];
    else if(20<=num && num<=29){
        converted += allNumbers[20];
        converted += " ";
        converted += allNumbers[(num%10)];
    }else if(30<=num && num<=39){
        converted += allNumbers[30];
        converted += " ";
        converted += allNumbers[(num%10)];
    }else if(40<=num && num<=49){
        converted += allNumbers[40];
        converted += " ";
        converted += allNumbers[(num%10)];
    }else if(50<=num && num<=59){
        converted += allNumbers[50];
        converted += " ";
        converted += allNumbers[(num%10)];
    }
    return converted;

}

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string result = "";
    if(m == 0){
        result += num_to_word(h);
        result += " o' clock";
    }else if(1<=m && m<=14){
        result += num_to_word(m);
        if(m == 1)
            result += " minute past ";
        else
            result += " minutes past ";
        result += num_to_word(h);
    }else if(m == 15){
        result += "quarter past ";
        result += num_to_word(h);
    }else if(16<=m && m<=29){
        result += num_to_word(m);
        result += " minutes past ";
        result += num_to_word(h);
    }else if(m == 30){
        result += "half past ";
        result += num_to_word(h);
    }else if(31<=m && m<=44){
        result += num_to_word(60-m);
        result += " minutes to ";
        result += num_to_word(h+1);
    }else if(m == 45){
        result += "quarter to ";
        result += num_to_word(h+1);
    }else if(46<=m && m<=59){
        result += num_to_word(60-m);
        result += " minutes to ";
        result += num_to_word(h+1);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
