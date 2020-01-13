#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> arr, answer;
    for(int i=0;i<commands.size();i++){
        for(int j=array[commands[i][0]-1];j<=array[commands[i][1]-1];j++){
            arr.push_back(array[j]);
        }
        
        sort(arr.begin(), arr.end());
        answer.push_back(arr[commands[i][2]-1]);

        //arr.clear();
    }
    return answer;
}
