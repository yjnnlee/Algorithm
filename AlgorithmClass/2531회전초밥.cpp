#include <stdio.h>
#include <vector>
using namespace std;

int n, d, k, c;
int eat[3001]; //연속으로 먹는 접시
vector<int> chobab;
int chk[30001]; //큐에 새로 들어왔을 때 이미 먹은 접시인가?
int  cnt = 1; //몇 개 먹었나? 쿠폰으로 이미 하나를 먹었음
int index = 0;

int main() {
	int temp;
	scanf("%d%d%d%d", &n, &d, &k, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		chobab.push_back(temp);
		chk[temp] = 1;
	}
	for (int i = 0; i < n-1; i++) {
		chobab.push_back(chobab[i]);
	}
	chk[c] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			eat[j] = chobab.front(); //k개 담아둠
			if (chobab.front() != chk[chobab.front()]) {
				eat[j]  
			}
			++index;
		}

		if (chobab[index] != c && chk[chobab[index]] != 1) { 
			//새로 들어오는 초밥이 쿠폰에 있는게 아니고 이미 있는거랑 중복되는게 아니면
			eat[i] = 
		}
	}
}