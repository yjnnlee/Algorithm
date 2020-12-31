#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 10001;
struct Tree {
	int l, r, order, depth;
}a[MAX];

struct Find_Depths { //각 레벨에서 가장 작은/큰 값 저장
	int l = MAX, r = 0;
}fd[MAX];

int findroot[MAX];

int order = 1;
void inorder(int now, int depth) {
	if (now == -1) return;
	if(a[now].l != 0) inorder(a[now].l, depth + 1); //왼 탐색
	
	if (fd[depth].l > order) fd[depth].l = order; //현재 레벨에서 가장 작은 값보다 작으면 갱신
	if (fd[depth].r < order) fd[depth].r = order; //현재 레벨에서 가장 큰 값보다 크면 갱신
	
	a[now].order = order++; //순서
	a[now].depth = depth; //레벨

	if (a[now].r != 0) inorder(a[now].r, depth + 1); //오 탐색
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].l = y;
		a[x].r = z;
		if (y != -1) findroot[y]++;
		if (z != -1) findroot[z]++;	
	}
	
	int root; //자식 노드로 한 번도 언급되지 않은 노드가 루트
	for (int i = 1; i <= n; i++) if (findroot[i] == 0) root = i;
	
	inorder(root, 1); //중위순회 하면서 레벨과 순서 갱신
	
	int res1 = 0, res2 = 0;
	for (int i = 1; i <= n; i++) {
		if (fd[i].l != MAX) {
			int len = fd[i].r - fd[i].l + 1;
			if (res2 < len) {
				res1 = i;
				res2 = len;
			}
		}
	}
	cout << res1 << " " << res2;
}
