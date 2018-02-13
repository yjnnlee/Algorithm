#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int n, t;


//struct P {
//	int x, y;
//}; P p;

//bool compare(const pair<int, int> &x, const pair<int, int>&y) {
//	if (x.first == y.first) { //첫번째 수가 같다면
//		return x.second > y.second; //y비교
//	}
//	//	return x.first > y.first; //첫 번째 수가 더 큰 수가 앞으로 가게 한다 (내림차순)
//	return x.first < y.first;
//	//첫 번째 수가 더 작은 수가 앞으로 (오름차순) 그냥 sort랑 결과가 같음
//}
typedef pair<int, int> p;
bool compare(const p &x, const p &y) {
	return x.second < y.second;
}
/*unknown-type std::less<void> 어쩌구 함수 템플릿을 특수화하지 못했다는 에러&
오퍼레이터 뭐시기랑 일치하는 오버로드 함수 없다고 뜨면 stable_sort로 바꾸고 compare 함수
추가해서 정렬해줌 -> 아님 안됨. 저 에러는 lower_bound 함수에서 뜨는듯. 삭제해버림
*/

vector<p> a;
//int f(int x) {
//	return lower_bound(a.begin(), a.end(), x) - a.begin();
//}
int main() {
	//vector<P> a[100000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		a.push_back({ t,i + 1});
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) { //좌표압축
		a[i].first = i;
	}
	sort(a.begin(), a.end(), compare);
	a.erase(unique(a.begin(), a.end()), a.end());
	//for (int i = 0; i < a.size(); i++) {
	//	printf("%d ", a[i].first);
	//}
	//printf("\n");
	for (int i = 0; i < a.size(); i++) {
		printf("%d ", a[i].first);
	}
//	printf("\n>%d", f(83));
}
//#include <stdio.h>
//int n, res, col[1000], inc[1000], dec[1000], w, h, num, k;
////int res[1000];
//struct P {
//	int x, y;
//};
//P map[10000];
//
//int main() {
//		scanf("%d%d%d%d", &w, &h, &num, &k);
//		for (int i = 0; i < num; i++) {
//			scanf("%d%d", &map[i].x, &map[i].y);
//		}
//}
