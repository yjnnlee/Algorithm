//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <string>
//#include <memory.h>
//using namespace std;
//struct A {
//	char left, right;
//};
//vector<A> v(100);
//
//void go(int now) {
//	if (v[now].left != 0) go(v[now].left);
//	cout << now << "\n";
//	if (v[now].right != 0) go(v[now].right);
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n;
//	cin >> n;
//	int nn = pow(2, n) - 1;
//	for (int i = 0; i < nn; i++) {
//		int a;
//		cin >> a;
//		while (1) {
//			int now = a;
//			//int now = root; //루트 어케구해
//			if (n < now) {
//				if (v[now].left != 0) now = v[now].left; //왼쪽 노드가 있으면 순회
//				else {
//					v[now].left = a; //없으면 만듦
//					break;
//				}
//			}
//			else {
//				if (v[now].right != 0) now = v[now].right; //오른쪽 노드가 있으면 순회
//				else {
//					v[now].right = a; //없으면 만듦
//					break;
//				}
//			}
//		}
//	}
//	go(6);
//
//	//for (int i = 0; i < nn; i++) {
//	//	if(v.empty())
//	//}
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
#include <math.h>
using namespace std;
vector<int> v(1024), res(1024);
int n;
int cnt = 0;
void go(int now, int depth) {
	if (depth == n) res[now] = v[cnt++]; //마지막값
	else {
		go(now * 2, depth + 1); //왼
		res[now] = v[cnt++]; //현재
		go(now * 2 + 1, depth + 1); //우
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int nn = pow(2, n) - 1;
	for (int i = 0; i < nn; i++) {
		cin >> v[i];
	}
	go(1, 1);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int len = 1;
		for (int j = 0; j < i; j++) len *= 2; //홀수개
		for (int j = 0; j < len; j++) {
			cout << res[cnt++] << " ";
		}
		cout << "\n";
	}
}
