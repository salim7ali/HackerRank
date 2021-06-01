// Given airplane list of forward and backward pairs(id, distance), 
// find the routes taking forward route followed by backward route where forward_route_dit+backward_route_dist is 
// closest to the maximum allowed range of airplane  
#include<bits/stdc++.h>
using namespace std;

vector<int> closestRouteToRange()

int main(){
    vector<vector<int>> forward_routes = {{1, 3000}, {5, 5000}, {3, 7000}, {4, 10000}};
    vector<vector<int>> return_routes = {{1, 2000}, {2, 3000}, {3, 4000}, {4, 5000}};
    const int AIRPLANE_RANGE = 10000;

    vector<int> result_routes = closestRouteToRange(forward_routes, return_routes, AIRPLANE_RANGE);
}