#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    vector<int> lexic;
    int leastClosest;
    
    // adding corresponding ASCII values for string w in lexic 
    for(int m=0; m<w.length(); m++){
        lexic.push_back((int)w[m]);
    }
    
    // traversing right to left of lexic, finding smaller | larger state and swapping smaller value with apporoptiate value from its right
    int i;
    bool possible = false;
    for(i = lexic.size()-2; i>=0; i--){
        if(lexic[i]<lexic[i+1]){
            possible = true;
            leastClosest = i+1; //initializing
            for(unsigned int j=i+1; j<lexic.size(); j++){
                if(lexic[j]>lexic[i] && lexic[j]<lexic[leastClosest]){
                    leastClosest = j;
                }
            }
            swap(lexic[i], lexic[leastClosest]);
            break;
        }
    }

    // when chars in string are in non-increasing order 
    if(!possible)
        return "no answer";

    // rearranging values to right of index where smaller existed previously
    int minInd;
    for(unsigned int k=i+1; k<lexic.size(); k++){
        // finding min from k to end of vector
        minInd = k;
        for(unsigned int l=k+1; l<lexic.size(); l++){
            if(lexic[l] < lexic[minInd])
                minInd = l;
        }

        swap(lexic[k], lexic[minInd]);
    }

    string result;
    for(unsigned int k=0; k<lexic.size(); k++){
        result += (char)lexic[k];
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
