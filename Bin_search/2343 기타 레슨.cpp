#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
int big, sum = 0;

int bin(int bigg, int summ) {
	int l = bigg, r = sum, mid;
	//l: 레슨 중 가장 긴 시간(다 담아야 하니까), r: 레슨 길이의 총 합

	while (l <= r) {
		mid = (l + r) / 2;
		int now = 0;
		int tmpsum = 0;
		for (int i = 0; i < n; i++) {
			if (tmpsum + v[i] > mid) { //mid보다 크면
				now++; //블루레이+1
				tmpsum = 0; //합초기화
			}
			tmpsum += v[i];
		}
		now++;

		if (now <= m) r = mid - 1; //m개의 블루레이 개수 비교
		else l = mid + 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v.push_back(x);
		if (x > big) big = x;
		sum += x;
	}
	cout << bin(big, sum);
}
