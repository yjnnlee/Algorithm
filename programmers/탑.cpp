#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int flag = 0;
    for(int i=0;i<heights.size();i++){
        for(int j=i-1;j>=0;j--){
            if(heights[i] < heights[j]){ //막힘
                answer.push_back(j+1);
                flag = 1; //막혔음
                break;
            }
        }
        if(!flag) answer.push_back(0); //안막혔으면 0
        flag = 0;
    }    
    return answer;
}
