#include <bits/stdc++.h>

using namespace std;

// Complete the longestIncreasingSubsequence function below.
int longestIncreasingSubsequence(vector<int> arr) {
    vector<int> LIS(arr.size(), 1);
    // vector<int> prevIndex(arr.size());
    int result =1, resIndex;
    
    for(int i=1; i<arr.size(); i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i] && LIS[j]+1>LIS[i]){
                LIS[i] = LIS[j] +1;
                // prevIndex[i] = j;
                result = max(LIS[i], result);
            }
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = longestIncreasingSubsequence(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
