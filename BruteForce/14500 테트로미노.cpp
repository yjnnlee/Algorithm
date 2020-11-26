#include <iostream>
using namespace std;
int a[501][501];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 3 < m) { //ㅁㅁㅁㅁ모양은 오른쪽으로 최소한 3칸이 필요하다
				int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3]; //ㅁㅁㅁㅁ
				if (res < t) res = t;
			}
			if (i + 3 < n) {
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j]; //ㅁㅁㅁㅁ세로
				if (res < t) res = t;
			}
			if (i + 1 < n && j + 2 < m) {
				//ㅁ
				//ㅁㅁㅁ
				int t = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
				if (res < t) res = t;
			}
			if (i + 2 < n && j + 1 < m) {
				//ㅁㅁ
				//ㅁ
				//ㅁ
				int t = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j];
				if (res < t) res = t;
			}
			if (i + 1 < n && j + 2 < m) {
				//ㅁㅁㅁ
				//    ㅁ
				int t = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+2];
				if (res < t) res = t;
			}
			if (i + 2 < n && j-1 >= 0) {
				//  ㅁ
				//  ㅁ
				//ㅁㅁ
				int t = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j-1];
				if (res < t) res = t;
			}
			if (i - 1 >= 0 && j + 2 < m) {
				//    ㅁ
				//ㅁㅁㅁ
				int t = a[i][j] + a[i][j+1] + a[i][j+2] + a[i-1][j+2];
				if (res < t) res = t;
			}
			if (i + 2 < n && j + 1 < m) {
				//ㅁ
				//ㅁ
				//ㅁㅁ
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
				if (res < t) res = t;
			}
			if (i + 1 < n && j + 2 < m) {
				//ㅁㅁㅁ
				//ㅁ
				int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j];
				if (res < t) res = t;
			}
			if (i + 2 < n && j + 1 < m) {
				//ㅁㅁ
				//  ㅁ
				//  ㅁ
				int t = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (res < t) res = t;
			}
			if (i + 1 < n && j + 1 < m) {
				//ㅁㅁ
				//ㅁㅁ
				int t = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				if (res < t) res = t;
			}
			if (i - 1 >= 0 && j + 2 < m) {
				//  ㅁㅁ
				//ㅁㅁ
				int t = a[i][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j + 2];
				if (res < t) res = t;
			}
			if (i + 2 < n && j + 1 < m) {
				//ㅁ
				//ㅁㅁ
				//  ㅁ
				int t = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (res < t) res = t;
			}
			if (i + 1 < n && j + 2 < m) {
				//ㅁㅁ
				//  ㅁㅁ
				int t = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (res < t) res = t;
			}
			if (i + 2 < n && j - 1 >= 0) {
				//  ㅁ
				//ㅁㅁ
				//ㅁ
				int t = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1];
				if (res < t) res = t;
			}
			if (j + 2 < m) {				
				int t = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					//  ㅁ
					//ㅁㅁㅁ
					int t2 = t + a[i - 1][j + 1];
					if (res < t2) res = t2;
				}
				if (i + 1 < n) {
					//ㅁㅁㅁ
					//  ㅁ
					int t2 = t + a[i + 1][j + 1];
					if (res < t2) res = t2;
				}
			}
			if (i + 2 < n) {
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j + 1 < m) {
					//ㅁ
					//ㅁㅁ
					//ㅁ
					int t2 = t + a[i + 1][j + 1];
					if (res < t2) res = t2;
				}
				if (j - 1 >= 0) {
					//  ㅁ
					//ㅁㅁ
					//  ㅁ
					int t2 = t + a[i + 1][j - 1];
					if (res < t2) res = t2;
				}
			}
		}
	}
	cout << res;
}
