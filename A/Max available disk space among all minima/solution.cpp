// Choose a contiguous segment of a certain number of computers, starting from the beginning of the row. Analyze the available hard disk space on each of the computers. Determine 
// the minimum available disk space within this segment. After performing these steps for the first segment, it is then repeated for 
// the next segment, continuing this procedure until the end of the row(eg: if the segment size is 4, computers 1 to 4 would be analyzed then 2 to 5, etc.)

// eg:
// numComputer=3
// hardDiskSpace= [8, 2, 4]
// segmentLength = 2

// Output: 2
// Explanation: Subarrays of size 2 are [8, 2] and [2, 4]. Thus, the initial analysis returns 2 and 2 because those are the minima for 
// the segments. Finally, the max of these values is 2.
// Thus answer is 2

#include<bits/stdc++.h>
using namespace std;

int maxOfAllMin(int numComputer, vector<int> hardDiskSpace, int segmentLength){
    int maxResult;
    multiset<int> diskSpaceSet;

    for(int i=0; i<segmentLength; i++){
        diskSpaceSet.insert(hardDiskSpace[i]);
    }

    int currMin= INT_MIN;
    for(int i=0; i+segmentLength<=numComputer; i++){
        if(i==0){
            maxResult = *diskSpaceSet.begin();
            continue;
        }
        int prev = hardDiskSpace[i-1];
        int next = hardDiskSpace[i+segmentLength-1];
        diskSpaceSet.erase(diskSpaceSet.find(prev));
        diskSpaceSet.insert(next);

        currMin = *diskSpaceSet.begin();
        if(currMin>maxResult)
            maxResult = currMin;
    }
    return maxResult;
}

int main(){
    vector<int> hardDiskSpace = {8, 2, 4};
    cout<<maxOfAllMin(3, hardDiskSpace, 2)<<"\n";

    hardDiskSpace = {8, 2, 4, 6, 1, 8, 3 ,2 , 2};
    cout<<maxOfAllMin(hardDiskSpace.size(), hardDiskSpace, 2)<<"\n";

    hardDiskSpace = {8, 2, 4, 6, 1, 8, 3 ,2 , 2};
    cout<<maxOfAllMin(hardDiskSpace.size(), hardDiskSpace, 3)<<"\n";

    hardDiskSpace = {8, 2, 4, 6, 1, 8, 3 ,2 , 2, 6, 6, 5};
    cout<<maxOfAllMin(hardDiskSpace.size(), hardDiskSpace, 3)<<"\n";
}