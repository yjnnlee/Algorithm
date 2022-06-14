#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> v = {781, 156, 31, 6, 1};
    map<char, int> m;
    m.insert({'A',0});
    m.insert({'E',1});
    m.insert({'I',2});
    m.insert({'O',3});
    m.insert({'U',4});

    int i =0;
    for(auto x: word){
        answer += m[x] * v[i] + 1;
        i++;
    }
    
    return answer;
}
