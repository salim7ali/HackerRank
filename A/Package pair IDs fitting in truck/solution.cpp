// In Amazon’s sort center, a computer system decides what packages are to be loaded on what trucks. All rooms and spaces are abstracted into space units which is represented as an integer. For each type of truck, they have different space units. For each package, they will be occupying different space units. As a software development engineer in sort centers, you will need to write a method:

// Given truck space units and a list of product space units, find out exactly TWO products that fit into the truck. You will also implement an internal rule that the truck has to reserve exactly 30 space units for safety purposes. Each package is assigned a unique ID, numbered from 0 to N-1.

// Assumptions: You will pick up exactly 2 packages. You cannot pick up one package twice. If you have multiple pairs, select the pair with the largest package.

// Input: The input to the function/method consists of two arguments : truckSpace , an integer representing the truck space. packagesSpace , a list of integers representing the space units occupying by packages.

// Output: Return a list of integers representing the IDs of two packages whose combined space will leave exactly 30 space units on the truck.

// Example Input : truckSpace = 90 packagesSpace = [1, 10, 25, 35, 60] Output : [2, 3] Explanation : Given a truck of 90 space units, a list of packages space units [1, 10, 25, 35, 60], Your method should select the third(ID-2) and fourth(ID-3) package since you have to reserve exactly 30 space units.
// https://pdfcoffee.com/amazon-coding-question-pdf-free.html

#include<bits/stdc++.h>
using namespace std;

pair<int, int> selectPackages(int truckSpace, int numPackages, vector<int> packageSpace){
    int availableSpace = truckSpace-30;

    multiset<int> setPackageSpace; 
    for(int i=0; i<packageSpace.size(); i++){
        setPackageSpace.insert(packageSpace[i]);
    }

    for(auto it = setPackageSpace.begin(); it != setPackageSpace.end(); it++){
        int firstEle = *it;
        int expectedSecondEle = availableSpace - firstEle;

        // int firstEleIndex = it-setPackageSpace.begin();
        // int expectedSecondEleIndex = it-setPackageSpace.begin();
        
        auto firstIt = setPackageSpace.lower_bound(expectedSecondEle);
        auto secondIt = setPackageSpace.upper_bound(expectedSecondEle);
        secondIt--;

        if(firstEle != expectedSecondEle){
            return {firstIt-setPackageSpace.begin(), secondIt-setPackageSpace.begin()};
        }
        if(firstIt == secondIt)
            continue;
        else{
            return {firstIt-setPackageSpace.begin(), secondIt-setPackageSpace.begin()};
        }
    }
}

int main(){
    vector<int> packageSpace = {1, 10, 25, 35, 60};
    pair<int, int> resultPair = selectPackages(90, packageSpace.size(), packageSpace);
    cout<<resultPair.first<<" "<<resultPair.second<<"\n";
}