#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
/*
* 설명: https://foxtrotin.tistory.com/547
*/
const int MAX = 1000000;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	
	vector<long long> d(MAX+1, 1); //1로 초기화
	for (int j = 2;j <= MAX;j++) { //전체 수에 대해
		for (int k = 1;j * k <= MAX;k++) { //j의 배수만큼 뛰면서 합 구하기
			d[j * k] += j; //d[i] = i의 모든 약수 총합
		}
	}
	cin >> n;
	vector<long long> num(n+1);
	int last = 0;
	for (int i = 0;i < n;i++) {
		cin >> num[i];
		if (num[i] > last) last = num[i]; //이 아래에서 1~x의 약수의 총합의 총합을 구하는데, 그냥 1~MAX까지 다 구해버리면 시간초과 난다
		//입력으로 온 수 중에 가장 큰 수까지만 구하면 통과
	}
	vector<long long> s(last +1); //1~x까지 자연수들의 "약수의 총합"의 총합
	for (int i = 1;i <= last;i++) {
		s[i] = s[i - 1] + d[i];
	}
//	for (int i = 1;i <= 7;i++) cout << s[i] << endl;
	for (int i = 0;i < n;i++) {
		cout << s[num[i]] << "\n";
	}
}
