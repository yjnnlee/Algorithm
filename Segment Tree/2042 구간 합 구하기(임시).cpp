#include <stdio.h>
#include <vector>
using namespace std;

long long int n, m, k, a, x, y, z;

long long init(vector<long long>&a, vector<long long> &tree, int node, int start, int end){
	if (start == end) { //node가 리프 노드인 경우
		return tree[node] = a[start]; //리프 노드는 배열의 원소를 가져야 하기 때문에
	}
	else {
		//node의 왼쪽 자식은 node*2, 오른쪽 자식은 node*2+1
		//node 구간이 [start,end]라면 왼쪽 자식은 [start,(start+end)/2],
		//오른쪽 자식은 [(start+end)/2+1, end]를 담당한다
		//왼쪽 자식과 오른쪽 자식 트리를 만들고 그 합을 저장한다
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2+1, end);
	}
}

long long sum(vector<long long>&tree, int node, int start, int end, int left, int right) {
	//node가 담당하고 있는 구간이 [start,end]고 합을 구하는 구간이 [left, right]라고 한다면
	if (left > end || right < start) return 0; //[left, right]와 [start, end]가 겹치지 않는 경우 탐색을 할 필요가 없음
	if (left <= start && end <= right) return tree[node]; //[left, right]가 [start, end]를 완전히 포함하는 경우 더 이상 호출하는 것은 비효율
	//[start, end]가 [left, right]를 완전히 포함하는 경우와 [left, right]와 [start, end]가 겹쳐져 있는 경우에는 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색을 시작해야 함
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2+1, end, left, right);
}

void update(vector<long long>&tree, int node, int start, int end, int index, long long diff) {
	//index번째 수를 val로 변경할 때 그 수가 얼마만큼 변했는지 = diff
	//diff = val - a[index]
	if (index < start || index > end) return; //포함되지 않는다면 자식도 index가 포함되지 않기 때문에 탐색을 중단
	tree[node] = tree[node] + diff; //가중치? 를 더한다
	if (start != end) { //리프 노드가인가? 리프 노드가 아닌 경우 자식도 변경해줘야 함
		update(tree, node * 2, start, (start + end) / 2, index, diff); //node 구간에 포함되는 경우에는 diff만큼 증가시켜 합을 변경
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	vector<long long> a(n), tree;

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(a, tree, 1, 0, n - 1);
	m += k;
	while (m--) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int y;
			long long int z, diff;
			scanf("%d%lld", &y, &z);
			y -= 1;
			diff = z - a[y];
			update(tree, 1, 0, n - 1, y, diff);
		}
		else if (x == 2) {
			int y, z;
			scanf("%d%d", &y, &z);
			printf("%lld\n", sum(tree, 1, 0, n - 1, y - 1, z - 1));
		}
	}
}
