#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

//start~end에서 left~right의 최대값 찾기
int maximum(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0; //범위에 없음
	if (left <= start && end <= right) return tree[node]; //완전히 겹쳐서 그냥 리턴
	return max(maximum(tree, node * 2, start, (start + end) / 2, left, right), 
				maximum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

void update(vector<int>& tree, int node, int start, int end, int i, int value) {
	if (i > end || i < start) return; //범위에 없음
	tree[node] = max(tree[node], value);
	if (start != end) { //리프 노드가 아니면 자식도 변경
		update(tree, node * 2, start, (start + end) / 2, i, value);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, value);
	}
}

const int MAX = 1000000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n); //원래 배열
	vector<int> b(n); //중복을 없앨 배열
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	//unique: 중복인 값을 맨 뒤로 보낸다(반환값-쓰레기값의 첫위치), erase: 범위를 지운다
	map<int, int> d;
	for (int i = 0; i < b.size(); i++) {
		d[b[i]] = i + 1; //map[key] = value;
	}
	for (int i = 0; i < n; i++) {
		a[i] = d[a[i]];
	}

	int h = (int)ceil(log2(MAX)); //트리의 높이는 log2(MAX)의 올림
	int tree_size = (1 << (h + 1)); //h+1번째 비트를 킨다
	vector<int> tree(tree_size);
	int ans = 0;
	for (int i = 0, num; i < n; i++) {
		num = a[i];
		int cur = maximum(tree, 1, 1, MAX, 1, num - 1); //[1, A[i]-1]구간의 최대값
		if (ans < cur + 1) { //최대값+1이 LIS?
			ans = cur + 1;
		}
		update(tree, 1, 1, MAX, num, cur + 1); //tree갱신
	}
	cout << ans;
	return 0;
}
