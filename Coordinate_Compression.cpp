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

struct mystruct {
	int x;
	bool operator <(const mystruct &s) const { return x < s.x; }
};

/*unknown-type std::less<void> 어쩌구 함수 템플릿을 특수화하지 못했다는 에러&
오퍼레이터 뭐시기랑 일치하는 오버로드 함수 없다고 뜨면 stable_sort로 바꾸고 compare 함수
추가해서 정렬해줌 -> 아님 안됨. 저 에러는 lower_bound 함수에서 뜨는듯. 삭제해버림
(추가) 여기서 에러뜬 이유: lowerbound 쓴 함수 f는 int형을 반환하는데 pair vector를 집어넣어서 그랬음
int벡터를 따로 만들어서 t값만 넣은 다음에 int벡터에서 페어벡터에 있는 t값을 찾아서 해결
*/

vector<p> a;
vector<int> d;
int f(int x) {
	return lower_bound(d.begin(), d.end(), x) - d.begin();
}

int main() {
	//vector<P> a[100000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);		
		a.push_back({ t,i}); //make_pair랑 같은거 첨알음
		d.push_back(t);
	}

	sort(d.begin(), d.end());
//	sort(a.begin(), a.end());
	//for (int i = 0; i < a.size(); i++) { //좌표압축
	//	a[i].first = i+1;
	//}

//	sort(a.begin(), a.end(), compare);
	d.erase(unique(d.begin(), d.end()), d.end());
	//a.resize(unique(a.begin(), a.end()) - a.begin());
//	a.erase(unique(a.begin(), a.end()), a.begin());
	//for (int i = 0; i < a.size(); i++) {
	//	printf("%d ", a[i].first);
	//}
	//printf("\n");
//	for (int i = 0; i < a.size(); i++) {
		//int &x = a[i].first;
//		x = lower_bound(a.begin(), a.end(), x) - a.begin();
		//auto x = p.lower_bound(mystruct{ 2 }); //p가 map일때 사용가능
		/*참고-https://stackoverflow.com/questions/30496881/comparison-operator-to-be-used-in-stdlower-bound */	
//	}
	for (int i = 0; i < a.size(); i++) {
		int x = lower_bound(d.begin(), d.end(), a[i].first) - d.begin();
			printf("%d ", x + 1);
	}
	//for (int i = 0; i < d.size(); i++) {
	//	printf("%d ", f(d[i]) + 1);
	//}
//	printf("\n\nlower: %d %d\n", d[2], f(d[2]));
//	printf("\n>%d", f(83));
}
