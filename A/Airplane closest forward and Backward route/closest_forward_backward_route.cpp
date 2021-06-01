// Given airplane list of forward and backward pairs(id, distance), 
// find the routes taking forward route followed by backward route where forward_route_dit+backward_route_dist is 
// closest to the maximum allowed range of airplane  
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> closestRouteToRange(vector<vector<int>> forward_routes, vector<vector<int>> return_routes, const int &AIRPLANE_RANGE){
    multiset<pair<int, int>> return_set;
    for(int i=0; i<return_routes.size(); i++)
        return_set.insert({return_routes[i][1], return_routes[i][0]});

    int closest_total = INT_MIN;
    vector<vector<int>> curr_closest_result;
    for(int i=0; i<forward_routes.size(); i++){
        int curr_forward_id = forward_routes[i][0];
        int curr_forward_dist = forward_routes[i][1];

        int curr_remaining_dist = AIRPLANE_RANGE - curr_forward_dist;
        auto it = return_set.upper_bound({curr_remaining_dist, INT_MAX});
        if(it == return_set.begin())
            continue;
        it--;

        int curr_return_id = it->second;
        int curr_return_dist = it->first;

        if(closest_total < curr_forward_dist + curr_return_dist){ //better result
            closest_total = curr_forward_dist + curr_return_dist;
            curr_closest_result.clear();
            curr_closest_result.push_back({curr_forward_id, curr_return_id});
        }else if(closest_total == curr_forward_dist + curr_return_dist){ // another route with total dist same as closest total
            curr_closest_result.push_back({curr_forward_id, curr_return_id});
        }
    }
    
}

int main(){
    vector<vector<int>> forward_routes = {{1, 3000}, {5, 5000}, {3, 7000}, {4, 10000}};
    vector<vector<int>> return_routes = {{1, 2000}, {2, 3000}, {3, 4000}, {4, 5000}};
    const int AIRPLANE_RANGE = 10000;

    vector<vector<int>> result_routes = closestRouteToRange(forward_routes, return_routes, AIRPLANE_RANGE);
}