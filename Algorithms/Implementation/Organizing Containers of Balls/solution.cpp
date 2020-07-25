#include <bits/stdc++.h>
#include <vector>
#include <numeric>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container){
    bool valid = true;  
    long long int totalContainer = 0;
    long long int totalType = 0;
    long long int notX = 0;
    long long int notType = 0;

    for(unsigned int i=0; i<container.size(); i++){
        // cout<<"(1)"<<totalContainer<<"\n";
        
        // totalContainer = accumulate(container[i].begin(), container[i].end(), 0);
        for(unsigned int k=0; k<container.size(); k++){
            totalContainer += container[i][k];    
            // cout<<"(4)"<<totalContainer<<"\n";
        }
        // cout<<"(2)"<<totalContainer<<"\n";
        notX = totalContainer - container[i][i];

        for(unsigned int j=0; j<container.size(); j++){
            totalType += container[j][i];    
            // cout<<"(3)"<<totalType<<"\n";
        }
        notType = totalType - container[i][i];
        
        // cout<<"totCont: "<<totalContainer<<", totType: "<<totalType<<"\n";
        if(notType != notX){
            cout<<"totCont: "<<totalContainer<<", totType: "<<totalType<<" ";
            // cout<<"totCont: "<<totalContainer<<", totType: "<<totalType<<" ";
            cout<<"i: "<<i<<"\n";
            cout<<"\n-I--\n";
            return "Impossible";
        }
            
        totalContainer = 0;
        totalType = 0;
    }
    cout<<"\n-P--\n";
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
