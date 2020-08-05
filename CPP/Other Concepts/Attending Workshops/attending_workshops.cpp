// https://www.hackerrank.com/challenges/attending-workshops/problem

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshops{
    int startT, duration, endT;
};

struct Available_Workshops{
    int n;
    Workshop* arr = new Workshop[n];//in C: Workshop* arr = (Workshop*)malloc(sizeof(Workshop));
};

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int n){

    Available_Workshops* AW = (Available_Workshops*)malloc(sizeof(Available_Workshops));
    AW->n = n;//in C: (*AW).n 
    int end_time[n];
    // vector<pair<int, int>> vp;
    
    //generate end_time array
    for(int i=0; i<n; i++){
        end_time[i] = start_time[i] + duration[i];
        AW->arr[i]->startT = start_time[i];
        AW->arr[i]->duration = duration[i];
        AW->arr[i]->endT = end_time[i];
        // vp.push_back(make_pair(end_time[i], i));
    }
    // sort(vp.begin(), vp.end());
    // for(int i=0; i<vp.size(); i++){

    // }
    return AW;
} 

int CalculateMaxWorkshops(Available_Workshops* ptr){
    sort(ptr->)
} 
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
