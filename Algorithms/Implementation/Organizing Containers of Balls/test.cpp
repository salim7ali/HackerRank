#include <bits/stdc++.h>
#include <vector>
#include <numeric>
using namespace std;

string organizingContainers(vector<vector<int>> container){
    bool valid = true;  
    int totalContainer = 0;
    int totalType = 0;
    int notX = 0;
    int notType = 0;

    for(unsigned int i=0; i<container.size(); i++){
        totalContainer = accumulate(container[i].begin(), container[i].end(), totalContainer);
        notX = totalContainer - container[i][i];

        for(unsigned int j=0; j<container.size(); j++){
            totalType += container[j][i];    
        }
        notType = totalType - container[i][i];
        cout<<"totCont: "<<totalContainer<<", totType: "<<totalType<<"\n";
        if(notType != notX)
            return "Impossible";
        totalContainer = 0;
        totalType = 0;
    }
    return "Possible";
}

int main(){
    vector<vector <int>> container;
    vector<int> temp;
//     999336263 998799923
// 998799923 999763019
    temp.push_back(999336263);
    temp.push_back(998799923);
    // temp.push_back(1);
    container.push_back(temp);
    temp.clear();
    temp.push_back(998799923);
    temp.push_back(999763019);
    // temp.push_back(1);
    container.push_back(temp);
    temp.clear();
    // temp.push_back(2);
    // temp.push_back(0);
    // temp.push_back(0);
    // container.push_back(temp);
    // temp.clear();


    cout<<organizingContainers(container);
}
