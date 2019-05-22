/*
#include <string>
#include <vector>

using namespace std;
int visit[100001] = {0, };
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    if(participant.size() == 1) return participant[0];
    for(int i=0;i<completion.size();i++){
        for(int j=0;j<participant.size();j++){
            if(visit[j] == 1) continue;
            if(completion[i] == participant[j]) {
                visit[j] = 1;
                break;
            }
        }
    }
    for(int i=0;i<participant.size();i++){
//        printf("%d ", visit[i]);
        if(visit[i] != 1) answer+=participant[i];
    }
    return answer;
}
//무식하게 풀기-같으면 remove하고 남은걸 출력
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    std::sort(participant.begin(), participant.end());
    std::sort(completion.begin(), completion.end());
    for(int i=0;i<participant.size();i++){
        if(participant[i] != completion[i]) {
            answer = participant[i];
            return answer;
        }
    }
}
