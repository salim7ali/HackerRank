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
    
}

int main(){
    vector<int> hardDiskSpace = {8, 2, 4};
    cout<<maxOfAllMin(3, hardDiskSpace, 2)<<"\n";
}