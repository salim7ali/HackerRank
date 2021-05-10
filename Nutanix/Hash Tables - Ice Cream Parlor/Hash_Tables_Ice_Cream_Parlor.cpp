// https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem?h_l=interview&playlist_slugs%5B%5D=nutanix
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'whatFlavors' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER money
 */

void whatFlavors(vector<int> cost, int money) {
    unorderd_map<int, vector<int>> cost_map;

    for(int i=0; i<cost.size(); i++){
        int flavour_cost = cost[i]; 
        cost_map[flavour_cost].push_back(i);
    }

    for(int i=0; i<cost.size(); i++){
        int first_flavour_cost = cost[i]; 
        int second_flavour_cost = money-first_flavour_cost;

        if(second_flavour_cost!=first_flavour_cost){
            if((cost_map.find(second_flavour_cost) != cost_map.end()) && cost_map[second_flavour_cost].size() > 1){// ele exists
                cout<<i<<" "<<cost_map[second_flavour_cost][0]<<"\n";
            }
        }
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string money_temp;
        getline(cin, money_temp);

        int money = stoi(ltrim(rtrim(money_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split(rtrim(cost_temp_temp));

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
