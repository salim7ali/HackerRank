// https://www.hackerrank.com/challenges/dijkstrashortreach/problem
// implementing using Dijkstra's Algorithm
#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;


vector<int> shortestReach(int noOfNodes, vector<vector<int>> edges, int startNode) {
    vector<bool> fixedNodes(noOfNodes+1, false);//not using index 0
    vector<int> nodeCost(noOfNodes+1, INT_MAX);//not using index 0
    nodeCost[startNode] = 0;

    // bool firstMinNode = false;
    int minNode;
    
    int otherNode;
    int curNode = startNode;;

    for(int j=0; j<noOfNodes; j++){
        for(int i=0; i<edges.size(); i++){// relaxing for one node
            if(edges[i][0] == curNode && fixedNodes[edges[i][1]] == false){
                otherNode = edges[i][1];
                if(nodeCost[otherNode] > (nodeCost[curNode] + edges[i][2]) ){
                    nodeCost[otherNode] = (nodeCost[curNode] + edges[i][2]);
                    
                    // if(nodeCost[otherNode] < nodeCost[minNode]){
                    //     minNode = otherNode;
                    // }

                }
            }else if(edges[i][1] == curNode && fixedNodes[edges[i][0]] == false){
                otherNode = edges[i][0];
                if(nodeCost[otherNode] > (nodeCost[curNode] + edges[i][2]) ){
                    nodeCost[otherNode] = (nodeCost[curNode] + edges[i][2]); 

                    // if(nodeCost[otherNode] < nodeCost[minNode]){
                    //     minNode = otherNode;
                    // }
                }

            }
        }
        fixedNodes[curNode] = true;

        minNode = 0;
        for(int k=1; k<nodeCost.size(); k++){
            if(fixedNodes[k] == false && nodeCost[k]<nodeCost[minNode])
                minNode = k;
        }
        curNode = minNode;
    }
    // for(int i=0; i<nodeCost.size(); i++){
    //     cout<<nodeCost[i]<<" ";
    // }cout<<"\n";

    nodeCost.erase(nodeCost.begin());//removed unused index 0
    nodeCost.erase(nodeCost.begin()+startNode-1);//removed unused index 0

// setting INT_MAX distance to -1
    for(int i=0; i<nodeCost.size(); i++){
        if(nodeCost[i]==INT_MAX)
            nodeCost[i] = -1;
    }

    return nodeCost;
}

int main(){
    //                            start    end  edge weight
    vector<vector<int>> edges = {   {1,     2,      24},
                                    {1,     4,      20},
                                    {3,     1,      3},
                                    {4,     3,      12}};
    vector<int> result; 
    result = shortestReach(4, edges, 1);    
    
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
}