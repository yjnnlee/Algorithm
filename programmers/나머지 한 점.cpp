#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    for(int i=0;i<2;i++){
        if(v[0][i] == v[1][i]) ans.push_back(v[2][i]);
        else if(v[0][i] == v[2][i]) ans.push_back(v[1][i]);
        else ans.push_back(v[0][i]);
    }
    return ans;
}
