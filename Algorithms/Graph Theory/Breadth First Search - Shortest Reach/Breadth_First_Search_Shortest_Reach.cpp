// https://www.hackerrank.com/challenges/bfsshortreach/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, -1);
    vector<int> queue;

    // s -= 1;// adjusting for indexing from 1 instead of 0
    int u =s;
    distance[s] =0;
    
    while(1){
        for(int i=0; i<edges.size(); i++){
            if(edges[i][0]==u && visited[edges[i][1]]==false){
                visited[edges[i][1]] = true;
                queue.push_back(edges[i][1]);
                distance[edges[i][1]] = distance[u] + 1;
            }else if(edges[i][1]==u  && visited[edges[i][0]]==false){
                visited[edges[i][0]] = true;
                queue.push_back(edges[i][0]);
                distance[edges[i][0]] = distance[u] + 1;
            }
        }
        if(queue.size() == 0)
            break;
        else{
            u = queue[0];
            queue.erase(queue.begin());
        }
    }

    distance.erase(distance.begin() + s);
    distance.erase(distance.begin());//adjusting for index starting from 1 
    for(int i=0; i<distance.size(); i++){
        if(distance[i]>0)
            distance[i] *= 6;
    }

    return distance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
