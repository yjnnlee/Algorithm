#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<int> arr)
{
    bool answer = true;
    int chk[1000000];
    for(int i=0;i<arr.size();i++){
        chk[arr[i]-1] = 1;
    }
    for(int i=0;i<arr.size();i++){
        if(!chk[i]) answer = false;
    }

    return answer;
}
