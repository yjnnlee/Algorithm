//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
///*
//1. 인접한 두 칸을 고르고, 사탕을 교환한다
//사탕을 교환하는 시간 복잡도 - 모든 사탕에 대해 상하좌우 4가지 경우의 수가 있음
//즉, N^2(모든사탕) * 4 = O(N^2)
//하지만 실제로는 왼쪽 상단에서 시작하므로 계속 오른쪽,아래만 보면 전체 경우를 볼 수 있다
//즉, 2가지 경우의 수이다
//그래서 N^2 * 2가 되지만 동일하게 O(N^2) 이다 (코드 짤 때 간결하게 하기 위함)
//
//2. 같은 색으로 이루어져 있는 가장 긴 연속 부분 행 또는 열을 고른다
//어느 행 또는 열이 가장 긴 연속 부분인지 모르기 때문에 전체 사탕에 대해 시도해 보아야 한다
//즉, N^2 = O(N^2)
//
//총 O(N^4)짜리 문제임
//N<=50이므로, 50^4=2500^4=6250000 (가능)
//*/
//
//int chk(vector<string>& a) { //가장 긴 연속 부분 찾아서 반환
//	int n = a.size();
//	int res = 1; //무조건 1개부터 시작
//	for (int i = 0;i < n;i++) {
//		int cnt = 1; //현재 연속
//		for (int j = 1;j < n;j++) { //오른쪽
//			if (a[i][j] == a[i][j - 1]) { //이전 값과 같으면 연속이다
//				cnt += 1;
//			}
//			else cnt = 1; //같지 않으면 1부터 다시 시작이다
//			if (res < cnt) res = cnt; //최대값 갱신
//		}
//
//		cnt = 1;
//		for (int j = 1;j < n;j++) { //아래
//			if (a[j][j] == a[j- 1][i]) { //아래니까 인덱스 바꿔야 함!!
//				cnt += 1;
//			}
//			else cnt = 1;
//			if (res < cnt) res = cnt;
//		}
//	}
//	return res;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
//	int n;
//	cin >> n;
//	vector<string> a(n);
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//	}
//	int res = 0;
//	for (int i = 0;i < n;i++) {
//		for (int j = 0;j < n;j++) {
//			if (j + 1 < n) { //오른쪽 스왑
//				swap(a[i][j], a[i][j + 1]);
//				int tmp = chk(a);
//				if (res < tmp) res = tmp;
//				swap(a[i][j], a[i][j + 1]); //원래대로
//			}
//
//			if (i + 1 < n) { //아래 스왑
//				swap(a[i][j], a[i + 1][j]);
//				int tmp = chk(a);
//				if (res < tmp) res = tmp;
//				swap(a[i][j], a[i + 1][j]); //원래대로
//			}
//		}
//	}
//	cout << res;
//}
//아니 이거랑 아래 코드랑 다른 게 뭐냐???

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
1. 인접한 두 칸을 고르고, 사탕을 교환한다
사탕을 교환하는 시간 복잡도 - 모든 사탕에 대해 상하좌우 4가지 경우의 수가 있음
즉, N^2(모든사탕) * 4 = O(N^2)
하지만 실제로는 왼쪽 상단에서 시작하므로 계속 오른쪽,아래만 보면 전체 경우를 볼 수 있다
즉, 2가지 경우의 수이다
그래서 N^2 * 2가 되지만 동일하게 O(N^2) 이다 (코드 짤 때 간결하게 하기 위함)

2. 같은 색으로 이루어져 있는 가장 긴 연속 부분 행 또는 열을 고른다
어느 행 또는 열이 가장 긴 연속 부분인지 모르기 때문에 전체 사탕에 대해 시도해 보아야 한다
즉, N^2 = O(N^2)

총 O(N^4)짜리 문제임
N<=50이므로, 50^4=2500^4=6250000 (가능)
*/
int check(vector<string>& a) {//가장 긴 연속 부분 찾아서 반환
    int n = a.size();
    int ans = 1; //무조건 1개부터 시작
    for (int i = 0; i < n; i++) {
        int cnt = 1; //현재 연속
        for (int j = 1; j < n; j++) {
            if (a[i][j] == a[i][j - 1]) {
                cnt += 1;
            }
            else {
                cnt = 1;
            }
            if (ans < cnt) ans = cnt;
        }
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (a[j][i] == a[j - 1][i]) {
                cnt += 1;
            }
            else {
                cnt = 1;
            }
            if (ans < cnt) ans = cnt;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) {
                swap(a[i][j], a[i][j + 1]);
                int temp = check(a);
                if (ans < temp) ans = temp;
                swap(a[i][j], a[i][j + 1]);
            }
            if (i + 1 < n) {
                swap(a[i][j], a[i + 1][j]);
                int temp = check(a);
                if (ans < temp) ans = temp;
                swap(a[i][j], a[i + 1][j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
