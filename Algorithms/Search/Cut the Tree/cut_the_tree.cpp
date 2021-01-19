// https://www.hackerrank.com/challenges/cut-the-tree/problem?h_r=profile

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

int DFS(int node, map<int, vector<int>> &adjList, 
                 vector<bool> &visited, vector<int> &sumAtNode, vector<int> data, 
                 bool findAbsDiff, int &sumOfTree, int &MINdiffBWSubtrees){
    // cout<<"visited "<<node<<" ";
    visited[node] = true;

    int sum=0;
    vector<int> adjNodes = adjList[node];
    for(int i=0; i<adjNodes.size(); i++){
        if(visited[adjNodes[i]] == false){
            visited[adjNodes[i]] = true;
            sum += DFS(adjNodes[i], adjList, visited, sumAtNode, data, findAbsDiff, sumOfTree, MINdiffBWSubtrees);
        }
    }
    sumAtNode[node] = sum+data[node-1];
    if(findAbsDiff){
        int weightOfFirstSubtree = sumAtNode[node];
        int weightOfSecondSubtree = sumOfTree - weightOfFirstSubtree;

        int diffBWSubtrees = abs(weightOfFirstSubtree-weightOfSecondSubtree);
        cout<<"node:"<<node<<" "<<sumOfTree<<"\n";
        cout<<weightOfFirstSubtree<<" "<<weightOfSecondSubtree<<" "<<diffBWSubtrees<<"\n---\n";
        if(diffBWSubtrees<MINdiffBWSubtrees)
            MINdiffBWSubtrees = diffBWSubtrees;
    }
    return sumAtNode[node];
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    vector<int> sumAtNode(data.size()+1);
    vector<bool> visited(data.size()+1, false);

    map<int, vector<int>> adjList;
    // populating adjacency list as question has given edge list
    for(int i=0; i<edges.size(); i++){
        int nodeFirst = edges[i][0];
        int nodeSecond = edges[i][1];
        adjList[nodeFirst].push_back(nodeSecond);
        adjList[nodeSecond].push_back(nodeFirst);
    }
    // for(auto ele:adjList){
    //     cout<<ele.first<<"-> "<<ele.second<<"\n";
    // }

    int sumOfTree;
    int MINdiffBWSubtrees = INT_MAX;
    sumOfTree = DFS(1, adjList, visited, sumAtNode, data, false, sumOfTree, MINdiffBWSubtrees);
    visited.assign(visited.size(), false);
    cout<<visited[3];

    DFS(1, adjList, visited, sumAtNode, data, true, sumOfTree, MINdiffBWSubtrees);

    return MINdiffBWSubtrees; 
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

