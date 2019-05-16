#include <string>
#include <vector>

using namespace std;
int i = 0;
vector<int> a(100001);
int solution(string arrangement) {
    int answer = 0;
    
    for(int j=0;j<arrangement.size();j++){
        if(arrangement[j] == '('){
            a.push_back(0);
        }
        if(arrangement[j] == ')'){
            if(arrangement[j-1] == '('){ //레이저면
                for(int p = 0;p<a.size();p++){
                    a[p]++;
                }
                a.pop_back();
            }
            else { //막대가 끝난 것이면
                answer += a.at(a.size()-1) + 1;
                a.pop_back();
            }
        }
    }
    return answer;
}
