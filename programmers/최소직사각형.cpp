#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    if(a[1] == b[1]){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    sort(sizes.begin(), sizes.end()); // 가장 작은 사이즈부터 시작한다
    int xres = sizes[0][0];
    for(int i=1;i<sizes.size();i++){
        if(xres<sizes[i][0]){ // 현재 크기에 안 들어가면
            if(xres>=sizes[i][1]){ // 돌려보는데 되면
                xres = sizes[i][1];
                // 가능
            }
            else{ // 돌려봐도 안 되면
                xres = sizes[i][0]; //새로운 사이즈로
            }
        }
    }
    sort(sizes.begin(), sizes.end(), compare); // 뒷자리 기준 정렬
    int yres = sizes[0][1]; // 가장 작은 사이즈 기준
    for(int i=1;i<sizes.size();i++){
        if(yres<sizes[i][1]){ // 현재 크기에 안 들어가면
            if(yres>sizes[i][0]){ // 돌려보는데 되면
                yres = sizes[i][0];
                // 가능
            }
            else{ // 돌려봐도 안 되면
                yres = sizes[i][1]; //새로운 사이즈로
            }
        }
    }
    
    cout<<xres<<" "<<yres;
    answer = xres*yres;
    return answer;
}

// 명함 돌리면 반대쪽 최대값이 높아지는데 그걸 계산하지 못 한 코드임



//------------------------------------------------------------------------------------------------------
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> big, small;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0]<sizes[i][1]) {
            big.push_back(sizes[i][1]);
            small.push_back(sizes[i][0]);
        }
        else{
            big.push_back(sizes[i][0]);
            small.push_back(sizes[i][1]);
        }
    }
    int xres = *max_element(big.begin(), big.end());
    int yres = *max_element(small.begin(), small.end());
    answer = xres*yres;
    return answer;
}

// 그냥 큰 수 작은 수 벡터 만들어서 비교하면 되었다... 간단하게 생각하자 
