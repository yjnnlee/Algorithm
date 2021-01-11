#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	int price = 0;
	price += a; //토핑 없는 가격
	int kal_all = 0;
	kal_all += c;

	int kal[101];
	for (int i = 0; i < n; i++) {
		cin >> kal[i];
	}
	sort(kal, kal + n, [](int a, int b) { //내림차순
		return a > b;
	});
	int res = (int)(kal_all / price);
	int now;
	for (int i = 0; i < n; i++) {
		//now = (int)((kal_all + kal[i]) / (price + b));
		price += b;
		kal_all += kal[i];
		now = (int)(kal_all / price);
//		cout << kal_all + kal[i] << " " << price << endl;
		if (res > now) {
			break;
		}
		else {
			res = now;
		}
	}
	//cout << kal_all << " ";
	cout << res;
}
