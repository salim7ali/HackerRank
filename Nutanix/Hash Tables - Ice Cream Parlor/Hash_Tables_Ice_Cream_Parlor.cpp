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
    unordered_map<int, vector<int>> cost_map;

    for(int i=0; i<cost.size(); i++){
        int flavour_cost = cost[i]; 
        cost_map[flavour_cost].push_back(i);
    }

    for(int i=0; i<cost.size(); i++){
        int first_flavour_cost = cost[i]; 
        int second_flavour_cost = money-first_flavour_cost;

        if(second_flavour_cost!=first_flavour_cost){
            if(cost_map.find(second_flavour_cost) != cost_map.end()){// ele exists
                cout<<i+1<<" "<<cost_map[second_flavour_cost][0]+1<<"\n";
                return;
            }
        }else{ //second_flavour_cost == first_flavour_cost
            if(cost_map[second_flavour_cost].size()>1){
                cout<<cost_map[second_flavour_cost][0]+1<<" "<<cost_map[second_flavour_cost][1]+1<<"\n";
                return;
            }
        }
    }
}

int main()
{
    whatFlavors({1, 4, 5, 3, 2}, 4);
}